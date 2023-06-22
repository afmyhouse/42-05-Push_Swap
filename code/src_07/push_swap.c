/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/22 17:19:49 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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


/// @brief 			SORT mechanics will be tested here
/// @param p2s		Pointer to the top of stack A and top of stack B
/// @param size		Size of the list to sort
void	ft_sort_machine(t_stack *p2s, int size)
{
	if(_SHOWFUNCTION)
	{
		ft_printf("############################################################################\n");
		ft_printf("void %sft_sort_machine%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s), int size = %i)\n",YLW,WTH, GRN,p2s->ta,WTH, GRN,p2s->tb,WTH, size);
		ft_printf("############################################################################\n");
	}
	int lowest;
	while (p2s->ta != p2s->ta->n)
	{
		lowest = ft_get_lowest(p2s);
		while (p2s->ta->data != lowest)
			ft_ra(p2s);
		ft_px(p2s, 'b');
	}
	ft_browse_stacks(p2s);
	while (p2s->tb)
		ft_px(p2s, 'a');
	return ;
}

void	ft_sort_3(t_stack *h)
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

void	ft_banner(int mydebug, int ac)
{
	ft_printf("\n");
	ft_printf("#########################################################################\n");
	ft_printf("##                  push_swap : %s                                    ##\n", VERSION);
	if (!mydebug)
		ft_printf("##                  real mode : args OK                                ##\n");
	else
		ft_printf("##                 debug mode : no args                                ##\n");
	ft_printf("##             number of args = %04i                                   ##\n", ac -1);
	ft_printf("#########################################################################\n\n");
}

int	main(int ac, char **av)
{
	t_stack	*p2s;
	int mydebug;

	ft_printf("_DEBUG = %i\n", _DEBUG);
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
		ft_printf("*****************************************\n");
		if (p2s->ta_size == 3)
			ft_sort_3(p2s);
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