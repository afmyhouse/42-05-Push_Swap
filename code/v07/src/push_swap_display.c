/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/17 19:44:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Display the stack content
/// @param p2s		Pointer to the stack head (top of the stack)
/// @param stack	Stack to display
void	ft_browse_stack(t_stack *p2s, char stack)
{
	if(_SHOWFUNCTION)
		ft_printf("void %sft_browse_stack%s(t_stack *p2s, char stack)\n",YLW,WTH);
	t_elem	*top;
	t_elem	*bottom;
	if (!_SHOWLIST)
		return ;
	if (stack == 'b' && p2s->tb)
	{
		top = p2s->tb;
		bottom = p2s->tb->p;
	}
	else if (stack == 'a' && p2s->ta)
	{
		top = p2s->ta;
		bottom = p2s->ta->p;
	}
	else
	{
		ft_printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
	}
	if (_DEBUG && stack == 'a')
	{
		ft_printf("%sStack %c: %s", BLU, stack, WTH);
	}
	else if (_DEBUG && stack == 'b')
	{
		ft_printf("%sStack %c: %s", PPL, stack, WTH);
	}
	while (top != bottom && top)
	{
		ft_printf("%d ", top->data);
		top = top->n;
	}
	ft_printf("%d\n", top->data);
	return ;
}

/// @brief 			Displays both stacks 'a' and 'b'
/// @param p2s		Pointer to the stacks head (top of the stack)
void	ft_browse_stacks(t_stack *p2s)
{
	if(_SHOWFUNCTION)
		ft_printf("void %sft_browse_stacks%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n",YLW,WTH, YLW, p2s->ta, WTH, YLW, p2s->tb, WTH);
	if (!_SHOWLIST)
		return ;
	ft_browse_stack(p2s, 'a');
	ft_browse_stack(p2s, 'b');

}
