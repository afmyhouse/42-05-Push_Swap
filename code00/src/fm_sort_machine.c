/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 14:08:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	sort_machine(t_stack *h)
{
	if (ft_sort_check(h))
		return ;
	if (h->size_a <= 3)
		ft_sort_3(h, 'a');
	else
	{
		ft_stack_b_start(h);
		ft_sort_to_b(h);
		ft_sort_3(h, 'a');
		ft_sort_to_a(h);
		ft_sort_final(h);
	}
	return ;
}
