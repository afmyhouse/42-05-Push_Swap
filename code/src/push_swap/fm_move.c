/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:28:49 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 19:16:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			MOVE boths stack together
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best		Pointer to the best element
void	move_both(t_stack *h, t_elem *best)
{
	while (best->cost_a && best->cost_b)
	{
		if (best->move_a == 'F')
			action_rr(h, _PRINT);
		else if (best->move_a == 'R')
			action_rrr(h, _PRINT);
		best->cost_a--;
		best->cost_b--;
	}
}

/// @brief 			MOVE boths stack together
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best		Pointer to the best element
void	move_single(t_stack *h, t_elem *best)
{
	while (best->cost_a && best->move_a == 'F')
	{
		best->cost_a--;
		action_rx(h, 'a', _PRINT);
	}
	while (best->cost_a && best->move_a == 'R')
	{
		best->cost_a--;
		action_rrx(h, 'a', _PRINT);
	}
	while (best->cost_b && best->move_b == 'F')
	{
		best->cost_b--;
		action_rx(h, 'b', _PRINT);
	}
	while (best->cost_b && best->move_b == 'R')
	{
		best->cost_b--;
		action_rrx(h, 'b', _PRINT);
	}
	return ;
}

/// @brief 			PUT the 'best' node on top before push it
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best 	Pointer to the best element
void	move_to_top(t_stack *h, t_elem *best)
{
	if (best->move_a == best->move_b)
		move_both(h, best);
	if (best->cost_a || best->cost_b)
		move_single(h, best);
	return ;
}
