/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_by_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:09:47 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/12 18:35:38 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
in this sort, we do the push&swap and record and return the oprations
Receive stack A with all numbers. Stack B is empty.
*/

//3 elements: no need to stack B
void	sort_small(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		ft_s(a, 'a');
	if ((*a)->next->value > (*a)->next->next->value)
		ft_rr(a, 'a');
	if ((*a)->value > (*a)->next->value)
		ft_s(a, 'a');
}

//helper function for sort_medium
static int	find_smallest_index(t_node **nd)
{
	int		min;
	int		min_ind;
	int		ind;
	t_node	*tmp;

	min = (*nd)->value;
	min_ind = 1;
	ind = 1;
	tmp = *nd;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_ind = ind;
		}
		ind++;
		tmp = (tmp)->next;
	}
	return (min_ind);
}

//4–5 elements: push smallest elements to B, sort 3 in A, push back.
void	sort_medium(t_node **a, t_node **b)
{
	int	length;
	int	min_index;

	length = node_size(a);
	min_index = find_smallest_index(a);
	while (length > 3)
	{
		min_index = find_smallest_index(a);
		while (min_index > 0)
		{
			ft_r(a, 'a');
			min_index--;
		}
		ft_p(b, a, 'b');
		length--;
	}
	sort_small(a);
	ft_p(a, b, 'a');
	ft_p(a, b, 'a');
}

void	push_swap_by_size(t_node **a)
{
	int		size;
	t_node	**b;

	if (!a || !*a || !(*a)->next)
		return ;
	size = node_size(a);
	b = malloc(sizeof(t_node *));
	if (!b)
		return ;
	*b = NULL;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			(ft_s(a, 'a'));
		else
			return ;
	}
	else if (size == 3)
		sort_small(a);
	else if (size == 4 || size == 5)
		sort_medium(a, b);
	else
		sort_big(a, b);
}
