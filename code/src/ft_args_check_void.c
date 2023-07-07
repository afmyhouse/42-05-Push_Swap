/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check_void.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:48:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Checks if the args dont include voids
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - no voids, ERROR - otherwise
int	ft_args_check_void(int len, char **array)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!array[i][0])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
