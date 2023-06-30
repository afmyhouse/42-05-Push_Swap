/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_rrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 18:49:57 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			ROTATION REVERSE the A stack bottom element to the top
/// @param p2s		Pointer to the stack
int	ft_rra(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rra%s(t_stack *p2s = (ta : %s%p%s))\n"\
		, YLW, WTH, PPL, p2s->ta, WTH);
	if (p2s->ta_size)
	{
		write(1, "rra\n", 4);
		p2s->ta = p2s->ta->p;
	}
	return (1);

}

/// @brief 			ROTATION REVERSE the B stack bottom element to the top
/// @param p2s		Pointer to the stack
int	ft_rrb(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rra%s(t_stack *p2s = (tb : %s%p%s))\n"\
		, YLW, WTH, PPL, p2s->tb, WTH);
	if (p2s->tb_size)
	{
		write(1, "rrb\n", 4);
		p2s->tb = p2s->tb->p;
	}
	return (1);
}

/// @brief 			ROTATION REVERSE both stack A and B
/// @param p2s		Pointer to the stacks
int	ft_rrr(t_stack *p2s)
{
	if (p2s->ta_size || p2s->tb_size)
		write(1, "rrr\n", 4);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rrr%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n"\
		, YLW, WTH, PPL, p2s->ta, WTH, PPL, p2s->tb, WTH);
	if (p2s->ta_size)
		p2s->ta = p2s->ta->p;
	if (p2s->tb_size)
		p2s->tb = p2s->tb->p;
	return (1);
}
