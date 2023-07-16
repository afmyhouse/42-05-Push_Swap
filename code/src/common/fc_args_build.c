/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_args_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/16 20:08:37 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Builds int array from the arguments passed to the program
/// @param ac		Number of arguments
/// @param av		Pointer to the array of arguments
/// @return			Pointer to the int array built
char	**ft_args_build(int ac, char **av)
{
	char	**array;

	if (_DEBUG_)
		printf("args_build : ac = %d\n", ac);

	array = 0x0;
	// if (ac == 0)
	// {
	// 	ft_error();
	// 	return (NULL);
	// }
	//else if (ac > 1)
	if (ac > 1)
		return (av);
	else if (ac == 1)
	{
		if (_DEBUG_)
		{
			printf("args_build : else if ac == 1 : ac    = %d\n", ac);
			printf("args_build : else if ac == 1 : av[0] = %s\n", av[0]);
		}
		array = ft_split(av[0], ' ');
		if (!array)
			return (NULL);
	}
	if (_DEBUG_)
		printf("args_build : return (array) : array = %p\n", array);
	return (array);
}
