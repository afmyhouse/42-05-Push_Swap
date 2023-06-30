/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 17:20:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Pull TOP element from stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	ft_px_src(t_elem **top_src)
{
	if(_SHOWFUNCTION)
		ft_printf("void %sft_px_src%s(t_elem **top_src = %s%p%s)\n",YLW,WTH, BLU,(*top_src),WTH);
	if ((*top_src)->n == (*top_src))
		(*top_src)->n = NULL;
	else
	{
		(*top_src)->p->n = (*top_src)->n;
		(*top_src)->n->p = (*top_src)->p;
	}
	return ;
}

/// @brief 			Push TOP element to stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	ft_px_dst(t_elem **top_src, t_elem **top_dst)
{
	if(_SHOWFUNCTION)
		ft_printf("void %sft_px_dst%s(t_elem **top_dst = %s%p%s)\n",YLW,WTH, BLU,(*top_dst),WTH);
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

/// @brief 			PUSH the top element of src stack to dst stack
/// @param top_src	Pointer to the top of the src stack
/// @param top_dst	Pointer to the top of the dst stack
void	ft_px_stack(t_elem **top_src, t_elem **top_dst)
{
	if(_SHOWFUNCTION)
		ft_printf("void %sft_px_stack%s(t_elem **top_src = %s%p%s, t_elem **top_dst = %s%p%s)\n",YLW,WTH, BLU,(*top_src),WTH,BLU, (*top_dst),WTH);
	t_elem	*new_top_src;

	ft_px_src(&(*top_src));
	new_top_src = (*top_src)->n;
	ft_px_dst(&(*top_src), &(*top_dst));
	*top_src = new_top_src;
	return ;
}

/// @brief 			PUSH the top element of A stack to B stack
/// @param p2s		Pointer to the stacks
/// @param stack	stack to push to ('A' | 'B')
void	ft_px(t_stack *p2s, char stack)
{
	ft_printf("p%c\n", stack);
	if(_SHOWFUNCTION)
		ft_printf("void %sft_px%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s), char stack : %s%c%s)\n",YLW,WTH, BLU,p2s->ta,WTH, BLU,p2s->tb,WTH, BLU,stack,WTH);
	t_stack	push;

	push = *p2s;
	if ((!push.ta && stack == 'b') && _DEBUG)
		ft_printf("p%c error : stack 'a' empty\n", stack);
	if ((!push.tb && stack == 'a') && _DEBUG)
		ft_printf("p%c error : stack 'b' empty\n", stack);
	if (stack == 'a' && push.tb != NULL)
	{
		ft_px_stack(&push.tb, &push.ta);
		push.ta_size++;
		push.tb_size--;
	}
	else if (stack == 'b' && push.ta != NULL)
	{
		ft_px_stack(&push.ta, &push.tb);
		push.ta_size--;
		push.tb_size++;
	}
	*p2s = push;
	ft_browse_stacks(p2s);
	ft_printf("size a : %d | size b : %d\n", p2s->ta_size, p2s->tb_size);
	return ;
}
