/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_action_rx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:40:03 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 19:49:28 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			ROTATION the stack top element to the bottom
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int	action_rx(t_stack *h, char stack, int print)
{
	if (stack == 'a' && h->size_a > 1)
	{
		h->ta = h->ta->n;
		if (print)
			write(1, "ra\n", 3);
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		h->tb = h->tb->n;
		if (print)
			write(1, "rb\n", 3);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

/// @brief 			ROTATION FORWARD top to bottom on both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	action_rr(t_stack *h, int print)
{
	if (h->size_a > 1)
		h->ta = h->ta->n;
	if (h->size_b > 1)
		h->tb = h->tb->n;
	if (h->size_a > 1 || h->size_b > 1)
	{
		if (print)
			write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

/// @brief 			ROTATION REVERSE both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	action_rrr(t_stack *h, int print)
{
	if (!h->ta && !h->tb)
		return (ERROR);
	if (h->size_a > 1)
		h->ta = h->ta->p;
	if (h->size_b > 1)
		h->tb = h->tb->p;
	if (print)
		write(1, "rrr\n", 4);
	return (SUCCESS);
}

/// @brief 			ROTATION REVERSE the stack bottom element to the top
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int	action_rrx(t_stack *h, char stack, int print)
{
	if ((stack != 'a' && stack != 'b') || (stack == 'a' && !h->ta) \
	|| (stack == 'b' && !h->tb))
		return (ERROR);
	if (stack == 'a' && h->size_a > 1)
	{
		h->ta = h->ta->p;
		if (print)
			write(1, "rra\n", 4);
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		h->tb = h->tb->p;
		if (print)
			write(1, "rrb\n", 4);
	}
	return (SUCCESS);
}
