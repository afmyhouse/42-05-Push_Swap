/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:38:20 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:32:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief		Selects the lowest cost, THE BEST node to push
/// @param cur		head of stack source to select the best node
/// @param size		size of the stack source
/// @param stack_src stack source
/// @return			pointer to the best node
t_elem	*ft_cost_best(t_elem *cur, int size, char stack_src)
{
	t_elem	*best;
	int		i;
	int		best_cost;
	int		cur_cost;

	i = 0;
	best = cur;
	while (i++ < size)
	{
		best_cost = ft_cost_min(best);
		cur_cost = ft_cost_min(cur);
		if ((cur_cost < best_cost) || \
			(cur_cost == best_cost && (\
			(cur->data < best->data && stack_src == 'a') || \
			(cur->data > best->data && stack_src == 'b'))))
			best = cur;
		cur = cur->n;
	}
	return (best);
}
