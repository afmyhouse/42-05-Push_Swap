/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:04:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 14:19:44 by antoda-s         ###   ########.fr       */
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
int	ft_rx(t_stack *h, char stack, int print)
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
