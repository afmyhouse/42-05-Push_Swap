/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:57:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			PUSH back all of nodes from B to A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_final(t_stack *h)
{
	t_elem	*cur;
	int		cost;
	int		mid;

	cost = 0;
	mid = h->size_a / 2 + h->size_a % 2;
	cur = h->ta;
	while (cur->data != h->min_a && ++cost)
		cur = cur->n;
	cost = cost % h->size_a;
	if (!cost)
		return ;
	else if (cost > (mid - h->size_a % 2))
	{
		while (h->ta->data != h->min_a)
			ft_rrx(h, 'a');
	}
	else
	{
		while (h->ta->data != h->min_a)
			ft_rx(h, 'a');
	}
	return ;
}
