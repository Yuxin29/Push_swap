/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firststep_dealinput.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/12 16:25:29 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
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
	while (input[count + 1])
		count++;
	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		array[i] = (int)ft_atoi(input[i + 1]);
		i++;
	}
	stk = malloc(sizeof(t_stack) * 1);
	if (!stk)
	{
		free (array);
		return (NULL);
	}
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
			return (free(start), NULL);
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

int	node_size(t_node **nd)
{
	int		size;
	t_node	*tmp;

	size = 0;
	if (!nd || !(*nd))
		return (0);
	tmp = *nd;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	free_stack(t_node **start)
{
	t_node	*tmp;

	while (*start)
	{
		tmp = *start;
		*start = (*start)->next;
		free (tmp);
	}
	free (start);
}
