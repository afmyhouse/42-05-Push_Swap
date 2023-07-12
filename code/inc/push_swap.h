/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 00:23:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
///	LIBS
/* ************************************************************************** */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft.h"
# include "../inc/gnl.h"

/* ************************************************************************** */
///	DEBUG
/* ************************************************************************** */
# ifndef _PRINT
#  define _PRINT 1
#  define _NOPRINT 0
# endif
# ifndef _SHOW_STACKS_
#  define _SHOW_STACKS_ 1
# endif
# ifndef _SHORT_SIZE_
#  define _SHORT_SIZE_ 5
# endif

/* ************************************************************************** */
///	CONSTANTS
/* ************************************************************************** */
# ifndef ERROR
#  define ERROR 1
# endif
# ifndef SUCCESS
#  define SUCCESS 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# define SX 'S'
# define PX 'P'
# define RX 'F'
# define RRX 'R'
# define HOLD 0
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
	int				size_a;
	int				min_a;
	int				max_a;
	struct s_elem	*tb;
	int				size_b;
	int				min_b;
	int				max_b;
	int				moves;
}					t_stack;

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */

char	**ft_args_build(int ac, char **av);
int		ft_args_check_isvalid(int len, char **array);
int		ft_args_check_isint(int len, char **array);
int		ft_args_check_norepeat(int len, char **array);
int		ft_args_check_novoid(int len, char **array);
int		ft_args_check(int len, char **array);
int		ft_array_len(char **array);
void	ft_browse_stack(t_stack *h, char stack);
void	ft_browse_stacks(t_stack *h);
t_elem	*ft_cost_best(t_elem *cur, int size, char stack_src);
int		ft_cost_dest(t_stack *h, char stack_src);
int		ft_cost_eval(t_stack *h, char stack_src);
t_elem	*ft_cost_get(t_stack *h, char stack_src);
int		ft_cost_min(t_elem *cur);
int		ft_cost_optimizer(t_stack *h, t_elem *node);
int		ft_cost_raw(t_stack *h, t_elem *node);
int		ft_cost_rr(t_elem *node);
int		ft_cost_rrr(t_stack *h, t_elem *node);
int		ft_cost_source(t_stack *h, char stack_src);
int		ft_cost_to_pa(t_stack *h, t_elem *node);
int		ft_cost_to_pb(t_stack *h, t_elem *node);
int		ft_error(void);
int		ft_max_int(int a, int b);
int		ft_min_int(int a, int b);
void	ft_move_to_top(t_stack *h, t_elem *best);
void	ft_move_both(t_stack *h, t_elem *best);
void	ft_px_dst(t_elem **top_src, t_elem **top_dst);
void	ft_px_source(t_elem **top_src);
void	ft_px_stack(t_elem **top_src, t_elem **top_dst);
int		ft_px(t_stack *h, char stack, int print);
int		ft_rr(t_stack *h, int print);
int		ft_rrr(t_stack *h, int print);
int		ft_rrx(t_stack *h, char stack, int print);
int		ft_rx(t_stack *h, char stack, int print);
void	ft_sort_3(t_stack *h, char stack);
void	ft_sort_3a(t_stack *h);
void	ft_sort_3b(t_stack *h);
int		ft_sort_check(t_stack *h);
void	ft_sort_final(t_stack *h);
void	sort_machine(t_stack *h);
void	ft_sort_to_a(t_stack *h);
void	ft_sort_to_b(t_stack *h);
int		ft_ss(t_stack *h, int print);
int		ft_sx(t_stack *h, char stack, int print);
void	ft_sx_stack(t_elem **swap_top);
t_elem	*ft_stack_add_first(t_stack *h, int data);
t_elem	*ft_stack_add_next(t_elem *stack, int data);
void	ft_stack_b_start(t_stack *h);
void	ft_stack_free(t_stack *h);
void	ft_stack_init_status(t_stack *h);
t_stack	*ft_stack_init(int size, char **array);
void	ft_stack_limits_chk(t_stack *h, char stack);
void	ft_stack_limits_updt(t_elem *node, int *max, int *min);

///int		main(int ac, char **av);

/* ************************************************************************** */
///	CHECKER SPECIFIC FUNCTIONS
/* ************************************************************************** */
int		check_mover(t_stack *h, char *m);
int		check_machine(t_stack *h);
#endif