/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:22:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:23:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Add fisrt element to a circular list and update head pointer
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to first element of the stack, NULL if error malloc
t_elem	*ft_stack_add_first(t_stack *h, int data)
{
	t_elem	*node;

	node = malloc(sizeof(t_elem));
	if (!node)
		return (NULL);
	h->ta = node;
	node->p = h->ta;
	node->n = h->ta;
	node->cost_a = 0;
	node->cost_b = 0;
	node->data = data;
	node->move_a = HOLD;
	node->move_b = HOLD;
	h->min_a = data;
	h->max_a = data;
	h->min_b = 0;
	h->max_b = 0;
	return (node);
}
