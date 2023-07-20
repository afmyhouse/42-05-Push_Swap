/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:45:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/19 23:41:35 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
void	ft_stack_free_a(t_stack *h)
{
	t_elem	*node;
	t_elem	*tmp;

	if (!h->size_a)
		return ;
	node = h->ta;
	node->p->n = NULL;
	while (node)
	{
		tmp = node->n;
		*node = (t_elem){0, 0, 0, 0, 0, NULL, NULL};
		free(node);
		node = tmp;
	}
	return ;
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
void	ft_stack_free_b(t_stack *h)
{
	t_elem	*node;
	t_elem	*tmp;

	if (!h->size_b)
		return ;
	node = h->tb;
	node->p->n = NULL;
	while (node)
	{
		tmp = node->n;
		*node = (t_elem){0, 0, 0, 0, 0, NULL, NULL};
		free(node);
		node = tmp;
	}
	return ;
}

/// @brief 		Generates a list of elements from an array of arguments
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
void	ft_stack_free_x(t_stack *h)
{
	if (h->size_a)
		ft_stack_free_a(h);
	if (h->size_b)
		ft_stack_free_b(h);
	if (!h)
		return ;
	ft_stack_init_status(h);
	free(h);
	return ;
}

/// @brief 		Generates a list of elements from an array of arguments
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
void	ft_stack_free_f(t_flags *f)
{
	int	i;

	if (!f)
		return ;
	if (!f->any_flag)
	{
		i = 0;
		while (f->arg[i])
			free(f->arg[i++]);
		free(f->arg);
	}
	if (f->save_moves)
		close(f->fd);
	*f = (t_flags){0, 0, 0, 0, 0, 0, 0, NULL};
	free(f);
	return ;
}
