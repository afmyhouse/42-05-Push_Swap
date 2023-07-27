/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:40:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 18:22:44 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SORTS the 3 elements of the any stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to sort
void	sort_3_x(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if (h->size_a == 3)
			sort_3_a(h);
		else if (h->size_a == 2)
		{
			if (h->ta->data > h->ta->n->data)
				action_sx(h, 'a', _PRINT);
		}
	}
	else if (stack == 'b')
	{
		if (h->size_b == 3)
			sort_3_b(h);
		else if (h->size_b == 2)
		{
			if (h->tb->data < h->tb->n->data)
				action_sx(h, 'b', _PRINT);
		}
	}
}

/// @brief			SORT ASCENDING the 3 nodes, A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	sort_3_a(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->ta->data > h->ta->n->data)
		{
			if (h->ta->data < h->ta->p->data)
				swap = !action_sx(h, 'a', _PRINT);
			if (h->ta->data > h->ta->p->data)
				swap = !action_rx(h, 'a', _PRINT);
		}
		if ((h->ta->data < h->ta->n->data) && (h->ta->n->data > h->ta->p->data))
			swap = !action_rrx(h, 'a', _PRINT);
	}
}

/// @brief			SORT DESCENDING the 3 nodes, B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	sort_3_b(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->tb->data < h->tb->n->data)
		{
			if (h->tb->data > h->tb->p->data)
				swap = action_sx(h, 'b', _PRINT);
			if (h->tb->data < h->tb->p->data)
				swap = action_rx(h, 'b', _PRINT);
		}
		if ((h->tb->data > h->tb->n->data) && (h->tb->n->data < h->tb->p->data))
			swap = !action_rrx(h, 'b', _PRINT);
	}
}
