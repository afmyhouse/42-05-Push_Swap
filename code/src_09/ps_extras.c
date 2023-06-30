/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:31:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 17:32:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Print a banner with the program name and version
/// @param mydebug	Flag to print debug mode
/// @param ac		Number of arguments
void	ft_banner(int mydebug, int ac)
{
	ft_printf("\n");
	ft_printf("#########################################################################\n");
	ft_printf("##                  push_swap : %s                                    ##\n", VERSION);
	if (!mydebug)
		ft_printf("##                  real mode : args OK                                ##\n");
	else
		ft_printf("##                 debug mode : no args                                ##\n");
	ft_printf("##             number of args = %04i                                   ##\n", ac -1);
	ft_printf("#########################################################################\n\n");
}
