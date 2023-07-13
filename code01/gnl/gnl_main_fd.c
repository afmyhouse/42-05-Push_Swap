/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 00:34:17 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../lib/libft.h"
#include "../lib/gnl.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("*%s", line);
		if (line)
			ft_free_str(&line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}