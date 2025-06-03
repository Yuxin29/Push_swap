/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:15 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/03 18:00:31 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * sign);
}

int	*get_nbr_arr(char **input)
{
	int	i;
	int	count;
	int	*array;

	i = 0;
	count = 0;
	while (input[count])
		count++;
	array = malloc(sizeof(int) * count);
	if (!array)
		return (0);
	while (i < count)
	{
		array[i] = ft_atoi(input[i])
		i++;
	}
	return (array);
}
