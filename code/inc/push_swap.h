/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/30 12:54:10 by antoda-s         ###   ########.fr       */
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
///	DEBUG
/* ************************************************************************** */

# define VERSION "0.7"
# ifndef _DEBUG
#  define _DEBUG 1
# endif
# ifndef _TEST
#  define _TEST 1
# endif
# ifndef _SHOWLIST
#  define _SHOWLIST 1
# endif
# ifndef _PRINT
#  define _PRINT 1
#  define _NOPRINT 0
# endif
# ifndef _SHOWFUNCTION
#  define _SHOWFUNCTION 0
# endif

/* ************************************************************************** */
///	CONSTANTS
/* ************************************************************************** */
# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define SA 11
# define SB 21
# define SX 'S'
# define PA 12
# define PB 22
# define PX 'P'
# define RA 13
# define RB 23
# define RX 'F'
# define RRA 14
# define RRB 24
# define RRX 'R'
# define HALT 0
# define RANGE 2

/* ************************************************************************** */
///	COLORS
/* ************************************************************************** */

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;34m"
# define PPL "\033[0;35m"
# define WTH "\033[0m"

/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */

typedef struct s_elem
{
	int				data;
	int				cost_a;
	int				cost_b;
	char			move_a;
	char			move_b;
	struct s_elem	*n;
	struct s_elem	*p;
}					t_elem;

typedef struct s_stack
{
	struct s_elem	*ta;
	struct s_elem	*tb;
	int				size_a;
	int				size_b;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	int				moves;
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

/* ps_action_px.c *********************************************************** */
void	ft_px_src(t_elem **top_src);
void	ft_px_dst(t_elem **top_src, t_elem **top_dst);
void	ft_px_stack(t_elem **top_src, t_elem **top_dst);
int		ft_px(t_stack *p2s, char stack);

/* ps_action_rrx.c ********************************************************** */
int		ft_rra(t_stack *p2s);
int		ft_rrb(t_stack *p2s);
int		ft_rrr(t_stack *p2s);
int		ft_rrx(t_stack *p2s, char stack);

/* ps_action_rx.c *********************************************************** */
int		ft_ra(t_stack *p2s);
int		ft_rb(t_stack *p2s);
int		ft_rr(t_stack *p2s);
int		ft_rx(t_stack *p2s, char stack);

/* ps_action_sx.c *********************************************************** */
void	ft_sx_stack(t_elem **swap_top);
int		ft_sx(t_stack *p2s, char stack, int print);
int		ft_ss(t_stack *p2s);

/* ps_browse.c ************************************************************** */
void	ft_browse_stack(t_stack *p2s, char stack);
void	ft_browse_stacks(t_stack *p2s);

/* ps_debug.c *************************************************************** */
void	ft_sort_stack_test(t_stack *p2s);
void	ft_inital_stack_test(t_stack *p2s);
void	ft_sort_machine(t_stack *p2s, int size);
void	ft_sort_3t(t_stack *h);
void	ft_sort_3(t_stack *h, char stack);
void	ft_sort_3a(t_stack *h);
void	ft_sort_3b(t_stack *h);
void	ft_sort_5(t_stack *p2s);

/* ps_extras.c ************************************************************** */
void	ft_banner(int mydebug, int ac);

/* ps_stacker.c ************************************************************* */
t_elem	*ft_stack_add_first(t_stack *p2s, int data);
t_elem	*ft_stack_add_next(t_elem *stack, int data);
t_stack	*ft_generate_list(int ac, char **av);;

/* ps_costs.c *************************************************************** */
int		ft_cost_a(t_stack *h, t_elem *node);
int		ft_cost_b(t_stack *h, t_elem *node);
int		ft_cost_src(t_stack *h, char stack);
void	ft_cost_src_x(t_elem *cur, int range, char stack_src);
void	ft_cost_dst(t_stack *h, char stack);
void	ft_cost_dst_x(t_stack *h, t_elem *cur, int range, char stack_src);
t_elem	*ft_get_cost(t_stack *h, char stack);

/* ps_action.c ************************************************************** */
void	ft_best2top(t_stack *h, t_elem *best);
void	ft_insert2a(t_stack *h);
void	ft_insert2b(t_stack *h);
void	ft_action_x(t_stack *h, t_elem *best);
t_elem	*ft_get_location(t_elem *cur, int offset);
void	ft_updt_min_max(t_elem *node, int *max, int *min);
void	ft_check_min_max(t_stack *h, char stack);
#endif