/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_cost_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:17:57 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 19:19:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		SET COST as SUM of individual cost movement of the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the node to SET COST
/// @return		SUCCESS or ERROR
int	cost_raw(t_stack *h, t_elem *node)
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

/// @brief 		SET COST as 'rr' movement of the node
/// @param node	Pointer to the node to SET COST
/// @return		SUCCESS or ERROR
int	cost_rr(t_elem *node)
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

/// @brief 		SET COST the best move as 'rrr' for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the node to SET COST
int	cost_rrr(t_stack *h, t_elem *node)
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

/// @brief 			Calculates the cost of push a node to the A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int	cost_to_pa(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!h || !node || !h->ta)
		return (ERROR);
	cur = h->ta;
	if (node->data > h->max_a || node->data < h->min_a)
		while (cur->p->data < cur->data && cost++ < h->size_a)
			cur = cur->n;
	else
	{
		while (cur->data != h->min_a && cost++ < h->size_a)
			cur = cur->n;
		while (++cost && cur->data < node->data && cur->n->data < node->data)
			cur = cur->n;
	}
	node->cost_a = cost % h->size_a;
	return (SUCCESS);
}

/// @brief 			Calculates the cost of push node to the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int	cost_to_pb(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!h || !node || !h->tb)
		return (ERROR);
	cur = h->tb;
	if (node->data > h->max_b || node->data < h->min_b)
		while (cur->data < cur->p->data && cost++ < h->size_b)
			cur = cur->n;
	else
	{
		while (cur->data != h->max_b && cost++ < h->size_b)
			cur = cur->n;
		while (++cost && cur->data > node->data && cur->n->data > node->data)
			cur = cur->n;
	}
	node->cost_b = cost % h->size_b;
	return (SUCCESS);
}
