/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/09 23:25:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//#include "../libft/libft.h"

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
			p2s->ta = stack;					// top pointer
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
	p2s->ba = stack;						// bottom pointer is the last stack element
	p2s->ba->na = p2s->ta;					// either way next pointer points to top
	p2s->ta->pa = p2s->ba;						// top prev pointer points to bottom
	return (p2s);
}

/// @brief 		Displays the stack
/// @param p2s	Pointer to the stack
void	ft_browse_stack(t_stack *p2s, int stack)
{
	t_elem	*top;
	t_elem	*bottom;

	if (stack)
	{
		top = p2s->tb;
		bottom = p2s->bb;
	}
	else
	{
		top = p2s->ta;
		bottom = p2s->ba;
	}
	if (top)
	{
		printf("Stack %c: ", stack + 'a');
		while (top != bottom  && top)
		{
			printf("%d ", top->data);
			top = (!stack) ? top->na : top->nb;
		}
		printf("%d\n", top->data);
	}
	else
		printf("Stack %c: is empty\n", stack + 'a');
}

/// @brief 		FORWARD Rotates the stack top element to the bottom
/// @param p2s	Pointer to the stack
void	ft_ra_stack(t_stack *p2s)
{
	p2s->ba = p2s->ta;
	p2s->ta = p2s->ta->na;
}

/// @brief 		REVERSE Rotates the stack bottom element to the top
/// @param p2s	Pointer to the stack
void	ft_rra_stack(t_stack *p2s)
{
	p2s->ta = p2s->ba;
	p2s->ba = p2s->ba->pa;
}

/// @brief 		SWAP the top two elements of the stack
/// @param p2s	Pointer to the stack
void	ft_sa_stack(t_stack *p2s)
{
	p2s->ba->na = p2s->ta->na;
	p2s->ta->na = p2s->ba->na->na;
	p2s->ta->pa = p2s->ba->na;
	p2s->ba->na->na = p2s->ta;
	p2s->ba->na->pa = p2s->ba;
	p2s->ta = p2s->ta->pa;
}

void	ft_push_a(t_stack *p2s)
{
	t_stack	swap;

	swap = *p2s;

	if(!swap.tb)
		return ;

	swap.ta = swap.tb;

	if (p2s->tb->nb == p2s->tb)
	{
		p2s->tb = NULL;				// if there is only one element left in the stack
		p2s->bb = NULL;
	}
	else
	{
		p2s->tb = p2s->tb->nb;
		p2s->tb->pb = p2s->bb;
		p2s->bb->nb = p2s->tb;
	}
	if(!p2s->ta)
	{
		p2s->ta = swap.ta;
		p2s->ta->na = p2s->ta;
		p2s->ta->pa = p2s->ta;
		p2s->ba = p2s->ta;
	}
	else
	{
		p2s->ba->na = swap.ta;
		p2s->ta->pa = swap.ta;
		swap.ta->na = p2s->ta;
		swap.ta->pa = p2s->ba;
		p2s->ta = swap.ta;
	}
	p2s->ta->nb = NULL;
	p2s->ta->pb = NULL;
	return ;
}

void	ft_pb_stack(t_stack *p2s)
{
	t_stack	swap;

	swap = *p2s;

	if (!swap.ta)
		return ;

	swap.tb = swap.ta;

	if (p2s->ta->na == p2s->ta)
	{
		p2s->ta = NULL;				// if there is only one element left in the stack
		p2s->ba = NULL;
	}
	else
	{
		p2s->ta = p2s->ta->na;
		p2s->ta->pa = p2s->ba;
		p2s->ba->na = p2s->ta;
	}
	if (!p2s->tb)
	{
		p2s->tb = swap.tb;
		p2s->tb->nb = p2s->tb;
		p2s->tb->pb = p2s->tb;
		p2s->bb = p2s->tb;
	}
	else
	{
		p2s->bb->nb = swap.tb;
		p2s->tb->pb = swap.tb;
		swap.tb->nb = p2s->tb;
		swap.tb->pb = p2s->bb;
		p2s->tb = swap.tb;
	}
	p2s->tb->na = NULL;
	p2s->tb->pa = NULL;
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*p2a;
	ac = 7;
	av[1] = "1";
	av[2] = "2";
	av[3] = "3";
	av[4] = "4";
	av[5] = "5";
	av[6] = "6";
	if (ac >= 2)
		p2a = ft_generate_list(av, ac);

	printf("*list*\n");
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

	printf("* pa *\n");
	ft_push_a(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	printf("* pa *\n");
	ft_push_a(p2a);
	ft_browse_stack(p2a, 0);
	ft_browse_stack(p2a, 1);
	printf("*\n");

	write(1, "Hello World!\n", 13);
	return (0);
}