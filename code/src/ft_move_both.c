/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move copy 2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:28:49 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:50:21 by antoda-s         ###   ########.fr       */
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
			ft_rr(h);
		else if (best->move_a == 'R')
			ft_rrr(h);
		best->cost_a--;
		best->cost_b--;
	}
}
