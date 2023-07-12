/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_dest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:38:20 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:32:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Initial setup to calculate the destination cost to place
///					a new node from stack source to stack destination
/// @param h		Pointer to the stack
int	ft_cost_dest(t_stack *h, char stack_src)
{
	t_elem	*cur;
	int		i;

	i = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a' && h->tb)
	{
		cur = h->ta;
		while (i++ < h->size_a)
		{
			ft_cost_to_pb(h, cur);
			cur = cur->n;
		}
	}
	else if (stack_src == 'b' && h->ta)
	{
		cur = h->tb;
		while (i++ < h->size_b)
		{
			ft_cost_to_pa(h, cur);
			cur = cur->n;
		}
	}
	return (SUCCESS);
}
