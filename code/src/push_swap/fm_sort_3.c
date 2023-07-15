/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:40:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/14 19:36:17 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SORTS the 3 elements of the any stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to sort
void	ft_sort_3(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if (h->size_a == 3)
			ft_sort_3a(h);
		else if (h->size_a == 2)
		{
			if (h->ta->data > h->ta->n->data)
				ft_sx(h, 'a', _PRINT);
		}
	}
	else if (stack == 'b')
	{
		if (h->size_b == 3)
			ft_sort_3b(h);
		else if (h->size_b == 2)
		{
			if (h->tb->data < h->tb->n->data)
				ft_sx(h, 'b', _PRINT);
		}
	}
}

/// @brief			SORT ASCENDING the 3 nodes, A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_3a(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->ta->data > h->ta->n->data)
		{
			if (h->ta->data < h->ta->p->data)
				swap = !ft_sx(h, 'a', _PRINT);
			if (h->ta->data > h->ta->p->data)
				swap = !ft_rx(h, 'a', _PRINT);
		}
		if ((h->ta->data < h->ta->n->data) && (h->ta->n->data > h->ta->p->data))
			swap = !ft_rrx(h, 'a', _PRINT);
	}
}

/// @brief			SORT DESCENDING the 3 nodes, B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_3b(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->tb->data < h->tb->n->data)
		{
			if (h->tb->data > h->tb->p->data)
				swap = ft_sx(h, 'b', _PRINT);
			if (h->tb->data < h->tb->p->data)
				swap = ft_rx(h, 'b', _PRINT);
		}
		if ((h->tb->data > h->tb->n->data) && (h->tb->n->data < h->tb->p->data))
			swap = !ft_rrx(h, 'b', _PRINT);
	}
}
