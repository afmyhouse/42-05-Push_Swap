/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_check_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/11 16:14:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"
//#include "gnl.h"

/// @brief 			Checks if the last readingand add it to the raw string
/// @param node		node with reading information and raw string
/// @param buff		buffer with the last reading
void	gnl_check_reading(t_fd_lst *node, char *buff)
{
	char	*tmp;

	if (node->ret < 0)
	{
		ft_free_str(&buff);
		node->ret = 0;
	}
	else
	{
		buff[node->ret] = '\0';
		if (node->ret)
		{
			tmp = node->raw;
			node->raw = ft_strjoin(node->raw, buff);
			ft_free_str(&tmp);
		}
	}
	return ;
}
