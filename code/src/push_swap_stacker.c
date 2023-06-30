/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 17:13:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Add fisrt element to a circular list and update head pointer
/// @param p2s		Pointer to the stack head (top of the stack)
/// @return			Pointer to first element of the stack, NULL if error malloc
t_elem	*ft_stack_add_first(t_stack *p2s)
{
	if(_SHOWFUNCTION)
		ft_printf("t_elem \t%s*ft_stack_add_first%s(t_stack *p2s = %s%p%s)\n",YLW,WTH, YLW,p2s,WTH);
	t_elem	*stack;

	stack = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	p2s->ta = stack;
	stack->p = p2s->ta;
	stack->n = p2s->ta;
	return (stack);
}

/// @brief 			Adds a new element to the circular stack
/// @param stack	Pointer to the stack last added element
/// @return			Pointer to the stack current element, NULL if error malloc
t_elem	*ft_stack_add_next(t_elem *stack)
{
	if(_SHOWFUNCTION)
		ft_printf("t_elem \t%s*ft_stack_add_next%s(t_elem *stack = %p)\n",YLW,WTH, stack);
	stack->n = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
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
	if(_SHOWFUNCTION)
		ft_printf("t_stack %s*ft_generate%s(int size = %i, char **av = %s)\n",YLW,WTH, size, av[1]);
	int		i;
	t_elem	*stack_node;
	t_stack	*p2s;

	if (!av[1])
		return (NULL);
	i = 1;
	p2s = malloc(sizeof(t_stack));
	if (!p2s)
		return (NULL);
	stack_node = ft_stack_add_first(p2s);
	stack_node->data = atoi(av[i++]);
	//ft_printf("%sfirst elem%s = %s%p%s : data = %s%i%s)\n",RED,WTH, YLW,p2s->ta,WTH, YLW,p2s->ta->data,WTH);
	while (i < size)
	{
		stack_node = ft_stack_add_next(stack_node);
		stack_node->data = atoi(av[i++]);
	//	ft_printf("%snext  elem%s = %s%p%s : data = %s%i%s)\n",RED,WTH, YLW,stack_node,WTH, YLW,stack_node->data,WTH);
	}
	stack_node->n = p2s->ta;
	p2s->ta->p = stack_node;
	p2s->ta_size = size - 1;
	printf("p2s->ta = %p\n", p2s->ta);
	printf("p2s->ta_size = %i\n", p2s->ta_size);
	printf("p2s->tb = %p\n", p2s->tb);
	printf("p2s->tb_size = %i\n", p2s->tb_size);
	return (p2s);
}
