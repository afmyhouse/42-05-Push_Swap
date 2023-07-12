/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:38:20 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:32:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Calculates the cost of each element of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_cost_source(t_stack *h, char stack_src)
{
	t_elem	*cur;
	int		i;

	i = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a')
	{
		cur = h->ta;
		while (i < h->size_a)
		{
			cur->cost_a = i++;
			cur = cur->n;
		}
	}
	else if (stack_src == 'b')
	{
		cur = h->tb;
		while (i < h->size_b)
		{
			cur->cost_b = i++;
			cur = cur->n;
		}
	}
	return (SUCCESS);
}
