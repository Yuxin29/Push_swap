/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:09:47 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/04 20:57:51 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
General structure of push_swap():
- Receive stack A with all numbers. Stack B is empty.

- Decide sorting method based on size:
2 or 3 elements: handle with simple logic.
4–5 elements: push smallest elements to B, sort 3 in A, push back.
>5 elements: radix sort or chunk-based logic.

Basic example logic (3 elements):

if (stack_size == 2)
    do sa if needed;
else if (stack_size == 3)
    use conditionals to sort with sa, ra, rra;
    
For large input:
- Use Radix Sort (binary sorting) or Chunking (divide input into small ranges).
- Use pb to move unsorted elements to stack B.
- Use pa to reinsert them correctly sorted.

*/

char **push_swap(int	*nbrs)
{
	// in this function, we do the push&swap that we need to do and record the oprations we did in an array of strs;
	// and we return this str;
}
