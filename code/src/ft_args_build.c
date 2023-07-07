/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:16:22 by antoda-s         ###   ########.fr       */
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

	array = 0x0;
	if (ac == 0)
	{
		ft_error();
		return (NULL);
	}
	else if (ac > 1)
		return (av);
	else if (ac == 1)
	{
		array = ft_split(av[0], ' ');
		if (!array)
			return (NULL);
	}
	return (array);
}
