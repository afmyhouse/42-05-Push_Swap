/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap copy 3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:15:06 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
