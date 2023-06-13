/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/13 01:41:17 by antoda-s         ###   ########.fr       */
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
# include "../lib/libft.h"

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
# define BLU "\033[0;34m"
# define WTH "\033[0m"
# define PPL "\033[0;35m"
# define _DEBUG 0
/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */

typedef struct s_elem
{
	struct s_elem	*n;
	int				data;
	struct s_elem	*p;
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
/* push_swap_a_rx.c ********************************************************* */
void	ft_ra_stack(t_stack *p2s);
void	ft_rb_stack(t_stack *p2s);
void	ft_rr_stack(t_stack *p2s);
/* push_swap_a_rrx.c ******************************************************** */
void	ft_rra_stack(t_stack *p2s);
void	ft_rrb_stack(t_stack *p2s);
void	ft_rrr_stack(t_stack *p2s);
/* push_swap_a_sx.c ********************************************************* */
void	ft_sx_stack(t_stack *p2s, char stack, int print);
void	ft_ss_stack(t_stack *p2s);
/* push_swap_a_px.c ********************************************************* */
void	ft_px_src(t_elem **top_src);
void	ft_px_dst(t_elem **top_src, t_elem **top_dst);
void	ft_px(t_elem **top_src, t_elem **top_dst);
void	ft_px_stack(t_stack *p2s, char stack);
/* push_swap_u_1.c ********************************************************** */
t_stack	*ft_generate_list(int ac, char **av);;
void	ft_browse_stack(t_stack *p2s, char stack);
void	ft_browse_stacks(t_stack *p2s);
/* push_swap_u_1.c ********************************************************** */
void	ft_sort_stack_test(t_stack *p2s);
void	ft_inital_stack_test(t_stack *p2s);
void	ft_sort_machine(t_stack *p2s, int size);

#endif