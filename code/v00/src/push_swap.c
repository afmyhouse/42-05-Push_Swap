/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/08 19:28:01 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//#include "../libft/libft.h"

t_stack	*ft_generate_list(char **av, int ac)
{
	int		i;
	t_elem	*stack_a;
	t_stack	*p2a;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
		{
			stack_a = malloc(sizeof(t_elem));
			p2a = malloc(sizeof(t_stack));
			p2a->top = stack_a;
			(*stack_a).prev = NULL;
			(*stack_a).next = NULL;
		}
		else
		{
			(*stack_a).next = malloc(sizeof(t_elem));
			(*(*stack_a).next).prev = stack_a;
			stack_a = (*stack_a).next;
		}
		(*stack_a).data = atoi(av[i]);
		(*stack_a).next = NULL;
		i++;
	}
	stack_a->next = p2a->top;
	p2a->top->prev = stack_a;
	p2a->bottom = stack_a;
	return (p2a);
}

void	ft_browse_stack(t_stack *p2s)
{
	t_elem	*tmp;

	tmp = p2s->top;
	while (tmp != p2s->bottom)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);
}

void	ft_ra_stack(t_stack *p2s)
{
	p2s->bottom = p2s->top;
	p2s->top = p2s->top->next;
}

void	ft_rra_stack(t_stack *p2s)
{
	p2s->top = p2s->bottom;
	p2s->bottom = p2s->bottom->prev;
}

void	ft_sa_stack_data(t_stack *p2s)
{
	int	tmp;

	tmp = p2s->top->data;
	p2s->top->data = p2s->top->next->data;
	p2s->top->next->data = tmp;
}

void	ft_sa_stack(t_stack *p2s)
{
	p2s->bottom->next = p2s->top->next;
	p2s->top->next = p2s->bottom->next->next;
	p2s->top->prev = p2s->bottom->next;
	p2s->bottom->next->next = p2s->top;
	p2s->bottom->next->prev = p2s->bottom;
	p2s->top = p2s->top->prev;
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
	{
		p2a = ft_generate_list(av, ac);
	}
	//int first = 0;
	printf("*list*\n");
	ft_browse_stack(p2a);
	printf("*\n");
	printf("ra *list*\n");
	ft_ra_stack(p2a);
	ft_browse_stack(p2a);
	printf("*\n");
	printf("rra *list*\n");
	ft_rra_stack(p2a);
	ft_browse_stack(p2a);
	printf("*\n");
	printf("sa *list*\n");
	ft_sa_stack(p2a);
	ft_browse_stack(p2a);
	printf("*\n");
	printf("sa *list*\n");
	ft_sa_stack(p2a);
	ft_browse_stack(p2a);
	printf("*\n");
	/*while (!(first) || first && (p2a->top != p2a->bottom->next))
	{
		printf("p2a->top\t%p\n", p2a->top);
		printf("p2a->top->prev\t%p\n", p2a->top->prev);
		printf("p2a->top->next\t%p\n", p2a->top->next);
		printf("p2a->top->data\t% 14d\n\n", p2a->top->data);
		p2a->top = p2a->top->prev;
		first = 1;
	}
	printf("p2a->top \t%p\n", p2a->top);*/
	/*printf("p2a->top->prev\t%p\n", p2a->top->prev);
	printf("p2a->top->next\t%p\n", p2a->top->next);
	printf("p2a->top->data\t% 14d\n\n", p2a->top->data);
	p2a->top = p2a->top->prev;
	printf("p2a->top \t%p\n", p2a->top);*/

	write(1, "Hello World!\n", 13);
	return (0);
}