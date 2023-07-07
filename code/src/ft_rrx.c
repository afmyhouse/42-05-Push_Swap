/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:04:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:33:12 by antoda-s         ###   ########.fr       */
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
	{
		h->ta = h->ta->p;
		write(1, "rra\n", 4);
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		h->tb = h->tb->p;
		write(1, "rrb\n", 4);
	}
	return (SUCCESS);
}
