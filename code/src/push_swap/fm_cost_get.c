/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:38:20 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:32:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Selects the lowest cost, best, node to insert in the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to the best node
t_elem	*ft_cost_get(t_stack *h, char stack_src)
{
	if (stack_src == 'a' || stack_src == 'b')
	{
		ft_cost_source(h, stack_src);
		ft_cost_dest(h, stack_src);
		ft_cost_eval(h, stack_src);
		if (stack_src == 'a')
			return (ft_cost_best(h->ta, h->size_a, stack_src));
		else if (stack_src == 'b')
			return (ft_cost_best(h->tb, h->size_b, stack_src));
	}
	return (NULL);
}
