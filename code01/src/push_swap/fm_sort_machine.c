/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_sort_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 11:52:05 by antoda-s         ###   ########.fr       */
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
	if (ft_sort_check(h))
		return ;
	if (h->size_a <= 3)
		ft_sort_3(h, 'a');
	else
	{
		ft_stack_b_start(h);
		ft_sort_to_b(h);
		ft_sort_3(h, 'a');
		ft_sort_to_a(h);
		ft_sort_final(h);
	}
	return ;
}

/// @brief 			PUSH back all of nodes from B to A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_final(t_stack *h)
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
			ft_rrx(h, 'a', _PRINT);
	}
	else
	{
		while (h->ta->data != h->min_a)
			ft_rx(h, 'a', _PRINT);
	}
	return ;
}

/// @brief 			Find the best node to push to stack A
/// @param h		Information regarding :
void	ft_sort_to_a(t_stack *h)
{
	t_elem	*best;

	while (h->size_b)
	{
		best = ft_cost_get(h, 'b');
		if (best->cost_a || best->cost_b)
			ft_move_to_top(h, best);
		ft_px(h, 'a', _PRINT);
	}
	return ;
}

/// @brief 			Find the best node to push to stack B
/// @param h	Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_to_b(t_stack *h)
{
	t_elem	*best;

	while (h->size_a > 3)
	{
		best = ft_cost_get(h, 'a');
		if (best->cost_a || best->cost_b)
			ft_move_to_top(h, best);
		ft_px(h, 'b', _PRINT);
	}
	return ;
}
