/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_check_machine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:46:56 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/12 21:48:41 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	check_machine(t_stack *h)
{
	char	*line;

	if (ft_sort_check(h))
		return ;
	else
	{
		line = get_next_line(0);
		while (line)
		{
			if (check_mover(h, line))
				return (ft_error());
			if (line)
				ft_free_str(&line);
			line = get_next_line(0);
		}
		if (h->size_b || !ft_sort_check(h))
			return (ft_error());
		else if (ft_sort_check(h))
			return (SUCCESS);
	}
	return ;
}

int	check_mover(t_stack *h, char *m)
{

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
		return (ft_error());
	return (SUCCESS);
}
