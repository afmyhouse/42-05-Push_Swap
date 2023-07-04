/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_rrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:04:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/04 23:06:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			ROTATION REVERSE the stack bottom element to the top
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int	ft_rrx(t_stack *h, char stack)
{
	if ((stack != 'a' && stack != 'b') || (stack == 'a' && !h->ta) \
	|| (stack == 'b' && !h->tb))
		return (ERROR);
	if (stack == 'a' && h->size_a > 1)
		h->ta = h->ta->p;
	else if (stack == 'b' && h->size_b > 1)
		h->tb = h->tb->p;
	printf("rr%c\n", stack);
	return (SUCCESS);
}

/// @brief 			ROTATION REVERSE both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_rrr(t_stack *h)
{
	if (!h->ta && !h->tb)
		return (ERROR);
	if (h->size_a > 1)
		h->ta = h->ta->p;
	if (h->size_b > 1)
		h->tb = h->tb->p;
	printf("rrr\n");
	return (SUCCESS);
}

/// @brief 			ROTATION the stack top element to the bottom
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int	ft_rx(t_stack *h, char stack)
{
	if (stack == 'a' && h->size_a > 1)
	{
		printf("r%c\n", stack);
		h->ta = h->ta->n;
		return (SUCCESS);
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		printf("r%c\n", stack);
		h->tb = h->tb->n;
		return (SUCCESS);
	}
	else
		return (ERROR);
}

/// @brief 			ROTATION FORWARD top to bottom on both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_rr(t_stack *h)
{
	if (h->size_a > 1)
		h->ta = h->ta->n;
	if (h->size_b > 1)
		h->tb = h->tb->n;
	if (h->size_a > 1 || h->size_b > 1)
	{
		printf("rr\n");
		return (1);
	}
	return (0);
}
