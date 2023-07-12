/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 16:54:06 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"
//#include "gnl.h"

/// @brief 		Allocs & returns a string ending w/ a \n, read from a file fd
///				Each fd should be managed independently of the others
///				- when reading from stdin, the function will keep on reading
///				from the current position even after have read the \n
/// @param fd	File Descriptor
/// @return		The string read from the file descriptor
char	*get_next_line(int fd)
{
	static t_fd_lst	*list;
	t_fd_lst		*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = gnl_check_fd(fd, &list);
	if (node == NULL)
		return (NULL);
	gnl_next_line(node);
	line = node->nl;
	if ((node->ret == 0 || node->ret == -1) && (!node->nl || !*node->nl))
	{
		list = node->next;
		free(node);
	}
	return (line);
}
