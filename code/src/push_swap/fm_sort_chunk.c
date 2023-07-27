/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_sort_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 22:10:09 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_chunk_index_a(t_stack *h, int j, int k)
{
	t_elem	*cur;
	t_elem	*low;

	while (j <= h->size_a)
	{
		k = 1;
		cur = h->ta;
		while (cur->i && cur->i != h->size_a && k++)
			cur = cur->n;
		if (!cur->i)
		{
			low = cur;
			while (k++ < h->size_a)
			{
				cur = cur->n;
				if (cur->data < low->data && cur->i == 0)
					low = cur;
			}
			low->i = j++;
		}
		else
			break ;
	}
	return ;
}

/// @brief 		Assigns an index to each element of stack A
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param lowest element lowest cost of the chunk
void	sort_chunk_index_2b2(t_stack *h, const int lowest)
{
	t_elem	*node;

	node = h->ta;
	while (node->cost_a != lowest)
		node = node->n;
	move_single(h, node);
	action_px(h, 'b', _PRINT);
	return ;
}

/// @brief 		Assigns an index to each element of stack A
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param j	Index of the current element
/// @param i	Index of the current chunk
/// @param lowest	element lowest cost of the chunk
/// @return		1 if new element, 0 otherwise
int	sort_chunk_index_2b1(t_stack *h, int j, const int i, int lowest)
{
	int		new_elem;
	t_elem	*cur;

	new_elem = 0;
	cur = h->ta;
	while (j < h->size_a)
	{
		if (cur->i <= i)
		{
			cur->cost_a = ft_min_int(j, h->size_a - j);
			if (ft_min_int(j, h->size_a - j) == j)
				cur->move_a = RX;
			else
				cur->move_a = RRX;
			if (cur->cost_a < lowest)
				lowest = cur->cost_a;
			new_elem = 1;
		}
		cur = cur->n;
		j++;
	}
	if (new_elem)
		sort_chunk_index_2b2(h, lowest);
	return (new_elem);
}

/// @brief 		pushs to  stack B chunks of size _CHUNK_
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param f	Information regarding :
///				display of color (-c), display of stacks (-s),
///				display of moves (-m), log moves to file moves.txt (-l)
void	sort_chunk_index_2b(t_stack *h, t_flags *f)
{
	int		k;
	int		chunk_size;

	extra_browse_stacks(h, f);
	k = 1;
	h->chunk = ft_min_int(h->size_a / _CHUNK_, 4);
	chunk_size = (h->size_a / h->chunk);
	while (h->size_a > 3)
	{
		if (!sort_chunk_index_2b1(h, 0, k * chunk_size, \
		h->size_a / 2 + h->size_a % 2))
			k++;
	}
	return ;
}

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	sort_chunk(t_stack *h, t_flags *f)
{
	if (sort_check(h))
		return ;
	if (h->size_a <= 3)
		sort_3_x(h, 'a');
	else
	{
		sort_chunk_index_a(h, 1, 1);
		sort_chunk_index_2b(h, f);
		sort_3_x(h, 'a');
		sort_to_x(h, 'a');
		sort_final(h);
	}
	return ;
}
