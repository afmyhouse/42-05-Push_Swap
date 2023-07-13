/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:38:20 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:32:47 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		COST OPTIMIZER for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the element to be cost optimized
/// @return		SUCCESS or ERROR
int	ft_cost_eval(t_stack *h, char stack_src)
{
	t_elem	*node;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a')
	{
		node = h->ta;
		size = h->size_a;
	}
	else if (stack_src)
	{
		node = h->tb;
		size = h->size_b;
	}
	while (i++ < size)
	{
		ft_cost_optimizer(h, node);
		node = node->n;
	}
	return (SUCCESS);
}
