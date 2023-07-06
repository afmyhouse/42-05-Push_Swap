/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 23:34:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Builds a string from the arguments passed to the program
/// @param ac	Number of arguments
/// @param av	Pointer to the array of arguments
/// @return		Pointer to the string built
char	*ft_args_build_n(int ac, char **av)
{
	int		i;
	char	*s1;
	char	*s2;
	char	*tmp;

	i = 1;
	s1 = malloc(sizeof(char) * 1);
	s2 = av[i];
	while (i < (ac))
	{
		if (i - 1)
		s1 = ft_strjoin(s1, " ");
		tmp = s1;
		s1 = ft_strjoin(s1, s2);
		s2 = av[i + 1];
		if (tmp)
			free(tmp);
		i++;
	}
	return (s1);
}

/// @brief 			Builds a string from the arguments passed to the program
/// @param av		Pointer to the array of arguments
/// @return			Pointer to the string built
char	*ft_args_build_2(char **av)
{
	if (!av[1][0])
	{
		ft_error();
		printf("check args : void\n");
		return (NULL);
	}
	return (av[1]);
}

/// @brief 			Builds int array from the arguments passed to the program
/// @param ac		Number of arguments
/// @param av		Pointer to the array of arguments
/// @return			Pointer to the int array built
char	**ft_args_build(int ac, char **av)
{
	char	*s1;
	char	**array;

	if (ac == 1)
	{
		ft_error();
		printf("check args : empty\n");
		return (NULL);
	}
	else if (ac > 2)
		s1 = ft_args_build_n(ac, av);
	else if (ac == 2)
		s1 = ft_args_build_2(av);
	if (!s1)
		return (NULL);
	array = ft_split(s1, ' ');
	if (s1 != av[1])
	{
		free(s1);
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

	array = ft_args_build(ac, av);
	if (!array)
		return (0);
	len = ft_array_len(array);
	if (ft_args_check(len, array))
		return (ft_error());
	h = ft_generate_list(len, array);
	free(array);
	ft_browse_stacks(h);
	ft_sort_machine(h);
	ft_browse_stacks(h);

	return (SUCCESS);
}
