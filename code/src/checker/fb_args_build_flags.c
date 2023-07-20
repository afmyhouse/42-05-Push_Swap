/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_args_build_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/20 14:46:58 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Builds int array from the arguments passed to the program
/// @param ac		Number of arguments
/// @param av		Pointer to the array of arguments
/// @return			Pointer to the int array built
int	ft_args_build_c(t_flags *f)
{
	if (f->len > 1)
		ft_flags_detector(f);
	if (f->len > 1)
	{
		f->any_flag = TRUE;
		return (SUCCESS);
	}
	else if (f->len == 1)
	{
		f->any_flag = FALSE;
		if (!ft_strlen(f->arg[0]))
		{
			ft_error();
			return (ERROR);
		}
		f->arg = ft_split(f->arg[0], ' ');
		if (!f->arg)
			return (ERROR);
		f->len = ft_array_len(f->arg);
	}
	return (SUCCESS);
}

int	ft_flags_detector(t_flags *f)
{
	int	i;

	i = 1;
	f->any_flag = 1;
	if (f->arg[0][0] == '-')
	{
		while (f->any_flag && f->arg[0][i])
		{
			if (f->arg[0][i] != 's' && f->arg[0][i] != 'c' && \
			f->arg[0][i] != 'm' && f->arg[0][i] != 'r')
				f->any_flag = 0;
			i++;
		}
		if (f->any_flag)
			ft_flags_parser(f);
	}
	return (SUCCESS);
}

int	ft_flags_wrong(t_flags *f, int i)
{
	if (f->arg[0][i] == 's' || f->arg[0][i] == 'c' || \
	f->arg[0][i] == 'm' || f->arg[0][i] == 'r')
		ft_printf("Warning! '%c' flag is repeated!\n", f->arg[0][i]);
	else
		ft_printf("Warning: '%c' is not a flag!\n", f->arg[0][i]);
	return (ERROR);
}

int	ft_flags_parser(t_flags *f)
{
	int	i;

	i = 1;
	while (f->arg[0][i])
	{
		if (f->arg[0][i] == 's' && !f->show_stacks)
			f->show_stacks = 1;
		else if (f->arg[0][i] == 'c' && !f->show_colors)
			f->show_colors = 1;
		else if (f->arg[0][i] == 'm' && !f->show_moves)
			f->show_moves = 1;
		else if (f->arg[0][i] == 'r' && !f->save_moves)
		{
			f->fd = open("moves.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
			f->save_moves = 1;
		}
		else
			return (ft_flags_wrong(f, i));
		i++;
	}
	f->arg++;
	f->len--;
	return (SUCCESS);
}

void	ft_extra_moves_show(t_flags *f, char *m)
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
		else if (m[0] == 'r' && m[1] == 'r' && m[2] == '\n')
			ft_printf("%s->%s%s", PPL, m, WTH);
	}
	if (f->save_moves)
		write(f->fd, m, ft_strlen(m));
	return ;
}
