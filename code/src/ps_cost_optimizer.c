/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_optimizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:32:53 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/06 13:01:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		SET COST as 'rr' movement of the node
/// @param node	Pointer to the node to SET COST
/// @return		SUCCESS or ERROR
int	ft_cost_rr(t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else
		node->move_a = RX;
	if (!node->cost_b)
		node->move_b = HOLD;
	else
		node->move_b = RX;
	return (SUCCESS);
}

/// @brief 		SET COST as SUM of individual cost movement of the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the node to SET COST
/// @return		SUCCESS or ERROR
int	ft_cost_raw(t_stack *h, t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else if (node->cost_a > (h->size_a - node->cost_a))
	{
		node->move_a = RRX;
		node->cost_a = h->size_a - node->cost_a;
	}
	else
		node->move_a = RX;
	if (!node->cost_b)
		node->move_b = HOLD;
	else if (node->cost_b > (h->size_b - node->cost_b))
	{
		node->move_b = RRX;
		node->cost_b = h->size_b - node->cost_b;
	}
	else
		node->move_b = RX;
	return (SUCCESS);
}

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

/// @brief 		COST OPTIMIZER for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the element to be cost optimized
/// @return		SUCCESS or ERROR
int	ft_cost_best(t_stack *h, char stack_src)
{
	t_elem	*node;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a')
	{
		node = h->ta;
		size = h->size_a;
	}
	else if (stack_src)
	{
		node = h->tb;
		size = h->size_b;
	}
	while (i++ < size)
	{
		ft_cost_optimizer(h, node);
		node = node->n;
	}
	return (SUCCESS);
}
