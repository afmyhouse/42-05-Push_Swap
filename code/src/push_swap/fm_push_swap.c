/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/31 14:41:05 by antoda-s         ###   ########.fr       */
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
	t_flags	*f;

	signal(SIGPIPE, SIG_IGN);
	if (ac == 1)
		return (0);
	f = flags_init(ac - 1, ++av);
	f->any_flag = TRUE;
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
	if (h->size_a >= 100)
		sort_chunk(h, f);
	else
		sort_cost(h);
	ft_free_structs(h, f);
	return (0);
}
