/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:28:49 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 16:45:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			MOVE boths stack together
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best		Pointer to the best element
void	ft_move_both(t_stack *h, t_elem *best)
{
	while (best->cost_a && best->cost_b)
	{
		if (best->move_a == 'F')
			ft_rr(h, _PRINT);
		else if (best->move_a == 'R')
			ft_rrr(h, _PRINT);
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
void	ft_move_single(t_stack *h, t_elem *best)
{
	while (best->cost_a && best->move_a == 'F')
	{
		best->cost_a--;
		ft_rx(h, 'a', _PRINT);
	}
	while (best->cost_a && best->move_a == 'R')
	{
		best->cost_a--;
		ft_rrx(h, 'a', _PRINT);
	}
	while (best->cost_b && best->move_b == 'F')
	{
		best->cost_b--;
		ft_rx(h, 'b', _PRINT);
	}
	while (best->cost_b && best->move_b == 'R')
	{
		best->cost_b--;
		ft_rrx(h, 'b', _PRINT);
	}
	return ;
}

/// @brief 			PUT the 'best' node on top before push it
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best 	Pointer to the best element
void	ft_move_to_top(t_stack *h, t_elem *best)
{
	if (best->move_a == best->move_b)
		ft_move_both(h, best);
	if (best->cost_a || best->cost_b)
		ft_move_single(h, best);
	return ;
}
