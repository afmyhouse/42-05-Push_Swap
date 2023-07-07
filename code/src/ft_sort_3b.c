/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:40:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:55:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
				swap = ft_rx(h, 'b');
		}
		if ((h->tb->data > h->tb->n->data) && (h->tb->n->data < h->tb->p->data))
			swap = !ft_rrx(h, 'b');
	}
}
