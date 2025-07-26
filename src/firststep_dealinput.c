/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firststep_dealinput.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/17 22:56:22 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s)
{
	int		sign;
	long	nbr;
	int		max_digit;

	sign = 1;
	nbr = 0;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	max_digit = 7;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
		max_digit = 8;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		if (nbr > MAX_D_10 || (nbr == MAX_D_10 && (*s - '0') > max_digit))
			return (FT_ATOI_ERROR);
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * sign);
}

t_stack	*get_nbr_stack(char **input)
{
	int		i;
	int		count;
	int		*array;
	t_stack	*stk;

	count = 0;
	while (input[count])
		count++;
	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	i = -1;
	while (++i < count)
		array[i] = (int)ft_atoi(input[i]);
	stk = malloc(sizeof(t_stack) * 1);
	if (!stk)
		return (free (array), NULL);
	stk->arr = array;
	stk->size = count;
	return (stk);
}

t_node	**get_node(t_stack *stk)
{
	t_node	**start;
	t_node	*current;
	t_node	*new;
	int		i;

	start = malloc(sizeof(t_node *));
	if (!start || !stk)
		return (NULL);
	*start = NULL;
	current = NULL;
	i = 0;
	while (i < stk->size)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return (free_node(start), free(start), NULL);
		new->value = stk->arr[i++];
		new->next = NULL;
		if (!*start)
			*start = new;
		else
			current->next = new;
		current = new;
	}
	return (start);
}

void	free_stack(t_stack *stk)
{
	if (!stk)
		return ;
	if (stk->arr)
		free(stk->arr);
	free(stk);
}

void	free_node(t_node **start)
{
	t_node	*tmp;

	if (!start)
		return ;
	while (*start)
	{
		tmp = (*start)->next;
		free(*start);
		*start = tmp;
	}
}
