/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/16 15:31:58 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_elem	*ft_stack_add_first(t_stack *p2s)
{
	t_elem	*stack;

	stack = malloc(sizeof(t_elem));
	p2s->ta = stack;
	stack->p = p2s->ta;
	stack->n = p2s->ta;
	return (stack);
}

t_elem	*ft_stack_add_next(t_elem *stack)
{
	stack->n = malloc(sizeof(t_elem));
	stack->n->p = stack;
	stack = stack->n;
	return (stack);
}

/// @brief 		Generates a list of elements
/// @param av	Arguments
/// @param ac	Number of arguments
/// @return		Pointer to the stack
t_stack	*ft_generate_list(int size, char **av)
{
	int		i;
	t_elem	*stack_node;
	t_stack	*p2s;

	if (!av[1])
		return (NULL);
	i = 1;
	p2s = malloc(sizeof(t_stack));
	stack_node = ft_stack_add_first(p2s);
	stack_node->data = atoi(av[i++]);
	while (i < size)
	{
		stack_node = ft_stack_add_next(stack_node);
		stack_node->data = atoi(av[i++]);
	}
	stack_node->n = p2s->ta;
	p2s->ta->p = stack_node;
	return (p2s);
}

/// @brief 			Displays the stack
/// @param p2s		Pointer to the stack
void	ft_browse_stack(t_stack *p2s, char stack)
{
	t_elem	*top;
	t_elem	*bottom;

	if (stack == 'b' && p2s->tb)
	{
		top = p2s->tb;
		bottom = p2s->tb->p;
	}
	else if (stack == 'a' && p2s->ta)
	{
		top = p2s->ta;
		bottom = p2s->ta->p;
	}
	else
	{
		ft_printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
	}
	if (_DEBUG && stack == 'a')
	{
		ft_printf("%sStack %c: %s", BLU, stack, WTH);
	}
	else if (_DEBUG && stack == 'b')
	{
		ft_printf("%sStack %c: %s", PPL, stack, WTH);
	}
	while (top != bottom && top)
	{
		ft_printf("%d ", top->data);
		top = top->n;
	}
	ft_printf("%d\n", top->data);
	return ;
}

/// @brief 			Displays the stacks A and B
/// @param p2s		Pointer to the stacks
void	ft_browse_stacks(t_stack *p2s)
{
	if (_DEBUG)
	{
		ft_browse_stack(p2s, 'a');
		ft_browse_stack(p2s, 'b');
		ft_printf("**************\n");
	}
}
