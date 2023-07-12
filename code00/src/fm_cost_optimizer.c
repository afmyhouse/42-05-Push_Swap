/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_optimizer copy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:32:53 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:41:46 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		COST the best move for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the node
/// @return		SUCCESS or ERROR
int	ft_cost_optimizer(t_stack *h, t_elem *node)
{
	int	raw_cost;
	int	rr_cost;
	int	rrr_cost;

	rr_cost = ft_max_int(node->cost_a, node->cost_b);
	rrr_cost = ft_max_int((h->size_a - node->cost_a) % \
	h->size_a, (h->size_b - node->cost_b) % h->size_b);
	raw_cost = ft_min_int(h->size_a - node->cost_a, node->cost_a) \
	+ ft_min_int(h->size_b - node->cost_b, node->cost_b);
	if (rr_cost < rrr_cost && rr_cost < raw_cost)
		return (ft_cost_rr(node));
	else if (rrr_cost < rr_cost && rrr_cost < raw_cost)
		return (ft_cost_rrr(h, node));
	else if (raw_cost <= rr_cost && raw_cost <= rrr_cost)
		return (ft_cost_raw(h, node));
	return (SUCCESS);
}
