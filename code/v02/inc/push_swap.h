/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/10 00:03:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
///	LIBS
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

/* ************************************************************************** */
///	DEFINES
/* ************************************************************************** */

# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define WTH "\033[0m"
# define PPL "\033[0;35m"
# define _DEBUG 0
/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */

typedef struct s_elem
{
	struct s_elem	*na;
	struct s_elem	*pa;
	int				data;
	struct s_elem	*nb;
	struct s_elem	*pb;
}					t_elem;

typedef struct s_stack
{
	struct s_elem	*ta;
	struct s_elem	*tb;
}					t_stack;

typedef struct s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				*sorted;
	int				size;
}					t_data;

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */

t_stack	*ft_generate_list(char **argv, int ac);
void	ft_generate_stack(t_data *data, char **argv);
void	ft_generate_sorted(t_data *data);
void	ft_generate_data(t_data *data, char **argv);

#endif