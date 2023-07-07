/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check_isnum.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:48:01 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Checks if the args are numbers
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - all numbers, ERROR - otherwise
int	ft_args_check_isnum(int len, char **array)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (array[i][j])
		{
			c = array[i][j];
			if (!ft_isdigit(c) && !ft_isspace(c) && !ft_issign(c))
				return (ERROR);
			if (ft_issign(c) && !ft_isdigit(array[i][j + 1]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
