/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstep_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:48:42 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 16:40:03 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

static int	check_is_digit(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (input[i][j] == '+' || input[i][j] == '-')
		{
			j++;
			if (!input[i][j])
				return (0);
		}
		if (input[i][j] == '0' && input[i][j + 1] != '\0')
			return (0);
		while (input[i][j])
		{
			if (input[i][j] < '0' || input[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_max_min(char **input)
{
	int	i;
	long	value;

	i = 0;
	while (input[i])
	{
		value = ft_atoi(input[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	check_dup(char **input)
{
	t_stack	*stk;
	int	i;
	int	j;
	int	count;
	
	stk = get_nbr_stack(input);
	if (!stk)
		return (0);
	i = 0;
	while (i < stk->size)
	{
		j = 0;
		count = 0;
		while (j < stk->size)
		{
			if ((stk->arr)[i] == (stk->arr)[j])
				count++;
			j++;
		}
		if (count > 1)
			return (free(stk), 0);
		i++;
	}
	return (free(stk), 1);
}

static int	is_sorted(t_node **nd)
{
	t_node	*tmp;

	tmp = *nd;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stk;
	t_node	**nd;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argv[1] && !argv[1][0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (!check_is_digit(&argv[1]) || !check_max_min(&argv[1]) || !check_dup(&argv[1]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stk = get_nbr_stack(&argv[1]);
	if (!stk)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	nd = get_node(stk);
	if (!nd)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(nd) == 0)
		push_swap_by_size(nd);
	return (free(stk), free_stack(nd), 0);
}
