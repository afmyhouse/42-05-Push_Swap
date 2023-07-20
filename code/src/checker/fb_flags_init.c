/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_flags_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/19 23:24:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_flags	*ft_flags_init(int ac, char **av)
{
	t_flags	*f;

	f = malloc(sizeof(t_flags));
	if (!f)
		return (NULL);
	*f = (t_flags){0, 0, 0, 0, 0, 0, ac, av};
	return (f);
}
