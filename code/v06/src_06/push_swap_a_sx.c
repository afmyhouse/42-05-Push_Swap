/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_sx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/13 01:31:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SWAP the top two elements of the stack
/// @param stack	Pointer to the stack
void	ft_sx(t_elem **stack)
{
	(*stack)->p->n = (*stack)->n;
	(*stack)->n->p = (*stack)->p;

	(*stack)->p = (*stack)->n;
	(*stack)->n = (*stack)->n->n;

	(*stack)->n->p->n = (*stack);
	(*stack)->n->p = (*stack);

	(*stack) = (*stack)->p;
	return ;
}

/// @brief 			SWAP the top two elements of the stack
/// @param p2s		Pointer to the stack
/// @param stack	stack to swap
void	ft_sx_stack(t_stack *p2s, char stack, int print)
{
	t_stack	swap;

	swap = *p2s;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')) && _DEBUG)
		ft_printf("s%c error : stack '%c' empty\n", stack, stack);
	if (stack == 'a' && swap.ta != NULL)
	{
		ft_sx(&swap.ta);
		if (print)
			ft_printf("s%c\n", stack);
	}
	else if (stack == 'b' && swap.tb != NULL)
	{
		ft_sx(&swap.tb);
		if (print)
			ft_printf("s%c\n", stack);
	}

	*p2s = swap;
	return ;
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param p2s		Pointer to the stacks
void	ft_ss_stack(t_stack *p2s)
{
	write(1, "ss\n", 3);
	ft_sx_stack(p2s, 'a', 0);
	ft_sx_stack(p2s, 'b', 0);
}
