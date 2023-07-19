/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/19 12:36:18 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		STARTS THE PROGRAM
/// @param ac	args count
/// @param av	args array (expected a string o ints)
/// @return		SUCCESS - no errors, ERROR - otherwise
int	main(int ac, char **av)
{
	t_stack	*h;
	char	**array;
	int		len;
	int		i;

	array = ft_args_build(ac - 1, ++av);
	if (!array)
		return (0);
	if (array == (char **)*(av))
		len = ac - 1;
	else
		len = ft_array_len(array);
	if (ft_args_check(len, array) == ERROR)
		return (ft_error());
	h = ft_stack_init(len, array);
	if (array != av)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
	i = check_machine(h);
	ft_stack_free_x(h);
	return (i);
}

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	check_machine(t_stack *h)
{
	if (ft_action(h) == SUCCESS)
	{
		if (_DEBUG_)
			ft_browse_stacks(h);
		if (h->size_b || !ft_sort_check(h))
			return (ft_checker_result(ERROR));
		else if (ft_sort_check(h))
			return (ft_checker_result(SUCCESS));
	}
	else
		return (ft_error());
	return (ERROR);
}

int	ft_action(t_stack *h)
{
	char	*line;
	int		result;

	result = SUCCESS;
	line = ps_gnl();
	while (*line)
	{
		ft_browse_stacks(h);
		if (check_mover(h, line) == ERROR)
		{
			result = ERROR;
			break ;
		}
		if (line)
			ft_free_str(&line);
		line = ps_gnl();
	}
	if (line)
		ft_free_str(&line);
	ft_browse_stacks(h);
	return (result);
}

/// @brief 			Checks if the stack is sorted
/// @param result	Pointer to the stack
/// @return			0 if sorted, 1 otherwise
int	ft_checker_result(int result)
{
	if (result == SUCCESS)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (result);
}

int	check_mover(t_stack *h, char *m)
{
	if (!*m)
	{
		return (SUCCESS);
	}
	if (m[0] == 's' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		ft_sx(h, m[1], 0);
	else if (m[0] == 's' && m[1] == 's' && m[2] == '\n')
		ft_ss(h, 0);
	else if (m[0] == 'p' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		ft_px(h, m[1], 0);
	else if (m[0] == 'r' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		ft_rx(h, m[1], 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == '\n')
		ft_rr(h, 0);
	else if (m[0] == 'r' && m[1] == 'r' && (m[2] == 'a' || m[2] == 'b') \
	&& m[3] == '\n')
		ft_rrx(h, m[2], 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == 'r' && m[3] == '\n')
		ft_rrr(h, 0);
	else
	{
		return (ERROR);
	}
	return (SUCCESS);
}
