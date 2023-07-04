/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:45:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 00:12:49 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Displays errors when args or process not successful
/// @param		-	void
/// @return	-		ERROR
int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}

/// @brief 			Find the maximum value in an int pair
/// @param a		First int
/// @param b		Second int
/// @return	-		Minimum value
int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/// @brief 			Find the minimum value in an int pair
/// @param a		First int
/// @param b		Second int
/// @return			Minimum value
int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/// @brief 			Find the length of the integers(ASCII) array
/// @param array	Pointer to the array
/// @return			Length of the array
int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
