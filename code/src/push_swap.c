/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/06 15:55:35 by antoda-s         ###   ########.fr       */
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
		if(!array)
			return (NULL);
	}
	return (array);
}

/// @brief 		STARTS THE PROGRAM
/// @param ac	args count
/// @param av	args array (expected a string o ints)
/// @return		SUCCESS - no errors, ERROR - otherwise
int	main(int ac, char **av)
{
	t_stack	*h;
	char	**array;
	int		len;
	int		i;

	array = ft_args_build(ac - 1, ++av);
	if (!array)
		return (0);
	if ( array == (char **)*(av))
		len = ac - 1;
	else
		len = ft_array_len(array);
	if (ft_args_check(len, array))
		return (ft_error());
	h = ft_generate_list(len, array);
	if ( array != av)
	{
		i = 0;
		while(array[i])
			free(array[i++]);
		free(array);
	}
	ft_browse_stacks(h);
	ft_sort_machine(h);
	ft_browse_stacks(h);
	ft_free_list(h);
	return (SUCCESS);
}
