/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacker copy 4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:22:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:06:31 by antoda-s         ###   ########.fr       */
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
