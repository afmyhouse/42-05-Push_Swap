/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/04 23:58:03 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Checks if the args dont include repetitions
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - no repetitions, ERROR - otherwise
int	ft_args_check_norepeat(char **array, int len)
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
			{
				printf("check args repeat\n");
				return (ERROR);
			}
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
int	ft_args_check_void(char **array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!array[i][0])
		{
			printf("check args void\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

/// @brief			Checks if the args are numbers
/// @param array	Pointer to the array of args
/// @param len		Number of args
/// @return			SUCCESS - all numbers, ERROR - otherwise
int	ft_args_check_isnum(char **array, int len)
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
			if (!ft_isdigit(c) && c != ' ' && !ft_issign(c))
			{
				printf("check args : not int\n");
				return (ERROR);
			}
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
int	ft_args_check_limits(char **array, int len)
{
	int		i;
	long	nb1;
	long	nb2;
	int		sign;

	i = 0;
	sign = 1;
	while (i < len)
	{
		if (array[i][0] == '-')
			sign = -1;
		nb1 = ft_atoi(array[i] + ft_strlen(array[i]) - 1);
		nb2 = (ft_atoi(array[i]) % 10) * sign;
		sign = 1;
		if (nb1 != nb2)
		{
			printf("check args : limits\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

/// @brief 			Checks if the args are valid
/// @param len		Number of args
/// @param array	Pointer to the array of args
/// @return			SUCCESS - valid, ERROR - otherwise
int	ft_args_check(int len, char **array)
{
	if (len <= 1)
	{
		printf("check args : len <= 1\n");
		return (ERROR);
	}
	if (ft_args_check_isnum(array, len))
		return (ERROR);
	if (ft_args_check_void(array, len))
		return (ERROR);
	if (ft_args_check_norepeat(array, len))
		return (ERROR);
	if (ft_args_check_limits(array, len))
		return (ERROR);
	return (SUCCESS);
}
