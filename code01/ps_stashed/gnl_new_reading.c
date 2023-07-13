/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_new_reading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/11 16:17:14 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"
//#include "gnl.h"

/// @brief 		Reads the file in slashes of BUFFER_SIZE until it finds a \n
///				or the EOF. It saves the reading at the pointer node->raw.
///				It frees the memory allocated to the reading buffer.
/// @param node	The node with "fd" file descriptor, pointer "raw" to hold
///				reading result and status of reading "ret"
/// @return		1 if it finds a new line, 0 if it reaches the end of the file
int	gnl_new_reading(t_fd_lst *node)
{
	char	*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	buff[0] = '\0';
	while (node->ret != 0 && !ft_strchr(buff, '\n'))
	{
		node->ret = read(node->fd, buff, BUFFER_SIZE);
		gnl_check_reading(node, buff);
	}
	ft_free_str(&buff);
	return (1);
}
