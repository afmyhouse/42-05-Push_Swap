/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check_norepeat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:48:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Checks if the args dont include repetitions
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - no repetitions, ERROR - otherwise
int	ft_args_check_norepeat(int len, char **array)
{
	int		i;
	int		j;
	int		cmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		cmp = atoi(array[i]);
		while (j < len)
		{
			if (cmp == atoi(array[j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
