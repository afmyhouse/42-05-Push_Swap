/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_stack_limits_updt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:22:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 11:59:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			UPDATE MIN and MAX values in the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to update
void	ft_stack_limits_updt(t_elem *node, int *max, int *min)
{
	t_elem	*tmp;

	tmp = node;
	*min = tmp->data;
	*max = tmp->data;
	while (tmp->n != node)
	{
		if (tmp->data < *min)
			*min = tmp->data;
		if (tmp->data > *max)
			*max = tmp->data;
		tmp = tmp->n;
	}
	if (tmp->data < *min)
		*min = tmp->data;
	if (tmp->data > *max)
		*max = tmp->data;
	return ;
}

/// @brief 			Check for new values of min and max after push
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack pushed
void	ft_stack_limits_chk(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if ((h->ta->data == h->min_b || h->ta->data == h->max_b) && h->size_b)
			ft_stack_limits_updt(h->tb, &h->max_b, &h->min_b);
		if (h->ta->data < h->min_a)
			h->min_a = h->ta->data;
		if (h->ta->data > h->max_a)
			h->max_a = h->ta->data;
	}
	else if (stack == 'b')
	{
		if ((h->tb->data == h->min_a || h->tb->data == h->max_a) && h->size_a)
			ft_stack_limits_updt(h->ta, &h->max_a, &h->min_a);
		if (h->size_b == 1 && stack == 'b')
		{
			h->min_b = h->tb->data;
			h->max_b = h->tb->data;
		}
		else if (h->size_b > 1 && h->tb->data < h->min_b)
			h->min_b = h->tb->data;
		else if (h->size_b > 1 && h->tb->data > h->max_b)
			h->max_b = h->tb->data;
	}
	return ;
}
