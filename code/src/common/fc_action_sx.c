/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_action_sx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:51:13 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 19:50:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SWAP the top two elements of the stack
/// @param swap_top	Pointer to the stack
void	action_sx_stack(t_elem **swap_top)
{
	(*swap_top)->p->n = (*swap_top)->n;
	(*swap_top)->n->p = (*swap_top)->p;
	(*swap_top)->p = (*swap_top)->n;
	(*swap_top)->n = (*swap_top)->n->n;
	(*swap_top)->n->p->n = (*swap_top);
	(*swap_top)->n->p = (*swap_top);
	(*swap_top) = (*swap_top)->p;
	return ;
}

/// @brief 			SWAP the top two elements of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to swap
int	action_sx(t_stack *h, char stack, int print)
{
	t_stack	swap;

	swap = *h;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')))
		return (ERROR);
	else
	{
		if (stack == 'a' && swap.ta != NULL && swap.size_a > 1)
		{
			action_sx_stack(&swap.ta);
			if (print)
				write(1, "sa\n", 3);
		}
		if (stack == 'b' && swap.tb != NULL && swap.size_b > 1)
		{
			action_sx_stack(&swap.tb);
			if (print)
				write(1, "sb\n", 3);
		}
		*h = swap;
		return (SUCCESS);
	}
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	action_ss(t_stack *h, int print)
{
	action_sx(h, 'a', _NOPRINT);
	action_sx(h, 'b', _NOPRINT);
	if (print)
		write(1, "ss\n", 3);
	return (1);
}
