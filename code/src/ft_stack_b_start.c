/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:40:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:01:48 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Inializes B stack with the up to 3 elements of A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_stack_b_start(t_stack *h)
{
	int	i;

	i = 3;
	while (h->size_a > 3 && i--)
		ft_px(h, 'b');
	ft_sort_3(h, 'b');
}
