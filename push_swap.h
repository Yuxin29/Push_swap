/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:37:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/10 20:21:10 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  -------------------------Steps---------------------------
- Dealing with input and change them into Stack Structure:
- Implement Basic Stack Operations: sa, sb, pa, pb, ra, etc.
- sorting start, method according to list size:
	-> 2
	-> 3
	-> 4-5
	-> more than 5
- main: input error check first, **argv change to **t_node, then call push_swap
-------------------------------------------------------
for exit and malloc: <stdlib.h>
void	exit(int status);
for read: <fcntl.h>
ssize_t  read(int fd, void *buf, size_t count);
------------------------------------
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

//self_defined data structure: linked list
typedef struct s_node
{
	int		value;
	struct s_node	*next;
}			t_node;

//below are input dealing functions
void	free_stack(t_node **head)
int	*get_nbr_arr(char **input);
t_node	*get_node(int *arr);

//operation helpers: not used yet
//int     is_sorted(t_node *head);

//operations
void	ft_s(t_node **a, char name);
void	ft_p(t_node **dst, t_node **src, char name_sr);
void	ft_r(t_node **a, char name);
void	ft_rr(t_node **a, char name);

//sorting 
void	push_swap(int *nbrs);
void	sort_small(t_node *a, t_node *b);
void	sort_medium(t_node *a, t_node	*b);
void	sort_big(t_node *a, t_node *b);

//main
int	main(int argc, char **argv);

#endif
