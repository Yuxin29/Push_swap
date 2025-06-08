/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:56:31 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 15:31:30 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//print the operation (eg,"sa\n"), return and store it to print later in main().

//swaps: - sa / sb: swap the first two elements
void	ft_s(t_node **nd, char name)
{
	int	tmp;

	if (!nd || !*nd || !(*nd)->next)
		return ;
	tmp = (*nd)->value;
	(*nd)->value = (*nd)->next->value;
	(*nd)->next->value = tmp;
	write (1, "s", 1);
	write (1, &name, 1);
	write (1, "\n", 1);
}

//- pa / pb: push from one stack to the other
void	ft_p(t_node **dst, t_node **src, char name)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	write (1, "p", 1);
	write (1, &name, 1);
	write (1, "\n", 1);
}

//- ra / rb: rotate up (first to last)
void	ft_r(t_node **nd, char name)
{
	t_node	*tmp;
	t_node	*last;

	if (!nd || !*nd || !(*nd)->next)
		return ;
	tmp = *nd;
	*nd = (*nd)->next;
	tmp->next = NULL;
	last = *nd;
	while (last->next)
		last = last->next;
	last->next = tmp;
	write (1, "r", 1);
	write (1, &name, 1);
	write (1, "\n", 1);
}

//- rra / rrb: reverse rotate (last to first)
void	ft_rr(t_node **nd, char name)
{
	t_node	*tmp;
	t_node	*last;

	if (!nd || !*nd || !(*nd)->next)
		return ;
	tmp = NULL;
	last = *nd;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *nd;
	*nd = last;
	write (1, "rr", 2);
	write (1, &name, 1);
	write (1, "\n", 1);
}

//below are thing that dont need to be double defined
//- ss: sa + sb
//- rr: ra + rb
//- rrr: rra + rrb                                                        