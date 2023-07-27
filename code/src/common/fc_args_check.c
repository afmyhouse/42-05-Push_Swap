/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/27 18:14:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief			Checks if the args are numbers
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - all numbers, ERROR - otherwise
int	args_check_isvalid(int len, char **array)
{
	int		i;
	int		j;
	char	cur;
	char	next;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (array[i][j])
		{
			cur = array[i][j];
			next = array[i][j + 1];
			if (!ft_isdigit(cur) && !ft_isspace(cur) && !ft_issign(cur))
				return (ERROR);
			if ((ft_issign(cur)) && !ft_isdigit(next))
				return (ERROR);
			if ((ft_isdigit(cur)) && (next && !ft_isdigit(next)))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/// @brief 			Checks if the args dont include voids
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - no voids, ERROR - otherwise
int	args_check_novoid(int len, char **array)
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

/// @brief 			Checks if the args dont include repetitions
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - no repetitions, ERROR - otherwise
int	args_check_norepeat(int len, char **array)
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

/// @brief			Checks if the args are within the limits of an int
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - within limits, ERROR - otherwise
int	args_check_isint(int len, char **array)
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

/// @brief 			Checks if the args are valid
/// @param len		Number of args
/// @param array	Pointer to the array of args
/// @return			SUCCESS - valid, ERROR - otherwise
int	args_check(int len, char **array)
{
	if (args_check_isvalid(len, array))
	{
		return (ERROR);
	}
	if (args_check_novoid(len, array))
	{
		return (ERROR);
	}
	if (args_check_norepeat(len, array))
	{
		return (ERROR);
	}
	if (args_check_isint(len, array))
	{
		return (ERROR);
	}
	return (SUCCESS);
}
