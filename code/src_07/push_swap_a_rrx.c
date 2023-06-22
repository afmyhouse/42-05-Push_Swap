/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_rrx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/21 19:57:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			REVERSE Rotates the A stack bottom element to the top
/// @param p2s		Pointer to the stack
int	ft_rra(t_stack *p2s)
{
	write(1, "rra\n", 4);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rra%s(t_stack *p2s = (ta : %s%p%s))\n",YLW,WTH,PPL,p2s->ta,WTH);
	p2s->ta = p2s->ta->p;
	ft_browse_stacks(p2s);
	return (1);

}

/// @brief 			REVERSE Rotates the B stack bottom element to the top
/// @param p2s		Pointer to the stack
int	ft_rrb(t_stack *p2s)
{
	write(1, "rrb\n", 4);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rra%s(t_stack *p2s = (tb : %s%p%s))\n",YLW,WTH,PPL,p2s->tb,WTH);
	p2s->tb = p2s->tb->p;
	ft_browse_stacks(p2s);
	return (1);
}

/// @brief 			REVERSE Rotates bottom to top on both stack A and B
/// @param p2s		Pointer to the stacks
int	ft_rrr(t_stack *p2s)
{
	write(1, "rrr\n", 4);
	if (_SHOWFUNCTION)
		ft_printf("void %sft_rrr%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n",YLW,WTH, PPL,p2s->ta,WTH,PPL,p2s->tb,WTH);
	p2s->ta = p2s->ta->p;
	p2s->tb = p2s->tb->p;
	ft_browse_stacks(p2s);
	return (1);
}
