/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:45:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 12:00:31 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Find the length of the integers(ASCII) array
/// @param array	Pointer to the array
/// @return			Length of the array
int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/// @brief 			Displays errors when args or process not successful
/// @param		-	void
/// @return	-		ERROR
int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}

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
		ft_printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
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
