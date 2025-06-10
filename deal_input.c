/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 16:07:54 by yuwu             ###   ########.fr       */
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

int	*get_nbr_arr(char **input)
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
		array[i] = ft_atoi(input[i + 1]);
		i++;
	}
	return (array);
}

t_node	*get_node(int *arr)
{
	t_node	*start;
	t_node	*current;
	t_node	*new;

	start = NULL;
	current = NULL;
	while (*arr)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return (NULL);
		new->value = *arr;
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
		arr++;
	}
	return (start);
}
