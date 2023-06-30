/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_rx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 18:48:56 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			ROTATION FORWARD the A stack top element to the bottom
/// @param p2s		Pointer to the stack
int	ft_ra(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		ft_printf("void %sft_ra%s(t_stack *p2s = (ta : %s%p%s))\n"\
		, YLW, WTH, PPL, p2s->ta, WTH);
	if (p2s->ta_size)
	{
		write(1, "ra\n", 3);
		p2s->ta = p2s->ta->n;
		return (1);
	}
	return (0);
}

/// @brief 			ROTATION FORWARD the B stack top element to the bottom
/// @param p2s	Pointer to the stack
int	ft_rb(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rb%s(t_stack *p2s = (tb : %s%p%s))\n"\
		, YLW, WTH, PPL, p2s->tb, WTH);
	if (p2s->tb_size)
	{
		write(1, "rb\n", 3);
		p2s->tb = p2s->tb->n;
		return (1);
	}
	return (0);

}

/// @brief 			ROTATION FORWARD top to bottom on both stack A and B
/// @param p2s		Pointer to the stacks
int	ft_rr(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rr%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n"\
		, YLW, WTH, PPL, p2s->ta, WTH, PPL, p2s->tb, WTH);
	if (p2s->ta_size)
		p2s->ta = p2s->ta->n;
	if (p2s->tb_size)
		p2s->tb = p2s->tb->n;
	if (p2s->ta_size || p2s->tb_size)
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}
