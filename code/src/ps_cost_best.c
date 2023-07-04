/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:38:20 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 00:06:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Selects the lowest cost, THE BEST node to push
/// @param cur		head of stack source to select the best node
/// @param size		size of the stack source
/// @param stack_src stack source
/// @return			pointer to the best node
t_elem	*ft_get_best2x(t_elem *cur, int size, char stack_src)
{
	t_elem	*best;
	int		i;
	int		best_cost;
	int		cur_cost;

	i = 0;
	best = cur;
	while (i++ < size)
	{
		best_cost = ft_min_cost(best);
		cur_cost = ft_min_cost(cur);
		if ((cur_cost < best_cost) ||\
			(cur_cost == best_cost && (\
			(cur->data < best->data && stack_src == 'a') ||\
			(cur->data > best->data && stack_src == 'b'))))
			best = cur;
		cur = cur->n;
	}
	return (best);
}

/// @brief 			Selects the lowest cost, best, node to insert in the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to the best node
t_elem	*ft_get_cost(t_stack *h, char stack_src)
{
	if (stack_src == 'a' || stack_src == 'b')
	{
		ft_cost_src(h, stack_src);
		ft_cost_dst(h, stack_src);
		ft_cost_optimizer(h, stack_src);
		if (stack_src == 'a')
			return (ft_get_best2x(h->ta, h->size_a, stack_src));
		else if (stack_src == 'b')
			return (ft_get_best2x(h->tb, h->size_b, stack_src));
	}
	return (NULL);
}