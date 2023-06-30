/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_sx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 20:15:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SWAP the top two elements of the stack
/// @param swap_top	Pointer to the stack
void	ft_sx_stack(t_elem **swap_top)
{
	if(_SHOWFUNCTION)
		ft_printf("void %sft_sx_stack%s(t_elem **swap_top = %s%p%s)\n"\
		, YLW, WTH, RED, (*swap_top), WTH);
	(*swap_top)->p->n = (*swap_top)->n;
	(*swap_top)->n->p = (*swap_top)->p;

	(*swap_top)->p = (*swap_top)->n;
	(*swap_top)->n = (*swap_top)->n->n;

	(*swap_top)->n->p->n = (*swap_top);
	(*swap_top)->n->p = (*swap_top);

	(*swap_top) = (*swap_top)->p;
	return ;
}

/// @brief 			SWAP the top two elements of the stack
/// @param p2s		Pointer to the stack
/// @param stack	stack to swap
int	ft_sx(t_stack *p2s, char stack, int print)
{
	t_stack	swap;

	if (_SHOWFUNCTION)
		ft_printf("void %sft_sx%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s)\
		, char stack : %s%c%s, int print = %i)\n", YLW, WTH, RED, p2s->ta, \
		WTH, RED, p2s->tb, WTH, RED, stack, WTH, print);

	swap = *p2s;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')) && _DEBUG)
		return (0);
	else
	{
		if (stack == 'a' && swap.ta != NULL)
			ft_sx_stack(&swap.ta);
		if (stack == 'b' && swap.tb != NULL)
			ft_sx_stack(&swap.tb);
		*p2s = swap;
		if (print)
			ft_printf("s%c\n", stack);
		return (1);
	}
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param p2s		Pointer to the stacks
int	ft_ss(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		ft_printf("void %sft_ss%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n"\
		, YLW, WTH, RED, p2s->ta, WTH, RED, p2s->tb, WTH);
	ft_sx(p2s, 'a', _NOPRINT);
	ft_sx(p2s, 'b', _NOPRINT);
	write(1, "ss\n", 3);
	return (1);
}
