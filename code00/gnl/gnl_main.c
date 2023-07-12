/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 04:12:07 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 16:54:06 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"
//#include "gnl.h"

int	main(void)
{
	char	*line;
	int		fd;
	//int		i;

	fd = open("test.txt", O_RDONLY);
	//i = 0;
	//while (i < 10)
	line = get_next_line(fd);
	while (line)
	{
		//line = gnl(fd);
		//line = gnl(0);
		printf("*%s", line);
		if (line)
			ft_free_str(&line);
		line = get_next_line(fd);
		//i++;
	}
	close(fd);
	return (0);
}