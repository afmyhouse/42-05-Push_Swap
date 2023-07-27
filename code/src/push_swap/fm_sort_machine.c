/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_sort_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 22:02:49 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	sort_machine(t_stack *h)
{
	if (sort_check(h))
		return ;
	if (h->size_a <= 3)
		sort_3_x(h, 'a');
	else
	{
		ft_stack_b_start(h);
		sort_to_x(h, 'b');
		sort_3_x(h, 'a');
		sort_to_x(h, 'a');
		sort_final(h);
	}
	return ;
}

/// @brief 			PUSH back all of nodes from B to A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	sort_final(t_stack *h)
{
	t_elem	*cur;
	int		cost;
	int		mid;

	cost = 0;
	mid = h->size_a / 2 + h->size_a % 2;
	cur = h->ta;
	while (cur->data != h->min_a && ++cost)
		cur = cur->n;
	cost = cost % h->size_a;
	if (!cost)
		return ;
	else if (cost > (mid - h->size_a % 2))
	{
		while (h->ta->data != h->min_a)
			action_rrx(h, 'a', _PRINT);
	}
	else
	{
		while (h->ta->data != h->min_a)
			action_rx(h, 'a', _PRINT);
	}
	return ;
}

/// @brief 			Find the best node to push to stack A or B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to push to
void	sort_to_x(t_stack *h, char stack)
{
	t_elem	*best;

	if (stack == 'a')
	{
		while (h->size_b)
		{
			best = cost_get(h, 'b');
			if (best->cost_a || best->cost_b)
				move_to_top(h, best);
			action_px(h, 'a', _PRINT);
		}
	}
	else if (stack == 'b')
	{
		while (h->size_a > 3)
		{
			best = cost_get(h, 'a');
			if (best->cost_a || best->cost_b)
				move_to_top(h, best);
			action_px(h, 'b', _PRINT);
		}
	}
	return ;
}

/// @brief 			Inializes B stack with the up to 3 elements of A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_stack_b_start(t_stack *h)
{
	int	i;

	i = 3;
	while (h->size_a > 3 && i--)
		action_px(h, 'b', _PRINT);
	sort_3_x(h, 'b');
}
