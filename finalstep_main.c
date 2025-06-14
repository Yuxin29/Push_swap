/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstep_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:48:42 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/14 17:31:49 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	check_digit(char **input)
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

static int	check_mm(char **input)
{
	int		i;
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
	int		i;
	int		j;
	int		count;

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
			return (free(stk->arr), free(stk), 1);
		i++;
	}
	return (free(stk->arr), free(stk), 0);
}

int	is_sorted(t_node **nd)
{
	t_node	*tmp;

	if (!nd || !*nd)
		return (1);
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
		return (write(2, "Error\n", 6), 1);
	if (argv[1] && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	if (!check_digit(&argv[1]) || !check_mm(&argv[1]) || !check_dup(&argv[1]))
		return (write(2, "Error\n", 6), 1);
	stk = get_nbr_stack(&argv[1]);
	if (!stk)
		return (write(2, "Error\n", 6), 1);
	nd = get_node(stk);
	if (!nd)
	{
		free_stack(stk);
		return (write(2, "Error\n", 6), 1);
	}
	if (!is_sorted(nd))
		push_swap_by_size(nd);
	free_stack(stk);
	free_node(nd);
	free(nd);
	return (0);
}
