/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/10 17:09:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//#include "../libft/libft.h"

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
			p2s->ta = stack;					// top pointer A stack
			stack->pa = p2s->ta;				// prev pointer points to itself
			stack->na = p2s->ta;				// next pointer points to itself);
		}
		else
		{
			stack->na = malloc(sizeof(t_elem));
			stack->na->pa = stack;
			stack = stack->na;
		}
		stack->nb = NULL;						// stack 'b' doen't exist
		stack->pb = NULL;						// stack 'b' doen't exist
		stack->data = atoi(av[i]);				// add data to element
		i++;
	}
	stack->na = p2s->ta;						// bottom pointer is the last stack element
	p2s->ta->pa = stack;						// top prev pointer points to bottom
	return (p2s);
}

/// @brief 		Displays the stack
/// @param p2s	Pointer to the stack
void	ft_browse_stack(t_stack *p2s, int stack)
{
	t_elem	*top;
	t_elem	*bottom;

	if (stack && p2s->tb)
	{
		top = p2s->tb;
		bottom = p2s->tb->pb;
	}
	else if (!stack && p2s->ta)
	{
		top = p2s->ta;
		bottom = p2s->ta->pa;
	}
	else
	{
		if(_DEBUG)
			printf("%sStack %c: is empty, %s\n", GRN, stack + 'a', WTH);
		return;
	}
	if(_DEBUG)
		printf("Stack %c: ", stack + 'a');
	while (top != bottom  && top)
	{
		printf("%d ", top->data);
		top = (!stack) ? top->na : top->nb;
	}
	printf("%d\n", top->data);
	return ;
}

/// @brief 		FORWARD Rotates the A stack top element to the bottom
/// @param p2s	Pointer to the stack
void	ft_ra_stack(t_stack *p2s)
{
	p2s->ta = p2s->ta->na;
}

/// @brief 		FORWARD Rotates the B stack top element to the bottom
/// @param p2s	Pointer to the stack
void	ft_rb_stack(t_stack *p2s)
{
	p2s->tb = p2s->tb->nb;
}

/// @brief 		REVERSE Rotates the A stack bottom element to the top
/// @param p2s	Pointer to the stack
void	ft_rra_stack(t_stack *p2s)
{
	p2s->ta = p2s->ta->pa;
}

/// @brief 		REVERSE Rotates the B stack top element to the bottom
/// @param p2s
void	ft_rrb_stack(t_stack *p2s)
{
	p2s->tb = p2s->tb->pb;
}
/// @brief 		SWAP the top two elements of the stack
/// @param p2s	Pointer to the stack
void	ft_sa_stack(t_stack *p2s)
{
	p2s->ta->pa->na = p2s->ta->na;
	p2s->ta->na->pa = p2s->ta->pa;

	p2s->ta->pa = p2s->ta->na;
	p2s->ta->na = p2s->ta->na->na;

	p2s->ta->na->pa->na = p2s->ta;
	p2s->ta->na->pa = p2s->ta;

	p2s->ta = p2s->ta->pa;
	return ;

}

/// @brief 		SWAP the top two elements of the stack
/// @param p2s	Pointer to the stack
void	ft_sb_stack(t_stack *p2s)
{
	p2s->tb->pb->nb = p2s->tb->nb;
	p2s->tb->nb->pb = p2s->tb->pb;

	p2s->tb->pb = p2s->tb->nb;
	p2s->tb->nb = p2s->tb->nb->nb;

	p2s->tb->nb->pb->nb = p2s->tb;
	p2s->tb->nb->pb = p2s->tb;

	p2s->tb = p2s->tb->pb;
	return ;

}

/// @brief 		PUSH the top element of B stack to A stack
/// @param p2s	Pointer to the stacks
void	ft_pa_stack(t_stack *p2s)
{
	t_stack swap;

	swap = *p2s;

	if (!swap.tb)
		return ;

	swap.ta = swap.tb;

	if (p2s->tb->nb == p2s->tb)
	{
		p2s->tb = NULL;
	}
	else
	{
		p2s->tb = swap.tb->nb;
		p2s->tb->pb = swap.tb->pb;
		p2s->tb->pb->nb = p2s->tb;
	}
	if (!p2s->ta)
	{
		p2s->ta = swap.ta;
		p2s->ta->na = p2s->ta;
		p2s->ta->pa = p2s->ta;
	}
	else
	{
		swap.ta->na = p2s->ta;
		swap.ta->pa = p2s->ta->pa;

		p2s->ta->pa = swap.ta;

		p2s->ta = swap.ta;
		p2s->ta->pa->na = p2s->ta;
	}
	p2s->ta->nb = NULL;
	p2s->ta->pb = NULL;
	return;
}

