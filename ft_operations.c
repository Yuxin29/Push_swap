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

/*
Mandatory operations:
- sa / sb: swap the first two elements
- ss: sa + sb
- pa / pb: push from one stack to the other
- ra / rb: rotate up (first to last)
- rr: ra + rb
- rra / rrb: reverse rotate (last to first)
- rrr: rra + rrb
*/

//print the operation (eg,"sa\n") and return the operation as a string and store it to print later in main().

void ft_s(t_node *a)
{
    int     tmp;
    int     n1;
    int     n2;
	if (!a || !*a || !(*a)->next)
        return ;

    n1 = a->value;
    n2 = a->next->value;
    a->value = n2;
    a->next->value = n1;
   	write (1, "s", 1);
    write (1, a, 1);
    write (1, "\n", 1);
	return ;
}

void ft_ss(t_node a, t_node b)
{
	if (!a || !*a || !(*a)->next)
        return ;
	else if
		ft_swap(a);
	if (!b || !*b || !(*b)->next)
        return ;
	else if
		ft_swap(b);
    return ;
}

void ft_p(t_node a, t_node b)
{
    t_node  tmp;

	if (!b || !*b || !(*b)->next)
        return ;
    tmp = b;
    b->next = a;
    b = b-next;
	write (1, "ra\n", 1);
    write (1, a, 1);
    write (1, "\n", 1);
	return ;
}

void ft_r(t_noda **a)
{
    t_node	*tmp;
    t_node  *last;

	if (!a || !*a || !(*a)->next)
		return ;
    tmp = *a;
	tmp->next = NULL;
	*a = (*a)->next;
	last = *a;
    while (!last->next)
        last =last->next;
    last->next = tmp;
	write (1, "ra\n", 1);
	write (1, a, 1);
	write (1, "\n", 1);
    return ;
}

void ft_rr(t_noda **a)
{
    t_node  *tmp;
    t_node  *last;

    if (!a || !*a || !(*a)->next)
        return ;
    tmp = *a;
    tmp->next = NULL;
    *a = (*a)->next;
    last = *a;
    while (!last->next)
        last =last->next;
    last->next = tmp;
    write (1, "ra\n", 1);
    return ;
}                                                             
