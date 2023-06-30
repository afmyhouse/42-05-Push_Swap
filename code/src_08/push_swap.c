/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/28 22:17:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_cost_dst(t_stack *p2s)
{
	p2s->ta->p->p->cost = 3 + ft_cost_b(p2s, *(p2s->ta));
	p2s->ta->p->cost = 2 + ft_cost_b(p2s, *(p2s->ta->p));
	p2s->ta->cost = 1 + ft_cost_b(p2s, *(p2s->ta->p->p));
	p2s->ta->n->cost = 2 + ft_cost_b(p2s, *(p2s->ta->n));
	p2s->ta->n->n->cost = 2 + ft_cost_b(p2s, *(p2s->ta->n->n));
	return ;
}

int		ft_cost_b(t_stack *p2s, t_elem node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!p2s->tb)
	{
		node.move_b = HOLD_B;
		return (0);
	}
	cur = p2s->tb;
	while (cur->data > node.data)
	{
		cost++;
		cur = cur->n;
	}
	if (cost >= p2s->tb_size / 2 + 1)
	{
		node.move_b = RB;
		return (p2s->tb_size - cost);
	}
	else
	{
		node.move_b = RRB;
		return (cost);
	}
}

void	ft_cost_get(t_stack *p2s)
{
	int		cost;
	t_elem	*cur;

	ft_cost_dst(p2s);

	cost = 0;
	cur = p2s->ta;
	while (cur != p2s->ta->n)
	{
		if (tmp->data < tmp->n->data)
			cost++;
		tmp = tmp->n;
	}
	return (cost);
}

int	ft_get_lowest(t_stack *p2s)
{
	int		lowest;
	t_elem	*tmp;

	lowest = p2s->ta->data;
	tmp = p2s->ta->n;
	while (tmp != p2s->ta)
	{
		if (tmp->data < lowest)
			lowest = tmp->data;
		tmp = tmp->n;
	}
	return (lowest);
}



void	ft_sort_3t(t_stack *h)
{
	int swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->ta->data > h->ta->n->data)
		{
			if (h->ta->data < h->ta->p->data)
				swap = ft_sx(h, 'a', _PRINT);
			if (h->ta->n->data > h->ta->p->data)
				swap = ft_ra(h);
		}
		if ((h->ta->data < h->ta->n->data) && (h->ta->n->data > h->ta->p->data))
			swap = ft_rra(h);
	}
}

int	main(int ac, char **av)
{
	t_stack	*p2s;
	int mydebug;

	if (ac > 2)
	{
		mydebug = 0;
	}
	else
	{
		mydebug = 1;
		ac = 7;
		av[1] = "2";
		av[2] = "1";
		av[3] = "3";
		av[4] = "6";
		av[5] = "5";
		av[6] = "8";
	}
	if (_DEBUG)
		ft_banner(mydebug, ac);
	if (ac >= 2)
	{
		p2s = ft_generate_list(ac, av);
		ft_browse_stacks(p2s);
		if (_DEBUG)
		{
			ft_inital_stack_test(p2s);
			ft_sort_stack_test(p2s);
		}
		ft_sort_machine(p2s, ac - 1);
		//p2s = ft_generate_list(ac, av);
		if (p2s->ta_size == 3)
			ft_sort_3t(p2s);
	}

	if (_DEBUG)
	{
		ft_banner(mydebug, ac);
		ft_printf("*PROUDLY PRINTED with ft_printf by antoda-s*\n");
		write(1, "Hello World!\n", 13);
	}
	return (0);
}

/*./push_swap 86 16 6 69 93 23 12 70 52 28 47 22 40 60 24 10 95 44 65 100 3 63 51 82 71 39 17 5 33 43 53 34 89 27 37 2 32 50 98 57 1 46 21 64 8 45 18 14 13 15 25 76 79 91 9 81 85 4 11 68 59 55 7 84 73 66 87 19 92 29 67 42 90 77 80 54 38 20 35 83 62 49 30 75 31 74 58 36 26 72 56 61 99 88 94 48 96 78 41 97*/