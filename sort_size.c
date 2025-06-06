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

char	**sort_small(t_node **a);

//4–5 elements: push smallest elements to B, sort 3 in A, push back.
char	**sort_medium(t_node **a, t_node **b);

// in this function, we do the push&swap that we need to do and 
// record the oprations we did in an array of strs and we return this str;
// Receive stack A with all numbers. Stack B is empty.
char	**push_swap(t_node	**a, t_node **b)
{
	int	num;

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
