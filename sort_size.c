/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:09:47 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/04 20:57:51 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
in this sort, we do the push&swap and record and return the oprations
Receive stack A with all numbers. Stack B is empty.
*/

//3 elements: no need to stack B
void	sort_small(t_node *a)
{
	if (a->value > a->next->value)
		ft_s(a);
	if (a->next->value > a->next->next->value)
		ft_rr(a);
	if (a->value > a->next->value)
		ft_s(a);
	return ;
}

//4–5 elements: push smallest elements to B, sort 3 in A, push back.
void	sort_medium(t_node *a, t_node *b);

//according to the length of the linked list, we use different fts.
void	push_swap(int	*nbrs);
{
	int		num;
	t_node	*a;

	a = get_node(nbrs);
	if (!a || !*a || !(*a)->next)
		return (NULL);
	num = get_stack(a)->size;
	if (size == 2)
	{
		if (node->value > node->next->value)
			return (ft_s(a));
	}
	else if (size == 3)
		return (sort_small(a));
	else if (size <= 5 && size >= 4)
		return (sort_small(a));
	else if (size > 5)
		return (sort_small(a));
	return (NULL);
}
