/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/10 23:22:55 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		Generates a list of elements
/// @param av	Arguments
/// @param ac	Number of arguments
/// @return		Pointer to the stack
t_stack	*ft_generate_list(char **av, int ac)
{
	int		i;
	t_elem	*stack;
	t_stack	*p2s;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
		{
			stack = malloc(sizeof(t_elem));
			p2s = malloc(sizeof(t_stack));
			p2s->ta = stack;
			stack->p = p2s->ta;
			stack->n = p2s->ta;
		}
		else
		{
			stack->n = malloc(sizeof(t_elem));
			stack->n->p = stack;
			stack = stack->n;
		}
		stack->data = atoi(av[i]);
		i++;
	}
	stack->n = p2s->ta;
	p2s->ta->p = stack;
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
		printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
	}
	if (_DEBUG && stack == 'a')
	{
		printf("%sStack %c: %s", BLU, stack, WTH);
	}
	else if (_DEBUG && stack == 'b')
	{
		printf("%sStack %c: %s", PPL, stack, WTH);
	}
	while (top != bottom  && top)
	{
		printf("%d ", top->data);
		top = top->n;
	}
	printf("%d\n", top->data);
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
		printf("**************\n");
	}
}

/// @brief 			FORWARD Rotates the A stack top element to the bottom
/// @param p2s		Pointer to the stack
void	ft_ra_stack(t_stack *p2s)
{
	write(1, "ra\n", 3);
	p2s->ta = p2s->ta->n;
}

/// @brief 			FORWARD Rotates the B stack top element to the bottom
/// @param p2s	Pointer to the stack
void	ft_rb_stack(t_stack *p2s)
{
	write(1, "rb\n", 3);
	p2s->tb = p2s->tb->n;
}

/// @brief 			FORWARD Rotates top to bottom on both stack A and B
/// @param p2s		Pointer to the stacks
void	ft_rr_stack(t_stack *p2s)
{
	write(1, "rr\n", 3);
	p2s->ta = p2s->ta->n;
	p2s->tb = p2s->tb->n;
}

/// @brief 			REVERSE Rotates the A stack bottom element to the top
/// @param p2s		Pointer to the stack
void	ft_rra_stack(t_stack *p2s)
{
	write(1, "rra\n", 4);
	p2s->ta = p2s->ta->p;
}

/// @brief 			REVERSE Rotates the B stack bottom element to the top
/// @param p2s		Pointer to the stack
void	ft_rrb_stack(t_stack *p2s)
{
	write(1, "rrb\n", 4);
	p2s->tb = p2s->tb->p;
}

/// @brief 			REVERSE Rotates bottom to top on both stack A and B
/// @param p2s		Pointer to the stacks
void	ft_rrr_stack(t_stack *p2s)
{
	write(1, "rrr\n", 4);
	p2s->ta = p2s->ta->p;
	p2s->tb = p2s->tb->p;
}

/// @brief 			SWAP the top two elements of the stack
/// @param stack	Pointer to the stack
void	ft_sx(t_elem **stack)
{
	(*stack)->p->n = (*stack)->n;
	(*stack)->n->p = (*stack)->p;

	(*stack)->p = (*stack)->n;
	(*stack)->n = (*stack)->n->n;

	(*stack)->n->p->n = (*stack);
	(*stack)->n->p = (*stack);

	(*stack) = (*stack)->p;
	return ;
}

