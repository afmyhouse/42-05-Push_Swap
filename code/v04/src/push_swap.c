/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/11 00:11:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
		p2s = ft_generate_list(ac, av);
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