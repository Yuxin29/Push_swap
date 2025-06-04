/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:37:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/03 16:48:31 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h> //for exit and malloc
#include <fcntl.h> //for read

//below are linked list used
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
	t_node *top;
	int size;
} t_stack;

//below are initiating and read fcs, I dont know where to use them yet
void	exit(int status);
ssize_t	read(int fd, void *buf, size_t count);

//below are input dealing functions
int *get_nbr_arr(char **input);
t_node  *get_node(int *arr);
t_stack *get_stack(t_node nd);

//operation helpers

//operations

//sorting 

//main

#endif


/*
My Steps:
- Dealing with input and change them into Stack Structure:

- Implement Basic Stack Ops:
helpers: some helpers
The actual operatison: sa, sb, pa, pb, ra, etc. — these are the building blocks of push_swap.

- Then Implement push_swap():
I DONT KNOW ABOUT HOW TO SORT YET
Start with simple cases (e.g., 2 or 3 numbers).
Scale up gradually (use radix sort for big input sets if allowed).

-main
I do my input check in main, change my input to stacks and call push swap in main
*/