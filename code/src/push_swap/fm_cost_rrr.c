/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_optimizer copy 4.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:32:53 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:41:22 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		SET COST the best move as 'rrr' for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the node to SET COST
int	ft_cost_rrr(t_stack *h, t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else
	{
		node->move_a = RRX;
		node->cost_a = h->size_a - node->cost_a;
	}
	if (!node->cost_b)
		node->move_b = HOLD;
	else
	{
		node->move_b = RRX;
		node->cost_b = h->size_b - node->cost_b;
	}
	return (SUCCESS);
}
