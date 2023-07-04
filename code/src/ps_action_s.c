/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_action_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:51:13 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/04 23:12:44 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SWAP the top two elements of the stack
/// @param swap_top	Pointer to the stack
void	ft_sx_stack(t_elem **swap_top)
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
int	ft_sx(t_stack *h, char stack, int print)
{
	t_stack	swap;

	swap = *h;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')))
		return (ERROR);
	else
	{
		if (stack == 'a' && swap.ta != NULL && swap.size_a > 1)
			ft_sx_stack(&swap.ta);
		if (stack == 'b' && swap.tb != NULL && swap.size_b > 1)
			ft_sx_stack(&swap.tb);
		*h = swap;
		if (print && ((stack == 'a' && swap.size_a > 1) \
		|| (stack == 'b' && swap.size_b > 1)))
			printf("s%c\n", stack);
		return (SUCCESS);
	}
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	ft_ss(t_stack *h)
{
	ft_sx(h, 'a', _NOPRINT);
	ft_sx(h, 'b', _NOPRINT);
	printf("ss\n");
	return (1);
}
