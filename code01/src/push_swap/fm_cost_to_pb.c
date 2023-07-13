/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_raw copy 2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:40 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:42:48 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Calculates the cost of push node to the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int	ft_cost_to_pb(t_stack *h, t_elem *node)
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
