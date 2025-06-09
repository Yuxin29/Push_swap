/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                			            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:58:28 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/04 21:59:20 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checking sorting status
int	is_sorted(t_node **head)
{
	while ((*head)->next->next)
	{
		if ((*head)->value > (*head)->next->value)
			return (0);
		(*head) = (*head)->next;
	}
	return (1);
}

// clean memory
void	free_stack(t_node *head)
{
	t_node	*tmp;

	tmp = NULL;
	while (head->next)
	{
		tmp = head;
		free (head);
		head = tmp->next;
	}
	return ;
}