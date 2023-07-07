/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap copy 2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:14:25 by antoda-s         ###   ########.fr       */
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
