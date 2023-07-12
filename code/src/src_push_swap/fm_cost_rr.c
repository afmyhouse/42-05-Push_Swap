/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_optimizer copy 2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:32:53 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:39:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		SET COST as 'rr' movement of the node
/// @param node	Pointer to the node to SET COST
/// @return		SUCCESS or ERROR
int	ft_cost_rr(t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else
		node->move_a = RX;
	if (!node->cost_b)
		node->move_b = HOLD;
	else
		node->move_b = RX;
	return (SUCCESS);
}
