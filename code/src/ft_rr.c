/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:04:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:33:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			ROTATION FORWARD top to bottom on both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_rr(t_stack *h)
{
	if (h->size_a > 1)
		h->ta = h->ta->n;
	if (h->size_b > 1)
		h->tb = h->tb->n;
	if (h->size_a > 1 || h->size_b > 1)
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}
