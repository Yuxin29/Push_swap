/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/04 20:59:19 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(char *s)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
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

static int	array_length(char **input)
{
	int	i;
	
	i = 0;
	while(!input[i])
		i++;
	return (i);
}

static int	*get_nbr_arr(char **input)
{
	int	i;
	int	count;
	int	*array;

	i = 0;
	count = array_length(input);
	array = malloc(sizeof(int) * count);
	if (!array)
		return (0);
	while (i < count)
	{
		array[i] = ft_atoi(input[i])
		i++;
	}
	return (array);
}

t_node	*get_node(char **input)
{
	int	i;
	int	length;
	int	*arr;
	t_node *start;
	t_node	*current;
	t_node	*new;
	
	i = 0;
	length = array_length(input);
	arr = get_nbr_arr(input);
	if (!arr)
		return (NULL);
	start = NULL;
	current = NULL;
	while (i < length)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return (NULL);
		new->value = arr[i];
		new->next = NULL;
		if (!start)
		{
			start = new;
			current = new;
		}
		else
		{
			current->next = new;
			current = new;
		}
		i++;
	}
	return (start);
}

t_stack	*get_stack(t_node nd)
{
	t_stack	*stk;
	int		i;

	stk = malloc(sizeof(t_stack) * 1);
	if (!stk)
		return (NULL);
	stk->top = nd;
	i = 0;
	while (nd->next)
	{
		nd = nc->next;
		i++;
	}
	stk-size = i;
	return (stk);
}
