/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/17 17:19:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SORT mechanics will be tested here
/// @param p2s		Pointer to the top of stack A and top of stack B
/// @param size		Size of the list to sort
void	ft_sort_machine(t_stack *p2s, int size)
{
	if(_SHOWFUNCTION)
	{
		ft_printf("############################################################################\n");
		printf("void %sft_sort_machine%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s), int size = %i)\n",YLW,WTH, GRN,p2s->ta,WTH, GRN,p2s->tb,WTH, size);
		ft_printf("############################################################################\n");
	}
	int i;

	i = 0;
	if (_DEBUG)
		ft_printf("%s*sort machine*%s\n", YLW, WTH);
	while (i < size)
	{
		ft_px(p2s, 'b');
		i++;
	}
	ft_browse_stacks(p2s);
	//ft_sort_stack_test(p2s);
	return ;
}

void	ft_banner(int mydebug, int ac)
{
	ft_printf("\n");
	ft_printf("############################################################################\n");
	ft_printf("##                  push_swap : v06                                       ##\n");
	if (!mydebug)
	{
	ft_printf("##                  real mode : args OK                                   ##\n");
	ft_printf("##             number of args = %04i                                      ##\n", ac -1);
	}
	else
	{
	ft_printf("##                 debug mode : no args                                   ##\n");
	ft_printf("##             number of args = %04i                                      ##\n", ac -1);
	}
	ft_printf("############################################################################\n\n");
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
	ft_banner(mydebug, ac);
	if (ac >= 2)
	{
		p2s = ft_generate_list(ac, av);
		if (_DEBUG)
			ft_inital_stack_test(p2s);
		ft_sort_stack_test(p2s);
		//ft_sort_machine(p2s, ac - 1);
	}
	ft_banner(mydebug, ac);
	ft_printf("*PROUDLY PRINTED with ft_printf by antoda-s*\n");

	if (_DEBUG)
		write(1, "Hello World!\n", 13);

	return (0);
}

/*./push_swap 86 16 6 69 93 23 12 70 52 28 47 22 40 60 24 10 95 44 65 100 3 63 51 82 71 39 17 5 33 43 53 34 89 27 37 2 32 50 98 57 1 46 21 64 8 45 18 14 13 15 25 76 79 91 9 81 85 4 11 68 59 55 7 84 73 66 87 19 92 29 67 42 90 77 80 54 38 20 35 83 62 49 30 75 31 74 58 36 26 72 56 61 99 88 94 48 96 78 41 97*/