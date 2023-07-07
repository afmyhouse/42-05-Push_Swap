/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:43:43 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:05:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			PUSH the top element of A stack to B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to push to ('A' | 'B')
/// @return			1 if success, 0 if fail
int	ft_px(t_stack *h, char stack)
{
	t_stack	push;

	push = *h;
	if ((!push.ta && stack == 'b') || (!push.tb && stack == 'a'))
		return (ERROR);
	if (stack == 'a' && push.tb != NULL)
	{
		ft_px_stack(&push.tb, &push.ta);
		push.size_a++;
		push.size_b--;
		write(1, "pa\n", 3);
	}
	else if (stack == 'b' && push.ta != NULL)
	{
		ft_px_stack(&push.ta, &push.tb);
		push.size_a--;
		push.size_b++;
		write(1, "pb\n", 3);
	}
	*h = push;
	ft_stack_limits_chk(h, stack);
	return (SUCCESS);
}
