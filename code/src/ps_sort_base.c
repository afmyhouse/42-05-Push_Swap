/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:40:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 00:14:19 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SORTS the 3 elements of the any stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to sort
void	ft_sort_3(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if (h->size_a == 3)
			ft_sort_3a(h);
		else if (h->size_a == 2)
		{
			if (h->ta->data > h->ta->n->data)
				ft_sx(h, 'a', _PRINT);
		}
	}
	else if (stack == 'b')
	{
		if (h->size_b == 3)
			ft_sort_3b(h);
		else if (h->size_b == 2)
		{
			if (h->tb->data < h->tb->n->data)
				ft_sx(h, 'b', _PRINT);
		}
	}
}

/// @brief			SORT ASCENDING the 3 nodes, A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_3a(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->ta->data > h->ta->n->data)
		{
			if (h->ta->data < h->ta->p->data)
				swap = !ft_sx(h, 'a', _PRINT);
			if (h->ta->data > h->ta->p->data)
				swap = !ft_rx(h, 'a');
		}
		if ((h->ta->data < h->ta->n->data) && (h->ta->n->data > h->ta->p->data))
			swap = !ft_rrx(h, 'a');
	}
}

/// @brief			SORT DESCENDING the 3 nodes, B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_3b(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->tb->data < h->tb->n->data)
		{
			if (h->tb->data > h->tb->p->data)
				swap = ft_sx(h, 'b', _PRINT);
			if (h->tb->data < h->tb->p->data)
				swap = ft_rx(h, 'b');
		}
		if ((h->tb->data > h->tb->n->data) && (h->tb->n->data < h->tb->p->data))
			swap = !ft_rrx(h, 'b');
	}
}

/// @brief 			SORTS the 5 elements of the any stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_short(t_stack *h)
{
	t_elem	*cur;
	int		i;

	i = 0;
	cur = h->ta;
	while (!ft_check_sort(h))
	{
		i = 0;
		cur = h->ta;
		while (i < h->size_a)
		{
			if (cur->data > cur->n->data && (cur->data != h->max_a || \
			cur->n->data != h->min_a))
				break ;
			if (cur->p->data > cur->data && (cur->p->data != h->max_a || \
			cur->data != h->min_a))
			{
				i = h->size_a - 1;
				break ;
			}
			cur = cur->n;
			i++;
		}
		if (i < h->size_a)
		{
			if (i > h->size_a / 2 - h->size_a % 2)
			{
				i = h->size_a - i;
				while (i--)
					ft_rrx(h, 'a');
			}
			else
				while (i--)
					ft_rx(h, 'a');
			if (h->ta->data > h->ta->n->data)
				ft_sx(h, 'a', _PRINT);
		}
		else
		{
			i = 0;
			cur = h->ta;
			while (cur->data != h->min_a)
			{
				i++;
				cur = cur->n;
			}
			if (i > h->size_a / 2 - h->size_a % 2)
			{
				i = h->size_a - i;
				while (i--)
					ft_rrx(h, 'a');
			}
			else
				while (i--)
					ft_rx(h, 'a');
		}
		cur = h->ta;
	}
	return ;
}

/// @brief 			Inializes B stack with the up to 3 elements of A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_start_stack_b(t_stack *h)
{
	int	i;

	i = 3;
	while (h->size_a > 3 && i--)
		ft_px(h, 'b');
	ft_sort_3(h, 'b');
}

