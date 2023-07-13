/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 11:58:49 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_stack	*ft_stack_init(int size, char **array)
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
	ft_stack_init_status(h);
	node = ft_stack_add_first(h, atoi(array[i]));
	i++;
	while (i < size)
	{
		node = ft_stack_add_next(node, atoi(array[i]));
		i++;
	}
	node->n = h->ta;
	h->ta->p = node;
	h->size_a = size;
	ft_stack_limits_updt(h->ta, &h->max_a, &h->min_a);
	return (h);
}

/// @brief 			Add fisrt element to a circular list and update head pointer
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to first element of the stack, NULL if error malloc
t_elem	*ft_stack_add_first(t_stack *h, int data)
{
	t_elem	*node;

	node = malloc(sizeof(t_elem));
	if (!node)
		return (NULL);
	h->ta = node;
	node->p = h->ta;
	node->n = h->ta;
	node->cost_a = 0;
	node->cost_b = 0;
	node->data = data;
	node->move_a = HOLD;
	node->move_b = HOLD;
	h->min_a = data;
	h->max_a = data;
	h->min_b = 0;
	h->max_b = 0;
	return (node);
}

/// @brief 			Adds a new element to the circular stack
/// @param stack	Pointer to the stack last added element
/// @return			Pointer to the stack current element, NULL if error malloc
t_elem	*ft_stack_add_next(t_elem *node, int data)
{
	node->n = malloc(sizeof(t_elem));
	if (!node)
		return (NULL);
	node->n->p = node;
	node = node->n;
	node->cost_a = 0;
	node->cost_b = 0;
	node->data = data;
	node->move_a = HOLD;
	node->move_b = HOLD;
	return (node);
}

/// @brief 			Initialize the information about the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_stack_init_status(t_stack *h)
{
	*h = (t_stack){NULL, 0, 0, 0, NULL, 0, 0, 0, 0};
	return ;
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
void	ft_stack_free(t_stack *h)
{
	t_elem	*node;
	t_elem	*tmp;

	if (!h->ta)
		return ;
	node = h->ta;
	node->p->n = NULL;
	while (node)
	{
		tmp = node->n;
		node->n = 0;
		node->p = 0;
		node->cost_a = 0;
		node->cost_b = 0;
		node->data = 0;
		node->move_a = HOLD;
		node->move_b = HOLD;
		free(node);
		node = tmp;
	}
	ft_stack_init_status(h);
	free(h);
	return ;
}
