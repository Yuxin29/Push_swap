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

/*------------------the only new thing used here------------------
value >> i shifts the bits of value to the right by i places.
& 1 isolates the least significant bit after shifting.
*/

//no need for null check a, already checked before calling it.
static int	max_bits(t_node **a)
{
	int		bits;
	int		max;
	t_node	*tmp;

	tmp = *a;
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

//below handles positive numbers fist
void	sort_big(t_node **a, t_node **b)
{
	int	max_bits;
	int i;
	int	j;
	int	size;
	int	value;

	max_bits = max_bits(a);
	i = 0;
	size = node_size(*a)
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			value = (*a)->value;
			if ((value >> i) & 1)
        		ft_r(a);
			else
				ft_p(a, b);
			j++;
		}
		while (*b)
			ft_p(b, a);
		i++;
	}
}