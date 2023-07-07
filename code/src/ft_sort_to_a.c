/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_machine copy 2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:58:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Find the best node to push to stack A
/// @param h		Information regarding :
void	ft_sort_to_a(t_stack *h)
{
	t_elem	*best;

	while (h->size_b)
	{
		best = ft_cost_get(h, 'b');
		if (best->cost_a || best->cost_b)
			ft_move_best_to_top(h, best);
		ft_px(h, 'a');
	}
	return ;
}
