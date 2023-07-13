/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_raw copy 3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:40 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:43:14 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Calculates the cost of push a node to the A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int	ft_cost_to_pa(t_stack *h, t_elem *node)
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
