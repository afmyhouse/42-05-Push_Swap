/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/09 22:56:21 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief		STARTS THE PROGRAM
/// @param ac	args count
/// @param av	args array (expected a string o ints)
/// @return		SUCCESS - no errors, ERROR - otherwise
int	main(int ac, char **av)
{
	t_stack	*h;
	t_flags	*f;

	if (ac == 1)
		return (0);
	f = flags_init(ac - 1, ++av);
	if (args_build(f) == ERROR || !f->arg)
	{
		ft_stack_free_f(f);
		return (0);
	}
	if (args_check(f->len, f->arg) == ERROR)
	{
		ft_stack_free_f(f);
		return (ft_error());
	}
	h = ft_stack_init(f->len, f->arg);
	checker_machine(h, f);
	ft_stack_free_x(h);
	ft_stack_free_f(f);
	return (0);
}

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	checker_machine(t_stack *h, t_flags *f)
{
	extra_browse_stacks(h, f);
	if (checker_get_move(h, f) == SUCCESS)
	{
		if (h->size_b || !sort_check(h))
			return (checker_result(ERROR, f->show_colors));
		else if (sort_check(h))
			return (checker_result(SUCCESS, f->show_colors));
	}
	else
		return (ft_error());
	return (ERROR);
}

/// @brief 			Read move from pipe
/// @param h		Pointer to the stack
/// @param f		Pointer to the flags
/// @return			0 if sorted, 1 otherwise
int	checker_get_move(t_stack *h, t_flags *f)
{
	char	*line;
	int		result;

	result = SUCCESS;
	line = ps_gnl();
	while (*line)
	{
		if (checker_mover(h, line) == ERROR)
		{
			result = ERROR;
			break ;
		}
		if (f->show_moves || f->save_moves)
			extra_moves_show(f, line);
		extra_browse_stacks(h, f);
		if (line)
			ft_free_str(&line);
		line = ps_gnl();
	}
	if (line)
		ft_free_str(&line);
	return (result);
}

/// @brief 			Checks if the stack is sorted
/// @param result	Pointer to the stack
/// @return			0 if sorted, 1 otherwise
int	checker_result(int result, int fcolor)
{
	char	*color;

	color = WTH;
	if (result == SUCCESS)
	{
		if (fcolor)
			color = YLW;
		ft_printf("%sOK%s\n", color, WTH);
	}
	else
	{
		if (fcolor)
			color = RED;
		ft_printf("%sKO%s\n", color, WTH);
	}
	return (result);
}

/// @brief 			Execute move read from pipe
/// @param h		Pointer to the stack
/// @param m		Pointer to the movement string
/// @return			0 if sorted, 1 otherwise
int	checker_mover(t_stack *h, char *m)
{
	if (!*m)
		return (SUCCESS);
	else if (m[0] == 's' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		action_sx(h, m[1], 0);
	else if (m[0] == 's' && m[1] == 's' && m[2] == '\n')
		action_ss(h, 0);
	else if (m[0] == 'p' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		action_px(h, m[1], 0);
	else if (m[0] == 'r' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		action_rx(h, m[1], 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == '\n')
		action_rr(h, 0);
	else if (m[0] == 'r' && m[1] == 'r' && (m[2] == 'a' || m[2] == 'b') \
	&& m[3] == '\n')
		action_rrx(h, m[2], 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == 'r' && m[3] == '\n')
		action_rrr(h, 0);
	else
		return (ERROR);
	return (SUCCESS);
}
