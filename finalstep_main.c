/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstep_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:48:42 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 16:40:03 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>  //this printf need to be removed later;

static int	check_input(char **input)
{
	int	i;
	int	j;

	i = 1;
	while (input[i])
	{
		j = 0;
		if (input[i][j] == '+' || input[i][j] == '-')
			j++;
		while (input[i][j])
		{
			if (input[i][j] < '0' || input[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);//input valid
}

int	main(int argc, char **argv)
{
	int		*nbrs;
	t_node	**nd;

	if (argc < 2 || check_input(argv) == 0)
	{
		write(1, "ERRORS", 6);
		return (0);
	}
	nbrs = get_nbr_arr(argv);
	if (!nbrs)
		return (1);
	nd = get_node(nbrs);
	while ((*nd)->next)
	{
		printf("%i\n", (*nd)->value);
		(*nd) = (*nd)->next;
	}
	//push_swap_by_size(nd);  I have seg fault at this step
	return (0);
}
