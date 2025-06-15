/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:37:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/14 13:43:40 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  -------------------------Steps---------------------------
- Dealing with input and change them into Stack Structure:
- Implement Basic Stack Operations: sa, sb, pa, pb, ra, etc.
- sort_by_size, method according to list size:
	-> 2
	-> 3
	-> 4-5
	-> more than 5
- sort_big, when it is mroe than 5
- main: input error check first, **argv change to **t_node, then call push_swap
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//# include <fcntl.h>
# include <limits.h>

# define FT_ATOI_ERROR LONG_MIN
# define MAX_DIV_10 214748364
# define MAX_MOD_10 7

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int		*arr;
	int		size;
}			t_stack;

//below are input dealing functions
long	ft_atoi(char *s);
t_stack	*get_nbr_stack(char **input);
t_node	**get_node(t_stack *stk);
void	free_node(t_node **start);
void	free_stack(t_stack *stk);

//operations
int		node_size(t_node **nd);
void	ft_s(t_node **a, char name);
void	ft_p(t_node **dst, t_node **src, char name_dst);
void	ft_r(t_node **a, char name);
void	ft_rr(t_node **a, char name);

//sorting, sort_big has its own .c file and 2 static helpers inside
void	push_swap_by_size(t_node **a);
void	sort_small(t_node **a);
void	sort_medium(t_node **a, t_node **b);
void	sort_big(t_node **a, t_node **b);

//main: includeing 3 static checker inside
int		is_sorted(t_node **a);
int		main(int argc, char **argv);

#endif

/*
for exit and malloc: <stdlib.h>
void	exit(int status);
for read: <fcntl.h>
ssize_t  read(int fd, void *buf, size_t count);
*/
