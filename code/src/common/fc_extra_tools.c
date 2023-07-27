/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_extra_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:14:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 22:16:10 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Display the stack content
/// @param t		Pointer to the top of the stack
/// @param b		Pointer to the bottom of the stack
/// @param stack	Stack to display
/// @param color	Color to display the stack
void	extra_browse_stack_print(t_elem *t, t_elem *b, char stack, char *color)
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
void	extra_browse_stack(t_stack *h, t_flags *f, char stack)
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
		extra_browse_stack_print(h->ta, h->ta->p, stack, color);
	else if (stack == 'b' && h->tb)
		extra_browse_stack_print(h->tb, h->tb->p, stack, color);
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
void	extra_browse_stacks(t_stack *h, t_flags *f)
{
	if (!f->show_stacks)
		return ;
	extra_browse_stack(h, f, 'a');
	extra_browse_stack(h, f, 'b');
	return ;
}

/// @brief 			Displays the moves
/// @param f		Information regarding flags :
///					-c show_colors
///					-m show_moves
///					-l log moves to file
///					-s show stack
/// @param m		Move to display
void	extra_moves_show(t_flags *f, char *m)
{
	if (!*m)
		return ;
	if (!f->show_colors && f->show_moves)
		ft_printf("->%s", m);
	else if (f->show_colors && f->show_moves)
	{
		if (m[0] == 's' && (m[1] == 'a' || m[1] == 'b' || \
		m[1] == 's') && m[2] == '\n')
			ft_printf("%s->%s%s", BLU, m, WTH);
		else if (m[0] == 'p' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
			ft_printf("%s->%s%s", YLW, m, WTH);
		else if (m[0] == 'r' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
			ft_printf("%s->%s%s", GRN, m, WTH);
		else if (m[0] == 'r' && m[1] == 'r' && (m[2] == 'a' || m[2] == 'b') \
		&& m[3] == '\n')
			ft_printf("%s->%s%s", RED, m, WTH);
		else if (m[0] == 'r' && m[1] == 'r' && (m[2] == '\n' || m[2] == 'r'))
			ft_printf("%s->%s%s", CYN, m, WTH);
	}
	if (f->save_moves)
		write(f->fd, m, ft_strlen(m));
	return ;
}
