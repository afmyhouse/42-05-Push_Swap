/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:51:13 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:34:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			SWAP the top two elements of the stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_ss(t_stack *h)
{
	ft_sx(h, 'a', _NOPRINT);
	ft_sx(h, 'b', _NOPRINT);
	write(1, "ss\n", 3);
	return (1);
}
