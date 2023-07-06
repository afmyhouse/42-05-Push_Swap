/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:40 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 22:03:38 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Calculates the cost of push node to the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int	ft_cost_push_b(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!h || !node || !h->tb)
		return (ERROR);
	cur = h->tb;
	if (node->data > h->max_b || node->data < h->min_b)
		while (cur->data < cur->p->data && cost++ < h->size_b)
			cur = cur->n;
	else
	{
		while (cur->data != h->max_b && cost++ < h->size_b)
			cur = cur->n;
		while (++cost && cur->data > node->data && cur->n->data > node->data)
			cur = cur->n;
	}
	node->cost_b = cost % h->size_b;
	return (SUCCESS);
}

/// @brief 			Calculates the cost of push a node to the A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int	ft_cost_push_a(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!h || !node || !h->ta)
		return (ERROR);
	cur = h->ta;
	if (node->data > h->max_a || node->data < h->min_a)
		while (cur->p->data < cur->data && cost++ < h->size_a)
			cur = cur->n;
	else
	{
		while (cur->data != h->min_a && cost++ < h->size_a)
			cur = cur->n;
		while (++cost && cur->data < node->data && cur->n->data < node->data)
			cur = cur->n;
	}
	node->cost_a = cost % h->size_a;
	return (SUCCESS);
}

/// @brief 			Initial setup to calculate the destination cost to place
///					a new node from stack source to stack destination
/// @param h		Pointer to the stack
int	ft_cost_dst(t_stack *h, char stack_src)
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
			ft_cost_push_b(h, cur);
			cur = cur->n;
		}
	}
	else if (stack_src == 'b' && h->ta)
	{
		cur = h->tb;
		while (i++ < h->size_b)
		{
			ft_cost_push_a(h, cur);
			cur = cur->n;
		}
	}
	return (SUCCESS);
}

/// @brief 			Calculates the cost of each element of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_cost_src(t_stack *h, char stack_src)
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

/// @brief 			GET MAX COST of any node by offset to head
/// @param cur		head of the stack
/// @param offset	offset to head
/// @return			lowest cost
int	ft_cost_min(t_elem *cur)
{
	int		max;

	if (cur->move_a == cur->move_b)
		max = ft_max_int(cur->cost_a, cur->cost_b);
	else
		max = cur->cost_a + cur->cost_b;
	return (max);
}
