/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firststep_dealinput.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 16:07:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//INT_MAX, INT_MIN not dealt with yet, I will probaly deal them in main
static int	ft_atoi(char *s)
{
	int	sign;
	int	nbr;

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

//in case if getting **t_node fails
void	free_stack(t_node **start)
{
	t_node	*tmp;

	while (*start)
	{
		tmp = *start;
		*start = (*start)->next;
		free (tmp);
	}
}

int	*get_nbr_arr(char **input)
{
	int	i;
	int	count;
	int	*array;

	count = 0;
	while (input[count + 1])
		count++;
	array = malloc(sizeof(int) * count);
	if (!array)
		return (0);
	i = 0;
	while (i < count)
	{
		array[i] = ft_atoi(input[i + 1]);
		i++;
	}
	return (array);
}

//potential issue here is when *arr == 0, need ints: index i and size
t_node	**get_node(int *arr)
{
	t_node	**start;
	t_node	*current;
	t_node	*new;

	if (!arr)
		return (NULL);
	start = malloc(sizeof(t_node *));
	if (!start)
		return (NULL);
	current = NULL;
	while (*arr)
	{
		new = malloc(sizeof(t_node) * 1);
		if (!new)
			return (free(start), NULL);
		new->value = *arr;
		new->next = NULL;
		if (!*start)
			*start = new;
		else
			current->next = new;
		current = new;
		arr++;
	}
	return (start);
}

int	node_size(t_node **nd)
{
	int	size;

	size = 0;
	if (!nd || !(*nd))
		return (0);
	while (*nd)
	{
		size++;
		*nd = (*nd)->next;
	}
	return (size);
}
