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
	return (1);//input valid
}

//below are helper functions tested;
int	array_length(char **input);
int	*get_nbr_arr(char **input);
t_node	*get_node(char **input);
t_stack	*get_stack(t_node *nd);

int	main(int argc, char **argv)
{
	int		i;
	int		length;
	int		*nbrs;
	t_node	*nd;
	t_node	*tmp;
	int		judge;

	if (check_input(argv) == 0)
		return (write(1, "INPUT_ERRORS", 12));
	if (argc < 2)
		return (write(1, "ERRORS", 6));
	//testing length
	length = array_length(argv);
	printf("%s", "length = ");
	printf("%i\n", length);
	//testing get_nbr_arr
	i = 0;
	nbrs = get_nbr_arr(argv);
	if (!nbrs)
		return (1);//error signal
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
	//testing helpers;
	judge = is_sorted(nd);
	printf("%i\n", judge);
	return (0);
}
