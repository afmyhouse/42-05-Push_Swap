/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_rx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/10 23:45:15 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			FORWARD Rotates the A stack top element to the bottom
/// @param p2s		Pointer to the stack
void	ft_ra_stack(t_stack *p2s)
{
	write(1, "ra\n", 3);
	p2s->ta = p2s->ta->n;
}

/// @brief 			FORWARD Rotates the B stack top element to the bottom
/// @param p2s	Pointer to the stack
void	ft_rb_stack(t_stack *p2s)
{
	write(1, "rb\n", 3);
	p2s->tb = p2s->tb->n;
}

/// @brief 			FORWARD Rotates top to bottom on both stack A and B
/// @param p2s		Pointer to the stacks
void	ft_rr_stack(t_stack *p2s)
{
	write(1, "rr\n", 3);
	p2s->ta = p2s->ta->n;
	p2s->tb = p2s->tb->n;
}
