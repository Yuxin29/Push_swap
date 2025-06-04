/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:58:28 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/04 21:59:20 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *new_node(int value);

void push_top(t_stack *stack, int value);

int pop_top(t_stack *stack);

void append_bottom(t_stack *stack, int value); (useful for ra)

int is_sorted(t_stack *stack); (optional but handy)

void free_stack(t_stack *stack);


