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

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//self_defined data structure: linked list
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int	*arr;
	int 	size;
}		t_stack;

//below are input dealing functions
long	ft_atoi(char *s);
void	free_stack(t_node **start);
t_stack	*get_nbr_stack(char **input);
t_node	**get_node(t_stack *stk);
int	node_size(t_node **nd);

//operations
void	ft_s(t_node **a, char name);
void	ft_p(t_node **dst, t_node **src, char name_dst);
void	ft_r(t_node **a, char name);
void	ft_rr(t_node **a, char name);

//sorting 
void	push_swap_by_size(t_node **a);
void	sort_small(t_node **a);
void	sort_medium(t_node **a);
void	sort_big(t_node **a);

//main
int	main(int argc, char **argv);

#endif
