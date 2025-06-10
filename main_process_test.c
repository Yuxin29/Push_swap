/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:38:12 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/06 17:43:05 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

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
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*nbrs;
	t_node	*nd;
	t_node	*tmp;

	if (check_input(argv) == 0)
		return (write(1, "INPUT_ERRORS", 12));
	if (argc < 2)
		return (write(1, "ERRORS", 6));
//testing get_nbr_arr
	i = 0;
	nbrs = get_nbr_arr(argv);
	if (!nbrs)
		return (1);
	while (i < length)
	{
		printf("%i\n", nbrs[i]);
		i++;
	}
//testing get_node;
	nd = get_node(argv);
	tmp = nd;
	while (tmp->next)
	{
		printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
