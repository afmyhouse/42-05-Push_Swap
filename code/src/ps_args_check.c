/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:58:00 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 23:49:37 by antoda-s         ###   ########.fr       */
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
			{
				write(1, "check args : repeat\n", 20);
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
int	ft_args_check_void(int len, char **array)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!array[i][0])
		{
			write(1, "check args : void\n", 18);
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
			if (!ft_isdigit(c) && c != ' ' && !ft_issign(c))
			{
				write(1, "check args : not int\n", 21);
				return (ERROR);
			}
			if (ft_issign(c) && !ft_isdigit(array[i][j + 1]))
			{
				write(1, "check args : sign?\n", 19);
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
int	ft_args_check_limits(int len, char **array)
{
	int		i;
	long int	nb1;
	//long int	nb2;
	//int		sign;

	i = 0;
	//sign = 1;
	while (i < len)
	{
		//if (array[i][0] == '-')
		//	sign = -1;
		nb1 = ft_atol(array[i]);// + ft_strlen(array[i]) - 1);
		//printf("%lu\n", nb1);
		//nb2 = (ft_atoi(array[i]) % 10) * sign;
		//printf("%lu\n", nb1);
		//sign = 1;
		//if (nb1 != nb2)
		if (nb1 > INT_MAX || nb1 < INT_MIN/* condition */)
		{
			write(1, "check args : limits\n", 20);
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
