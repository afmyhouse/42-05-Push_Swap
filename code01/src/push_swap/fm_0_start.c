/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_0_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 12:47:32 by antoda-s         ###   ########.fr       */
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
		return (ft_error());
	if (array == (char **)*(av))
		len = ac - 1;
	else
		len = ft_array_len(array);
	if (ft_args_check(len, array))
		return (ft_error());
	h = ft_stack_init(len, array);
	if (array != av)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
	sort_machine(h);
	ft_stack_free(h);
	return (SUCCESS);
}
