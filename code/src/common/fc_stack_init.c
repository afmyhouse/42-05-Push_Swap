/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 20:06:25 by antoda-s         ###   ########.fr       */
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
	node->i = 0;
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
	node->i = 0;
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
t_flags	*flags_init(int ac, char **av)
{
	t_flags	*f;

	f = malloc(sizeof(t_flags));
	if (!f)
		return (NULL);
	*f = (t_flags){0, 0, 0, 0, 0, 0, ac, av};
	return (f);
}
