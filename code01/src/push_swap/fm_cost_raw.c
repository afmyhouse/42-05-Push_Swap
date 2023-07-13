/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:32:53 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:40:40 by antoda-s         ###   ########.fr       */
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
