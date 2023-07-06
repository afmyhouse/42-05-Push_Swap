/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/06 16:54:32 by antoda-s         ###   ########.fr       */
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
	struct s_elem	*tb;
	int				size_a;
	int				size_b;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	int				moves;
}					t_stack;

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */

/* ps_action_p.c ************************************************************ */
void	ft_px_src(t_elem **top_src);
void	ft_px_dst(t_elem **top_src, t_elem **top_dst);
void	ft_px_stack(t_elem **top_src, t_elem **top_dst);
int		ft_px(t_stack *p2s, char stack);

/* ps_action_r.c ************************************************************ */
int		ft_rrx(t_stack *p2s, char stack);
int		ft_rrr(t_stack *p2s);
int		ft_rx(t_stack *p2s, char stack);
int		ft_rr(t_stack *p2s);

/* ps_action_s.c ************************************************************ */
void	ft_sx_stack(t_elem **swap_top);
int		ft_sx(t_stack *p2s, char stack, int print);
int		ft_ss(t_stack *p2s);

/* ps_args_check.c*********************************************************** */
int		ft_args_check_norepeat(int len, char **array);
int		ft_args_check_void(int len, char **array);
int		ft_args_check_isnum(int len, char **array);
int		ft_args_check_limits(int len, char **array);
int		ft_args_check(int len, char **array);

/* ps_cost_base.c******************************************************** */
int		ft_cost_push_b(t_stack *h, t_elem *node);
int		ft_cost_push_a(t_stack *h, t_elem *node);
int		ft_cost_dst(t_stack *h, char stack_src);
int		ft_cost_src(t_stack *h, char stack_src);
int		ft_cost_min(t_elem *cur);

/* ps_cost_best.c******************************************************** */
t_elem	*ft_get_best2x(t_elem *cur, int size, char stack_src);
t_elem	*ft_get_cost(t_stack *h, char stack_src);

/* ps_cost_optimizer.c*************************************************** */
int		ft_cost_rr(t_elem *node);
int		ft_cost_raw(t_stack *h, t_elem *node);
int		ft_cost_rrr(t_stack *h, t_elem *node);
int		ft_cost_optimizer(t_stack *h, t_elem *node);
int		ft_cost_best(t_stack *h, char stack_src);

/* ps_extras_browse.c******************************************************** */
void	ft_browse_stack(t_stack *p2s, char stack);
void	ft_browse_stacks(t_stack *p2s);

/* ps_action.c*************************************************************** */
void	ft_move_both(t_stack *h, t_elem *best);
void	ft_move_best2top(t_stack *h, t_elem *best);

/* ps_sort_base.c************************************************************ */
void	ft_sort_3(t_stack *h, char stack);
void	ft_sort_3a(t_stack *h);
void	ft_sort_3b(t_stack *h);
void	ft_sort_short(t_stack *h);
void	ft_start_stack_b(t_stack *h);

/* ps_sort_machine.c********************************************************* */
int		ft_check_sort(t_stack *h);
void	ft_sort_final(t_stack *h);
void	ft_sort_2_b(t_stack *h);
void	ft_sort_2_a(t_stack *h);
void	ft_sort_machine(t_stack *h);

/* ps_stacker.c********************************************************* */
void	ft_init_stack_status(t_stack *h);
void	ft_check_min_max(t_stack *h, char stack);
void	ft_updt_min_max(t_elem *node, int *max, int *min);
t_elem	*ft_stack_add_first(t_stack *h, int data);
t_elem	*ft_stack_add_next(t_elem *stack, int data);
t_stack	*ft_generate_list(int size, char **array);
void	 ft_free_list(t_stack *h);

/* ps_utils.c *************************************************************** */
int		ft_error(void);
int		ft_max_int(int a, int b);
int		ft_min_int(int a, int b);
int		ft_array_len(char **array);

/* push_swap.c ************************************************************** */
char	*ft_args_build_n(int ac, char **av);
char	*ft_args_build_2(char **av);
char	**ft_args_build(int ac, char **av);
int		main(int ac, char **av);

// /* ps_extras_libft.c********************************************************* */
// size_t	ft_strlen(const char *s);
// int		ft_isdigit(int c);
// int		ft_issign(char c);
// int		ft_isspace(char c);
// int		ft_itoa_len(int n);
// char	*ft_itoa(int n);
// int		ft_atoi(const char *nptr);
// long	ft_atol(const char *nptr);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_split_count(const char *s, char c);
// char	*ft_split_slice(const char *s, char c);
// char	**ft_split(char const *s, char c);

#endif