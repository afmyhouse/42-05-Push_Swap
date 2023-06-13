/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_rrx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/10 23:45:21 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			REVERSE Rotates the A stack bottom element to the top
/// @param p2s		Pointer to the stack
void	ft_rra_stack(t_stack *p2s)
{
	write(1, "rra\n", 4);
	p2s->ta = p2s->ta->p;
}

/// @brief 			REVERSE Rotates the B stack bottom element to the top
/// @param p2s		Pointer to the stack
void	ft_rrb_stack(t_stack *p2s)
{
	write(1, "rrb\n", 4);
	p2s->tb = p2s->tb->p;
}

/// @brief 			REVERSE Rotates bottom to top on both stack A and B
/// @param p2s		Pointer to the stacks
void	ft_rrr_stack(t_stack *p2s)
{
	write(1, "rrr\n", 4);
	p2s->ta = p2s->ta->p;
	p2s->tb = p2s->tb->p;
}
