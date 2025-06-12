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

	i = 1;
	while (input[i])
	{
		j = 0;
		if {input[i][j] == '+' || input[i][j] == '-'}
			j++;
		while (input[i][j])
		{
			if {input[i][j] < '0' || input[i][j] > '9'}
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_dup(char **input);
{
	while (*input)
	{
		if ()
			return (0);
		input++;
	}
	return (1);
}

static int	check_max_min(char **input)
{
	long	value;

	while (*input)
	{
		value = ft_atoi(*input);
		if (value < INT_MIN || VALUE > INT_MAX)
			return (0);
		input++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stk;
	t_node	**nd;

	if (argc < 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!check_is_digit(argv) || !check_dup(argv) || !check_max_min(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stk = get_nbr_stack(argv);
	if (!stk)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	nd = get_node(stk);
	if (!nd)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap_by_size(nd);
	return (0);
}
