/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firststep_dealinput.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/14 13:29:06 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

long	ft_atoi(char *s)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	if (!s || !*s)
		return (FT_ATOI_ERROR);
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (!(*s >= '0' && *s <= '9'))
		return (FT_ATOI_ERROR);
	while (*s && (*s >= '0' && *s <= '9'))
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	if (*s)
		return (FT_ATOI_ERROR);
	return (nbr * sign);
}

t_stack	*get_nbr_stack(char **input)
{
	int		i;
	int		count;
	int		*array;
	long	value;
	t_stack	*stk;

	count = 0;
	while (input[count])
		count++;
	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		value = ft_atoi(input[i]);
		if (value == FT_ATOI_ERROR || value > INT_MAX || value < INT_MIN)
			return (free(array), NULL);
		array[i] = (int)value;
		i++;
	}
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

	if (!stk)
		return (NULL);
	start = malloc(sizeof(t_node *));
	if (!start)
		return (NULL);
	*start = NULL;
	current = NULL;
	i = 0;
	while (i < stk->size)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return (free_node(start), free(start), NULL);
		new->value = stk->arr[i];
		new->next = NULL;
		if (!*start)
			*start = new;
		else
			current->next = new;
		current = new;
		i++;
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
