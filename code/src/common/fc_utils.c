/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:45:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/15 15:30:12 by antoda-s         ###   ########.fr       */
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

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
void	ft_stack_free(t_stack *h)
{
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
void	ft_stack_free_x(t_stack *h)
{
	if (h->size_a)
		ft_stack_free_a(h);
	if (h->size_b)
		ft_stack_free_b(h);
	if (h)
		ft_stack_free(h);
	return ;
}
