/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_rx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/17 17:57:14 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			FORWARD Rotates the A stack top element to the bottom
/// @param p2s		Pointer to the stack
void	ft_ra(t_stack *p2s)
{
	write(1, "ra\n", 3);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_ra%s(t_stack *p2s = (ta : %s%p%s))\n",YLW,WTH, PPL,p2s->ta,WTH);
	p2s->ta = p2s->ta->n;
	ft_browse_stacks(p2s);

}

/// @brief 			FORWARD Rotates the B stack top element to the bottom
/// @param p2s	Pointer to the stack
void	ft_rb(t_stack *p2s)
{
	write(1, "rb\n", 3);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rb%s(t_stack *p2s = (tb : %s%p%s))\n",YLW,WTH, PPL,p2s->tb,WTH);
	p2s->tb = p2s->tb->n;
	ft_browse_stacks(p2s);

}

/// @brief 			FORWARD Rotates top to bottom on both stack A and B
/// @param p2s		Pointer to the stacks
void	ft_rr(t_stack *p2s)
{
	write(1, "rr\n", 3);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rr%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n",YLW,WTH, PPL,p2s->ta,WTH,PPL, p2s->tb,WTH);
	p2s->ta = p2s->ta->n;
	p2s->tb = p2s->tb->n;
	ft_browse_stacks(p2s);

}
