/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 22:46:56 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			TEST several action on the stacks
/// @param p2s		Pointer to the stacks
void	ft_sort_stack_test(t_stack *p2s)
{
	if(_SHOWFUNCTION)
	{
		ft_printf("\n############################################################################\n");
		ft_printf("void %sft_sort_stack_test%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n",YLW,WTH, YLW,p2s->ta,WTH,YLW, p2s->tb,WTH);
		ft_printf("############################################################################\n\n");
	}
	if (!p2s->ta && !p2s->tb)
		return ;

	if (_DEBUG)
		ft_printf("%s****************  unsorted list  **********************%s\n", YLW, WTH);
	ft_browse_stacks(p2s);
	ft_sx(p2s, 'a', _PRINT);
	ft_px(p2s, 'b');
	ft_px(p2s, 'b');
	ft_px(p2s, 'b');
	ft_sx(p2s, 'a', _PRINT);
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
	ft_ss(p2s);
	if (_DEBUG)
		ft_printf("%s****************    sorted list  **********************%s\n", YLW, WTH);
	ft_printf("*\n");
	return ;
}

/// @brief 			TEST the stack
/// @param p2s		Pointer to the top of stack A and top of stack B
void	ft_inital_stack_test(t_stack *p2s)
{
	if (_SHOWFUNCTION)
	{
		printf("void %sft_initial_stack_test%s(t_stack *p2s = (ta : %s%p%s)\
		(tb : %s%p%s))\n", YLW, WTH, GRN, p2s->ta, WTH, GRN, p2s->tb, WTH);
	}
	if (!p2s->ta)
		return ;
	ft_printf("\n\n******** test list********\n\n");
	ft_browse_stacks(p2s);
	ft_ra(p2s);
	ft_rb(p2s);
	ft_rra(p2s);
	ft_rrb(p2s);
	ft_sx(p2s, 'a', _PRINT);
	ft_sx(p2s, 'b', _PRINT);
	ft_px(p2s, 'b');
	ft_px(p2s, 'b');
	ft_px(p2s, 'b');
	ft_rb(p2s);
	ft_ra(p2s);
	ft_rrb(p2s);
	ft_rrb(p2s);
	ft_rr(p2s);
	ft_rrr(p2s);
	ft_sx(p2s, 'b', _PRINT);
	ft_sx(p2s, 'b', _PRINT);
	ft_px(p2s, 'b');
	ft_px(p2s, 'a');
	ft_ss(p2s);
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
	return ;
}


/// @brief 			SORT mechanics will be tested here
/// @param p2s		Pointer to the top of stack A and top of stack B
/// @param size		Size of the list to sort
void	ft_sort_machine(t_stack *p2s, int size)
{
	if(_SHOWFUNCTION)
	{
		ft_printf("############################################################################\n");
		ft_printf("void %sft_sort_machine%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s), int size = %i)\n",YLW,WTH, GRN,p2s->ta,WTH, GRN,p2s->tb,WTH, size);
		ft_printf("############################################################################\n");
	}
	int lowest;
	while (p2s->ta != p2s->ta->n)
	{
		lowest = ft_get_lowest(p2s);
		while (p2s->ta->data != lowest)
			ft_ra(p2s);
		ft_px(p2s, 'b');
	}
	//ft_browse_stacks(p2s);
	while (p2s->tb)
		ft_px(p2s, 'a');
	return ;
}