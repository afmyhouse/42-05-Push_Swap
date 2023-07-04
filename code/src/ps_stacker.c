/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:22:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 00:13:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Initialize the information about the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_init_stack_status(t_stack *h)
{
	h->ta = NULL;
	h->size_a = 0;
	h->min_a = 0;
	h->max_a = 0;
	h->tb = NULL;
	h->size_b = 0;
	h->min_b = 0;
	h->max_b = 0;
	h->moves = 0;
	return ;
}

/// @brief 			Check for new values of min and max after push
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack pushed
void	ft_check_min_max(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if ((h->ta->data == h->min_b || h->ta->data == h->max_b) && h->size_b)
			ft_updt_min_max(h->tb, &h->max_b, &h->min_b);
		if (h->ta->data < h->min_a)
			h->min_a = h->ta->data;
		if (h->ta->data > h->max_a)
			h->max_a = h->ta->data;
	}
	else if (stack == 'b')
	{
		if ((h->tb->data == h->min_a || h->tb->data == h->max_a) && h->size_a)
			ft_updt_min_max(h->ta, &h->max_a, &h->min_a);
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

/// @brief 			UPDATE MIN and MAX values in the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to update
void	ft_updt_min_max(t_elem *node, int *max, int *min)
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

/// @brief 			Add fisrt element to a circular list and update head pointer
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to first element of the stack, NULL if error malloc
t_elem	*ft_stack_add_first(t_stack *h, int data)
{
	t_elem	*stack;

	stack = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	h->ta = stack;
	stack->p = h->ta;
	stack->n = h->ta;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->data = data;
	stack->move_a = HOLD;
	stack->move_b = HOLD;
	h->min_a = data;
	h->max_a = data;
	h->min_b = 0;
	h->max_b = 0;
	return (stack);
}

/// @brief 			Adds a new element to the circular stack
/// @param stack	Pointer to the stack last added element
/// @return			Pointer to the stack current element, NULL if error malloc
t_elem	*ft_stack_add_next(t_elem *stack, int data)
{
	stack->n = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	stack->n->p = stack;
	stack = stack->n;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->data = data;
	stack->move_a = HOLD;
	stack->move_b = HOLD;
	return (stack);
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_stack	*ft_generate_list(int size, char **array)
{
	int		i;
	t_elem	*node;
	t_stack	*h;

	if (!array[0])
		return (NULL);
	i = 0;
	h = malloc(sizeof(t_stack));
	if (!h)
		return (NULL);
	ft_init_stack_status(h);
	node = ft_stack_add_first(h, atoi(array[i]));
	free(array[i]);
	i++;
	while (i < size)
	{
		node = ft_stack_add_next(node, atoi(array[i]));
		free(array[i]);
		i++;
	}
	node->n = h->ta;
	h->ta->p = node;
	h->size_a = size;
	ft_updt_min_max(h->ta, &h->max_a, &h->min_a);
	return (h);
}