/// @brief 			SWAP the top two elements of the stack
/// @param p2s		Pointer to the stack
/// @param stack	stack to swap
void	ft_sx_stack(t_stack *p2s, char stack, int print)
{
	t_stack	swap;

	swap = *p2s;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')) && _DEBUG)
		printf("s%c error : stack '%c' empty\n", stack, stack);
	if (stack == 'a' && swap.ta != NULL)
	{
		ft_sx(&swap.ta);
		if (print)
			printf("s%c\n", stack);
	}
	else if (stack == 'b' && swap.tb != NULL)
	{
		ft_sx(&swap.tb);
		if (print)
			printf("s%c\n", stack);
	}

	*p2s = swap;
	return ;
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param p2s		Pointer to the stacks
void	ft_ss_stack(t_stack *p2s)
{
	write(1, "ss\n", 3);
	ft_sx_stack(p2s, 'a', 0);
	ft_sx_stack(p2s, 'b', 0);
}

/// @brief 			Pull TOP element from stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	ft_px_src(t_elem **top_src)
{

	if ((*top_src)->n == (*top_src))
		(*top_src)->n = NULL;
	else
	{
		(*top_src)->p->n = (*top_src)->n;
		(*top_src)->n->p = (*top_src)->p;
	}
	return ;
}

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

/// @brief 			PUSH the top element of src stack to dst stack
/// @param top_src	Pointer to the top of the src stack
/// @param top_dst	Pointer to the top of the dst stack
void	ft_px(t_elem **top_src, t_elem **top_dst)
{
	t_elem	*new_top_src;

	ft_px_src(&(*top_src));
	new_top_src = (*top_src)->n;
	ft_px_dst(&(*top_src), &(*top_dst));
	*top_src = new_top_src;
	return ;
}

/// @brief 			PUSH the top element of A stack to B stack
/// @param p2s		Pointer to the stacks
/// @param stack	stack to push to ('A' | 'B')
void	ft_px_stack(t_stack *p2s, char stack)
{
	t_stack	push;

	push = *p2s;
	if ((!push.ta && stack == 'b') && _DEBUG)
		printf("p%c error : stack 'a' empty\n", stack);
	if ((!push.tb && stack == 'a') && _DEBUG)
		printf("p%c error : stack 'b' empty\n", stack);
	if (stack == 'a' && push.tb != NULL)
	{
		ft_px(&push.tb, &push.ta);
		printf("p%c\n", stack);
	}
	else if (stack == 'b' && push.ta != NULL)
	{
		ft_px(&push.ta, &push.tb);
		printf("p%c\n", stack);
	}
	*p2s = push;

	return ;
}


/// @brief 			TEST several action on the stacks
/// @param p2s		Pointer to the stacks
void	ft_sort_stack_test(t_stack *p2s)
{
	if (!p2s->ta && !p2s->tb)
		return ;

	printf("*sort list*\n");
	ft_browse_stack(p2s, 'a');
	ft_browse_stack(p2s, 'b');
	printf("*\n");
	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_ss_stack(p2s);
	printf("%s*sort result*%s\n", YLW, WTH);
	ft_browse_stack(p2s, 'a');
	ft_browse_stack(p2s, 'b');
	//ft_printf("*\n");
	printf("*\n");

	return ;
}

/// @brief 			TEST the stack
/// @param p2s		Pointer to the top of stack A and top of stack B
void	ft_inital_stack_test(t_stack *p2s)
{
	if (!p2s->ta)
		return ;

	printf("*test list*\n");
	ft_browse_stacks(p2s);

	ft_ra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_ra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_rra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_rra_stack(p2s);
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'a', 1);
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'b', 1);
	ft_browse_stacks(p2s);

	ft_sx_stack(p2s, 'b', 1);
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'b');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);

	ft_px_stack(p2s, 'a');
	ft_browse_stacks(p2s);

	return ;
}

/// @brief 			SORT mechanics will be tested here
/// @param p2s		Pointer to the top of stack A and top of stack B
/// @param size		Size of the list to sort
void	ft_sort_machine(t_stack *p2s, int size)
{
	int i;

	i = 0;
	if (_DEBUG)
		printf("%s*sort machine*%s\n", YLW, WTH);
	while (i < size)
	{
		ft_px_stack(p2s, 'b');
		i++;
	}
	ft_browse_stacks(p2s);
	ft_sort_stack_test(p2s);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*p2s;
	int mydebug;

	if (ac > 2)
		mydebug = 0;
	else
		mydebug = 1;
	if (mydebug)
	{
		printf("\n*** mydebug mode : no args ***\n");
		ac = 7;
		av[1] = "2";
		av[2] = "1";
		av[3] = "3";
		av[4] = "6";
		av[5] = "5";
		av[6] = "8";
	}
	if (ac >= 2)
	{
		printf("ac = %i\n", ac - 1);
		p2s = ft_generate_list(av, ac);
		if (_DEBUG)
			ft_inital_stack_test(p2s);
		ft_sort_stack_test(p2s);
		ft_sort_machine(p2s, ac - 1);
	}

	if (_DEBUG)
		write(1, "Hello World!\n", 13);

	return (0);
}

/*./push_swap 86 16 6 69 93 23 12 70 52 28 47 22 40 60 24 10 95 44 65 100 3 63 51 82 71 39 17 5 33 43 53 34 89 27 37 2 32 50 98 57 1 46 21 64 8 45 18 14 13 15 25 76 79 91 9 81 85 4 11 68 59 55 7 84 73 66 87 19 92 29 67 42 90 77 80 54 38 20 35 83 62 49 30 75 31 74 58 36 26 72 56 61 99 88 94 48 96 78 41 97*/