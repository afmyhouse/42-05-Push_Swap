/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:04:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:33:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			ROTATION REVERSE both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_rrr(t_stack *h)
{
	if (!h->ta && !h->tb)
		return (ERROR);
	if (h->size_a > 1)
		h->ta = h->ta->p;
	if (h->size_b > 1)
		h->tb = h->tb->p;
	write(1, "rrr\n", 4);
	return (SUCCESS);
}
