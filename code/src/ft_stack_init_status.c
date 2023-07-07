/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacker copy 2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:22:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:05:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Initialize the information about the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_stack_init_status(t_stack *h)
{
	h->ta = NULL;
	h->size_a = 0;
	h->min_a = 0;
	h->max_a = 0;
	h->tb = NULL;
	h->size_b = 0;
	h->min_b = 0;
	h->max_b = 0;
	h->moves = 0;
	return ;
}
