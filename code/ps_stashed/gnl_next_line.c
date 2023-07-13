/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/11 16:17:31 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"
//#include "gnl.h"

/// @brief 		Checks if there is a complete line (\n) in the raw string.
///				If no \n is not found it calls for a "new line" from file
///				If a complete line is found it copies it to the node->nl
/// @param node	Pointer to the node with fd, pointers "raw" and "nl" and "ret"
/// @return		1 if it finds a new line, 0 if it reaches the end of the file
int	gnl_next_line(t_fd_lst *node)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!ft_strchr(node->raw, '\n') && node->ret)
		gnl_new_reading(node);
	if (node->raw && *node->raw)
	{
		tmp = node->raw;
		while (node->raw[i] && node->raw[i] != '\n')
			i++;
		if (node->raw[i] == '\n')
		{
			i++;
			node->nl = ft_substr(node->raw, 0, i);
			node->raw = ft_substr(node->raw, i, ft_strlen(node->raw) - i);
			if (!*node->raw)
				ft_free_str(&node->raw);
			free(tmp);
			return (1);
		}
		node->nl = node->raw;
	}
	node->raw = NULL;
	return (node->ret = 0, 0);
}
