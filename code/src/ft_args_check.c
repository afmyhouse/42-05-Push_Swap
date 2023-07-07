/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:49:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Checks if the args are valid
/// @param len		Number of args
/// @param array	Pointer to the array of args
/// @return			SUCCESS - valid, ERROR - otherwise
int	ft_args_check(int len, char **array)
{
	if (len <= 1)
		return (ERROR);
	if (ft_args_check_isnum(len, array))
		return (ERROR);
	if (ft_args_check_void(len, array))
		return (ERROR);
	if (ft_args_check_norepeat(len, array))
		return (ERROR);
	if (ft_args_check_limits(len, array))
		return (ERROR);
	return (SUCCESS);
}
