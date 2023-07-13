/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 16:42:22 by antoda-s         ###   ########.fr       */
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
			ft_move_to_top(h, best);
		ft_px(h, 'a', _PRINT);
	}
	return ;
}
