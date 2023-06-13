/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/11 00:21:10 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			TEST several action on the stacks
/// @param p2s		Pointer to the stacks
void	ft_sort_stack_test(t_stack *p2s)
{
	if (!p2s->ta && !p2s->tb)
		return ;

	printf("*sort list*\n");
	ft_browse_stack(p2s, 'a');
	ft_browse_stack(p2s, 'b');
	printf("*\n");
	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_ss_stack(p2s);
	printf("%s*sort result*%s\n", YLW, WTH);
	ft_browse_stack(p2s, 'a');
	ft_browse_stack(p2s, 'b');
	ft_printf("*PRINTED with FT_PRINTF*\n");
	printf("*\n");

	return ;
}

/// @brief 			TEST the stack
/// @param p2s		Pointer to the top of stack A and top of stack B
void	ft_inital_stack_test(t_stack *p2s)
{
	if (!p2s->ta)
		return ;

	printf("*test list*\n");
	ft_browse_stacks(p2s);

	ft_ra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_ra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_rra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_rra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'b', 1);
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'b', 1);
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);

	return ;
}

/// @brief 			SORT mechanics will be tested here
/// @param p2s		Pointer to the top of stack A and top of stack B
/// @param size		Size of the list to sort
void	ft_sort_machine(t_stack *p2s, int size)
{
	int i;

	i = 0;
	if (_DEBUG)
		printf("%s*sort machine*%s\n", YLW, WTH);
	while (i < size)
	{
		ft_px_stack(p2s, 'b');
		i++;
	}
	ft_browse_stacks(p2s);
	ft_sort_stack_test(p2s);
	return ;
}
