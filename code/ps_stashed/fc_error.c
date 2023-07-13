/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:45:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 02:09:39 by antoda-s         ###   ########.fr       */
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