/// @brief 		PUSH the top element of A stack to B stack
/// @param p2s	Pointer to the stacks
void	ft_pb_stack(t_stack *p2s)
{
	t_stack swap;

	swap = *p2s;

	if (!swap.ta)
		return;

	swap.tb = swap.ta;

	if (p2s->ta->na == p2s->ta)
	{
		p2s->ta = NULL;
	}
	else
	{
		p2s->ta = swap.ta->na;
		p2s->ta->pa = swap.ta->pa;
		p2s->ta->pa->na = p2s->ta;
	}
	if (!p2s->tb)
	{
		p2s->tb = swap.tb;
		p2s->tb->nb = p2s->tb;
		p2s->tb->pb = p2s->tb;
	}
	else
	{
		swap.tb->nb = p2s->tb;
		swap.ta->pb = p2s->tb->pb;

		p2s->tb->pb = swap.tb;

		p2s->tb = swap.tb;
		p2s->tb->pb->nb = p2s->tb;
	}
	p2s->tb->na = NULL;
	p2s->tb->pa = NULL;
	return;
}

/// @brief 		FORWARD Rotates top element to the bottom on each stack A and B
/// @param p2s	Pointer to the stacks
void	ft_rr_stack(t_stack *p2s)
{
	ft_ra_stack(p2s);
	ft_rb_stack(p2s);
}

/// @brief 		REVERSE Rotates top element to the bottom on each stack A and B
/// @param p2s	Pointer to the stacks
void ft_rrr_stack(t_stack *p2s)
{
	ft_rra_stack(p2s);
	ft_rrb_stack(p2s);
}

/// @brief		SWAP the top two elements of the stack A and B
/// @param p2s	Pointer to the stacks
void ft_ss_stack(t_stack *p2s)
{
	ft_sa_stack(p2s);
	ft_sb_stack(p2s);
}

void	ft_sort_stack_test(t_stack *p2s)
{
	if (!p2s->ta)
		return ;

	printf("*sort list*\n");
	ft_browse_stack(p2s, 0);
	ft_browse_stack(p2s, 1);
	printf("*\n");
	ft_sa_stack(p2s);
	ft_pb_stack(p2s);
	ft_pb_stack(p2s);
	ft_pb_stack(p2s);
	ft_sa_stack(p2s);
	ft_pa_stack(p2s);
	ft_pa_stack(p2s);
	ft_pa_stack(p2s);
	printf("*sort result*\n");
	ft_browse_stack(p2s, 0);
	ft_browse_stack(p2s, 1);
	printf("*\n");

	return ;
}

void	ft_inital_stack_test(t_stack *p2a)
{
	if (!p2a->ta)
		return ;

	printf("*test list*\n");
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* ra *\n");
	ft_ra_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* ra *\n");
	ft_ra_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("*rra *\n");
	ft_rra_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("*rra *\n");
	ft_rra_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* sa *\n");
	ft_sa_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* sa *\n");
	ft_sa_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pb *\n");
	ft_pb_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pb *\n");
	ft_pb_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* sb *\n");
	ft_sb_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* sb *\n");
	ft_sb_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pb *\n");
	ft_pb_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pa *\n");
	ft_pa_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pa *\n");
	ft_pa_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pa *\n");
	ft_pa_stack(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	return ;
}

int	main(int ac, char **av)
{
	t_stack	*p2a;
	int mydebug;

	if (ac > 2)
		mydebug = 0;
	else
		mydebug = 1;
	if (_DEBUG || mydebug)
	{
		printf("\n*** DEBUG MODE ***\n");
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
		p2a = ft_generate_list(av, ac);
		if (_DEBUG)
			ft_inital_stack_test(p2a);
		ft_sort_stack_test(p2a);
	}

	if (_DEBUG)
		write(1, "Hello World!\n", 13);

	return (0);
}