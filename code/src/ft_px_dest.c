/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_dest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:43:43 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/07 01:32:36 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Push TOP element to stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	ft_px_dst(t_elem **top_src, t_elem **top_dst)
{
	if (!*top_dst)
	{
		*top_dst = *top_src;
		(*top_dst)->n = *top_dst;
		(*top_dst)->p = *top_dst;
	}
	else
	{
		(*top_src)->n = *top_dst;
		(*top_src)->p = (*top_dst)->p;
		(*top_dst)->p->n = *top_src;
		(*top_dst)->p = *top_src;
		*top_dst = *top_src;
	}
	return ;
}
