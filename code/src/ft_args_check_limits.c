/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check_limits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:48:23 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Checks if the args are within the limits of an int
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - within limits, ERROR - otherwise
int	ft_args_check_limits(int len, char **array)
{
	int			i;
	long int	nb1;

	i = 0;
	while (i < len)
	{
		nb1 = ft_atol(array[i]);
		if (nb1 > INT_MAX || nb1 < INT_MIN)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
