/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:17:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/12 15:56:10 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*------------------the only new thing used here------------------
value >> i shifts the bits of value to the right by i places.
& 1 isolates the least significant bit after shifting.
*/

static int	max_bits(t_node **a)
{
	int		bits;
	int		max;
	t_node	*tmp;

	tmp = *a;
	if (!tmp)
		return (0);
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

static int	dealing_minus(t_node **a)
{
	int		off_set;
	int		min;
	t_node	*tmp;

	off_set = 0;
	tmp = *a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (min < 0)
		off_set = -min;
	return (off_set);
}

void	sort_big(t_node **a, t_node **b)
{
	int		max_bit;
	int		i;
	int		size;
	int		off_set;

	i = 0;
	max_bit = max_bits(a);
	off_set = dealing_minus(a);
	while (i < max_bit)
	{
		size = node_size(a);
		while (size)
		{
			if ((((*a)->value + off_set) >> i) & 1)
				ft_r(a, 'a');
			else
				ft_p(b, a, 'b');
			size--;
		}
		while (*b)
			ft_p(a, b, 'a');
		i++;
	}
}
