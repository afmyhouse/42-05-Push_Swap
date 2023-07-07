/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:51:13 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:38:02 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SWAP the top two elements of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to swap
int	ft_sx(t_stack *h, char stack, int print)
{
	t_stack	swap;

	swap = *h;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')))
		return (ERROR);
	else
	{
		if (stack == 'a' && swap.ta != NULL && swap.size_a > 1)
		{
			ft_sx_stack(&swap.ta);
			if (print)
				write(1, "sa\n", 3);
		}
		if (stack == 'b' && swap.tb != NULL && swap.size_b > 1)
		{
			ft_sx_stack(&swap.tb);
			if (print)
				write(1, "sb\n", 3);
		}
		*h = swap;
		return (SUCCESS);
	}
}
