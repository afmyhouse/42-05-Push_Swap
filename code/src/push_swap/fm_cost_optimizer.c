/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_cost_optimizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:32:53 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 19:28:50 by antoda-s         ###   ########.fr       */
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
int	cost_optimizer(t_stack *h, t_elem *node)
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
		return (cost_rr(node));
	else if (rrr_cost < rr_cost && rrr_cost < raw_cost)
		return (cost_rrr(h, node));
	else if (raw_cost <= rr_cost && raw_cost <= rrr_cost)
		return (cost_raw(h, node));
	return (SUCCESS);
}

/// @brief 			GET MAX COST of any node by offset to head
/// @param cur		head of the stack
/// @param offset	offset to head
/// @return			lowest cost
int	cost_min(t_elem *cur)
{
	int		max;

	if (cur->move_a == cur->move_b)
		max = ft_max_int(cur->cost_a, cur->cost_b);
	else
		max = cur->cost_a + cur->cost_b;
	return (max);
}

/// @brief 			Find the maximum value in an int pair
/// @param a		First int
/// @param b		Second int
/// @return	-		Minimum value
int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/// @brief 			Find the minimum value in an int pair
/// @param a		First int
/// @param b		Second int
/// @return			Minimum value
int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
