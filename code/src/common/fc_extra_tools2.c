/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_extra_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:52:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/26 18:48:15 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_browse_stack_print_index(t_stack *h, char stack, char *color)
{
	t_elem	*cur;
	int		j;

	j = 1;
	cur = h->ta;
	ft_printf("%sh->size_a = %d%s  \n", YLW, h->size_a, WTH);
	ft_printf("%sh->ta = %p  \n", color, cur);
	while (j <= h->size_a)
	{
		ft_printf("%02d\t[%02d][%02d] \n", cur->data, cur->i, cur->cost_a);
		cur = cur->n;
		j++;
	}
	if (stack == 'b')
		ft_printf("-----\n");
	ft_printf("%s", WTH);
	return ;
}
