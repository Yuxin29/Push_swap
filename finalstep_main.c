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

static int	check_input(char **input)
{
	int	i;
	int	check;

	i = 1;
	while (input[i])
	{
		check = ft_atoi(input[i]);
		if (check > INT_MAX || check < INT_MIN || check == 0)
			return (0);
		i++;
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
	if (check_input(argv) == 0)
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
