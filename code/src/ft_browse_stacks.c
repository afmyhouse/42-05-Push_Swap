/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_extras_browse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:14:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 00:36:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Display the stack content
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to display
void	ft_browse_stack(t_stack *h, char stack)
{
	t_elem	*top;
	t_elem	*bottom;

	if (stack == 'b' && h->tb)
	{
		top = h->tb;
		bottom = h->tb->p;
	}
	else if (stack == 'a' && h->ta)
	{
		top = h->ta;
		bottom = h->ta->p;
	}
	else
	{
		printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
	}
	while (top != bottom && top)
	{
		printf("%d ", top->data);
		top = top->n;
	}
	printf("%d\n", top->data);
	return ;
}

/// @brief 			Displays both stacks 'a' and 'b'
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_browse_stacks(t_stack *h)
{
	if (!_SHOW_STACKS_)
		return ;
	ft_browse_stack(h, 'a');
	ft_browse_stack(h, 'b');
	return ;
}
