/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:52:19 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 00:18:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 100000000
// # endif

/* ************************************************************************** */
///	LIBS
/* ************************************************************************** */
# include "../lib/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

// /* *********************************************************************** */
// ///	STRUCTS
// /* *********************************************************************** */

// typedef struct s_fd_lst
// {
// 	int				fd;
// 	char			*raw;
// 	char			*nl;
// 	int				ret;
// 	struct s_fd_lst	*next;
// }				t_fd_lst;

// /* *********************************************************************** */
// ///	FUNCTIONS PROTOTYPES
// /* *********************************************************************** */

// //void		ft_free_str(char **str);
// //char		*ft_strchr(const char *s, int c);
// //size_t		ft_strlen(const char *s);
// //char		*ft_strjoin(char const *s1, char const *s2);
// //char		*ft_strsub(char const *s, unsigned int start, size_t len);
// t_fd_lst	*gnl_check_fd(int fd, t_fd_lst **list);
// void		gnl_check_reading(t_fd_lst *node, char *buff);
// int			gnl_new_reading(t_fd_lst *node);
// int			gnl_next_line(t_fd_lst *node);
// char		*get_next_line(int fd);

#endif
