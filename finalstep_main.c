/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstep_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:48:42 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/17 22:24:16 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **nd)
{
	t_node	*tmp;

	if (!nd || !*nd || !(*nd)->next)
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

static int	check_digit(char **input)
{
	int	j;

	while (*input)
	{
		j = 0;
		if (!(*input)[j])
			return (0);
		while ((*input)[j] == ' ' || ((*input)[j] >= '\t'
				&& (*input)[j] <= '\r'))
			j++;
		if ((*input)[j] == '+' || (*input)[j] == '-')
			j++;
		if (!(*input)[j])
			return (0);
		while ((*input)[j])
		{
			if ((*input)[j] < '0' || (*input)[j] > '9')
				return (0);
			j++;
		}
		input++;
	}
	return (1);
}

static int	check_mm(char **input)
{
	long	v;

	if (check_digit(input))
	{
		while (*input)
		{
			v = ft_atoi(*input);
			if (v == FT_ATOI_ERROR || v > INT_MAX || v < INT_MIN)
				return (0);
			input++;
		}
		return (1);
	}
	return (0);
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
			return (free(stk->arr), free(stk), 0);
		i++;
	}
	return (free(stk->arr), free(stk), 1);
}

int	main(int ac, char **av)
{
	t_stack	*stk;
	t_node	**nd;

	if (ac < 2)
		return (0);
	if (!check_digit(&av[1]) || !check_mm(&av[1]) || !check_dup(&av[1]))
		return (write(2, "Error\n", 6), 1);
	stk = get_nbr_stack(&av[1]);
	if (!stk)
		return (write(2, "Error\n", 6), 1);
	nd = get_node(stk);
	if (!nd)
	{
		free_stack(stk);
		return (write(2, "Error\n", 6), 1);
	}
	if (!is_sorted(nd))
		push_swap_by_size(nd, stk);
	free_stack(stk);
	free_node(nd);
	free(nd);
	return (0);
}
