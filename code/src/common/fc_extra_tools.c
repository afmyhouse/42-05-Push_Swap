/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_extra_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:14:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/19 18:53:46 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_browse_stack_print(t_elem *t, t_elem *b, char stack, char *color)
{
	ft_printf("%s%c -> %s", color, stack);
	while (t != b && t)
	{
		ft_printf("%d ", t->data);
		t = t->n;
	}
	ft_printf("%d%s\n", t->data, WTH);
	if (stack == 'b')
		ft_printf("-----\n");
	return ;
}

/// @brief			Display the stack content
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to display
void	ft_browse_stack(t_stack *h, t_flags *f, char stack)
{
	char	*color;

	color = WTH;
	if (!f->show_stacks)
		return ;
	if (f->show_colors && stack == 'a')
		color = BLU;
	else if (f->show_colors && stack == 'b')
		color = GRN;
	if (stack == 'a' && h->ta)
		ft_browse_stack_print(h->ta, h->ta->p, stack, color);
	else if (stack == 'b' && h->tb)
		ft_browse_stack_print(h->tb, h->tb->p, stack, color);
	else if (stack == 'a' && !h->ta)
		ft_printf("%s%c -> stack is empty, %s\n", color, stack, WTH);
	else if (stack == 'b' && !h->tb)
		ft_printf("%s%c -> stack is empty, %s\n-----\n", color, stack, WTH);
	return ;
}

/// @brief 			Displays both stacks 'a' and 'b'
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_browse_stacks(t_stack *h, t_flags *f)
{
	if (!f->show_stacks)
		return ;
	ft_browse_stack(h, f, 'a');
	ft_browse_stack(h, f, 'b');
	return ;
}

void	ft_pause_key_nl(void)
{
	char	*line;

	line = (char *)malloc(2);
	line[0] = '\0';
	while (!read(0, line, 1))
		if (line[0] == ' ')
			break ;
	ft_free_str(&line);
	return ;
}
