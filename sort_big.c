/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:17:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 16:18:20 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//no need for null check a, already checked before calling it.

static int	max_bits(t_node **a)
{
	int		bits;
	int		max;
	t_node *tmp;

	*tmp = *a;
	max = (*tmp)->value;
	while ((*tmp)->next)
	{
		if ((*tmp)->next->value > max)
			max = (*tmp)->next->value;
		*tmp = (*tmp)->next;
	}
	bits = 0;
    while (max > 0)
	{
        max /= 2;
        bits++;
    }
    return bits;
}

//below handles positive numbers fist
char	*sort_big(t_node **a, t_node **b)
{
	int	max;
	int	max_bits;
	int n;
	int	value;

	max_bits = max_bits(a);
	i = 0;
	while (i <= max_bits)
	{
		while (*a)
		{
			value = (*a)->value;
			if ((value >> i) & 1)
        		ft_p(a, b);
			else
        		ft_r(a);
		}
		(*a) = (*a)->next;
		i++;
	}
}