/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_action_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:43:43 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 18:21:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Push TOP element to stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	action_px_dst(t_elem **top_src, t_elem **top_dst)
{
	if (!*top_dst)
	{
		*top_dst = *top_src;
		(*top_dst)->n = *top_dst;
		(*top_dst)->p = *top_dst;
	}
	else
	{
		(*top_src)->n = *top_dst;
		(*top_src)->p = (*top_dst)->p;
		(*top_dst)->p->n = *top_src;
		(*top_dst)->p = *top_src;
		*top_dst = *top_src;
	}
	return ;
}

/// @brief 			Pull TOP element from stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	action_px_source(t_elem **top_src)
{
	if ((*top_src)->n == (*top_src))
		(*top_src)->n = NULL;
	else
	{
		(*top_src)->p->n = (*top_src)->n;
		(*top_src)->n->p = (*top_src)->p;
	}
	return ;
}

/// @brief 			PUSH the top element of src stack to dst stack
/// @param top_src	Pointer to the top of the src stack
/// @param top_dst	Pointer to the top of the dst stack
void	action_px_stack(t_elem **top_src, t_elem **top_dst)
{
	t_elem	*new_top_src;

	action_px_source(&(*top_src));
	new_top_src = (*top_src)->n;
	action_px_dst(&(*top_src), &(*top_dst));
	*top_src = new_top_src;
	return ;
}

/// @brief 			PUSH the top element of A stack to B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to push to ('A' | 'B')
/// @return			1 if success, 0 if fail
int	action_px(t_stack *h, char stack, int print)
{
	t_stack	push;

	push = *h;
	if ((!push.ta && stack == 'b') || (!push.tb && stack == 'a'))
		return (ERROR);
	if (stack == 'a' && push.tb != NULL)
	{
		action_px_stack(&push.tb, &push.ta);
		push.size_a++;
		push.size_b--;
		if (print)
			write(1, "pa\n", 3);
	}
	else if (stack == 'b' && push.ta != NULL)
	{
		action_px_stack(&push.ta, &push.tb);
		push.size_a--;
		push.size_b++;
		if (print)
			write(1, "pb\n", 3);
	}
	*h = push;
	ft_stack_limits_chk(h, stack);
	return (SUCCESS);
}
