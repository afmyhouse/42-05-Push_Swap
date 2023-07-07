/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:28:49 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:50:49 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			PUT the 'best' node on top before push it
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best 	Pointer to the best element
void	ft_move_best_to_top(t_stack *h, t_elem *best)
{
	if (best->move_a == best->move_b)
		ft_move_both(h, best);
	while (best->cost_a && best->move_a == 'F')
	{
		best->cost_a--;
		ft_rx(h, 'a');
	}
	while (best->cost_a && best->move_a == 'R')
	{
		best->cost_a--;
		ft_rrx(h, 'a');
	}
	while (best->cost_b && best->move_b == 'F')
	{
		best->cost_b--;
		ft_rx(h, 'b');
	}
	while (best->cost_b && best->move_b == 'R')
	{
		best->cost_b--;
		ft_rrx(h, 'b');
	}
	return ;
}
