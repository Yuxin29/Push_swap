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

#ifndef PUSH_SWAP.H
#define PUSH_SWAP.H

#include <unistd.h>
#include <stdlib.h> //for exit and malloc
#include <fcntl.h> //for read

void	exit(int status);
ssize_t read(int fd, void *buf, size_t count);

#endif
