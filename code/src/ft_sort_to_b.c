/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:58:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Find the best node to push to stack B
/// @param h	Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_to_b(t_stack *h)
{
	t_elem	*best;

	while (h->size_a > 3)
	{
		best = ft_cost_get(h, 'a');
		if (best->cost_a || best->cost_b)
			ft_move_best_to_top(h, best);
		ft_px(h, 'b');
	}
	return ;
}
