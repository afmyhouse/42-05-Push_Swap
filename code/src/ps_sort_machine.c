/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/06 17:03:03 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Check if the A stack is sorted
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			TRUE if sorted, FASLE if not
int	ft_check_sort(t_stack *h)
{
	t_elem	*tmp;

	tmp = h->ta;
	while (tmp != h->ta->p)
	{
		if (tmp->data > tmp->n->data)
			return (FALSE);
		tmp = tmp->n;
	}
	return (TRUE);
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
			ft_rrx(h, 'a');
	}
	else
	{
		while (h->ta->data != h->min_a)
			ft_rx(h, 'a');
	}
	return ;
}

/// @brief 			Find the best node to push to stack B
/// @param h	Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_2_b(t_stack *h)
{
	t_elem	*best;

	while (h->size_a > 3)
	{
		best = ft_get_cost(h, 'a');
		if (best->cost_a || best->cost_b)
			ft_move_best2top(h, best);
		ft_px(h, 'b');
	}
	return ;
}

/// @brief 			Find the best node to push to stack A
/// @param h		Information regarding :
void	ft_sort_2_a(t_stack *h)
{
	t_elem	*best;

	while (h->size_b)
	{
		best = ft_get_cost(h, 'b');
		if (best->cost_a || best->cost_b)
			ft_move_best2top(h, best);
		ft_px(h, 'a');
	}
	return ;
}

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_machine(t_stack *h)
{
	if (ft_check_sort(h))
		return ;
	if (h->size_a <= 3)
		ft_sort_3(h, 'a');
	else if (h->size_a <= _SHORT_SIZE_)
		ft_sort_short(h);
	else
	{
		ft_start_stack_b(h);
		ft_sort_2_b(h);
		ft_sort_3(h, 'a');
		ft_sort_2_a(h);
		ft_sort_final(h);
	}
	return ;
}