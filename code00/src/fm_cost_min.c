/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_raw copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:35:40 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:43:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
