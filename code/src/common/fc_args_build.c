/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_args_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/21 11:37:23 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Detects kind of flag error
/// @param f	Pointer to the structure containing the flags
/// @param i	location of error char in the string
/// @return		ERROR signal
int	ft_flags_error(t_flags *f, int i)
{
	if (f->arg[0][i] == 's' || f->arg[0][i] == 'c' || \
	f->arg[0][i] == 'm' || f->arg[0][i] == 'l')
		ft_printf("Warning! '%c' flag is repeated!\n", f->arg[0][i]);
	else
		ft_printf("Warning: '%c' is not a flag!\n", f->arg[0][i]);
	return (ERROR);
}

/// @brief 		Checks if the flag is valid and sets the flag
/// @param f	Pointer to the structure containing the flags
/// @return		SUCCESS if the flag is valid, ERROR otherwise
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
		else if (f->arg[0][i] == 'l' && !f->save_moves)
		{
			f->fd = open("moves.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
			f->save_moves = 1;
		}
		else
			return (ft_flags_error(f, i));
		i++;
	}
	f->arg++;
	f->len--;
	return (SUCCESS);
}

/// @brief		Checks if there are flags in the command line input
/// @param f	Pointer to the structure containing the flags
/// @return		SUCCESS if there are flags ERROR otherwise
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
			f->arg[0][i] != 'm' && f->arg[0][i] != 'l')
				f->any_flag = 0;
			i++;
		}
		if (f->any_flag)
			ft_flags_parser(f);
	}
	return (TRUE);
}

/// @brief 			Builds int array from the arguments passed to the program
/// @param f		Pointer to the structure containing the flags
/// @param splits	Offest of resulting array
/// @param size		Offset of src array
/// @param array	Pointer to the array of arguments
/// @return			Pointer to the int array built
int	ft_args_array(t_flags *f, int i_dst, int i_src, char **array)
{
	while (f->arg[i_src])
	{
		if (ft_strchr((f->arg[i_src]), ' '))
		{
			while (*f->arg[i_src])
			{
				while (*f->arg[i_src] == ' ' && *f->arg[i_src])
					f->arg[i_src]++;
				if (*f->arg[i_src] && *f->arg[i_src] != ' ')
					array[i_dst++] = ft_split_slice(f->arg[i_src], ' ');
				while (*f->arg[i_src] && *f->arg[i_src] != ' ')
					f->arg[i_src]++;
			}
		}
		else
			array[i_dst++] = ft_strdup(f->arg[i_src]);
		i_src++;
	}
	f->arg = array;
	f->len = i_dst;
	return (SUCCESS);
}

/// @brief 			Builds int array from the arguments passed to the program
/// @param ac		Number of arguments
/// @param av		Pointer to the array of arguments
/// @return			Pointer to the int array built
int	ft_args_build(t_flags *f)
{
	int		splits;
	int		size;
	char	**array;

	if (f->len > 1 && !f->any_flag)
		ft_flags_detector(f);
	splits = 0;
	size = 0;
	while (f->arg[size])
	{
		splits += ft_split_count(f->arg[size], ' ');
		size++;
	}
	array = (char **)malloc(sizeof(char *) * (splits + 1));
	if (!array)
	{
		free (array);
		return (ERROR);
	}
	array[splits] = NULL;
	return (ft_args_array(f, 0, 0, array));
}
