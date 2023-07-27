/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_cost_analytics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:23:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 19:56:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Calculates the cost of each element of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	cost_source(t_stack *h, char stack_src)
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

/// @brief 		Initial setup to calculate the destination cost to place
///					a new node from stack source to stack destination
/// @param h		Pointer to the stack
int	cost_dest(t_stack *h, char stack_src)
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
			cost_to_pb(h, cur);
			cur = cur->n;
		}
	}
	else if (stack_src == 'b' && h->ta)
	{
		cur = h->tb;
		while (i++ < h->size_b)
		{
			cost_to_pa(h, cur);
			cur = cur->n;
		}
	}
	return (SUCCESS);
}

/// @brief 		COST OPTIMIZER for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the element to be cost optimized
/// @return		SUCCESS or ERROR
int	cost_eval(t_stack *h, char stack_src)
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
		cost_optimizer(h, node);
		node = node->n;
	}
	return (SUCCESS);
}

/// @brief		Selects the lowest cost, THE BEST node to push
/// @param cur		head of stack source to select the best node
/// @param size		size of the stack source
/// @param stack_src stack source
/// @return			pointer to the best node
t_elem	*cost_best(t_elem *cur, int size, char stack_src)
{
	t_elem	*best;
	int		i;
	int		best_cost;
	int		cur_cost;

	i = 0;
	best = cur;
	while (i++ < size)
	{
		best_cost = cost_min(best);
		cur_cost = cost_min(cur);
		if ((cur_cost < best_cost) || \
			(cur_cost == best_cost && (\
			(cur->data < best->data && stack_src == 'a') || \
			(cur->data > best->data && stack_src == 'b'))))
			best = cur;
		cur = cur->n;
	}
	return (best);
}

/// @brief 		Selects the lowest cost, best, node to insert in the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to the best node
t_elem	*cost_get(t_stack *h, char stack_src)
{
	if (stack_src == 'a' || stack_src == 'b')
	{
		cost_source(h, stack_src);
		cost_dest(h, stack_src);
		cost_eval(h, stack_src);
		if (stack_src == 'a')
			return (cost_best(h->ta, h->size_a, stack_src));
		else if (stack_src == 'b')
			return (cost_best(h->tb, h->size_b, stack_src));
	}
	return (NULL);
}
