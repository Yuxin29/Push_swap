/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:17:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/15 19:44:41 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------the only new thing used here-------------------------------
value >> i shifts the bits of value to the right by i places.
& 1 isolates the least significant bit after shifting.
*/

#include "push_swap.h"

//find the biggest number in t_node a and cast it into binary
static int	max_bits(t_node **a)
{
	int		max;
	t_node	*tmp;
	int		bits;

	if (!a || !*a)
		return (0);
	max = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

//bubble sort the array
static void	sort_stk_array(t_stack *stk)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (stk->size) - 1)
	{
		j = i + 1;
		while (j < stk->size)
		{
			if (stk->arr[i] > stk->arr[j])
			{
				tmp = stk->arr[i];
				stk->arr[i] = stk->arr[j];
				stk->arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

//get the index of a certain number in the stk
static int	get_index(t_stack *stk, int value)
{
	int	i;

	i = 0;
	while (i < stk->size)
	{
		if (stk->arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

// presort each node's value by its index in the sorted array
static void	presort(t_node **a, t_stack *stk)
{
	t_node	*tmp;

	tmp = *a;
	if (!stk->arr)
		return ;
	sort_stk_array(stk);
	while (tmp)
	{
		tmp->value = get_index(stk, tmp->value);
		tmp = tmp->next;
	}
}

void	sort_big(t_node **a, t_node **b, t_stack *stk)
{
	int	max_bit;
	int	i;
	int	j;

	i = 0;
	presort(a, stk);
	max_bit = max_bits(a);
	while (i < max_bit)
	{
		j = 0;
		while (j < stk->size)
		{
			if (((*a)->value >> i) & 1)
				ft_r(a, 'a');
			else
				ft_p(b, a, 'b');
			j++;
		}
		while (*b)
			ft_p(a, b, 'a');
		i++;
	}
}
