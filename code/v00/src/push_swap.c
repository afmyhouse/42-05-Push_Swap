/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/05 11:59:03 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef s_list{
	s_list	*prev;
	int		data;
	s_list	*next;
}	t_list;

typedef s_stack{
	t_list	*head;
	t_list	*tail;
}	t_stack;

void	ft_generate_list(char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*head_a;
	t_list	*tail_a;
	t_list	*stack_b;
	t_list	*head_b;
	t_list	*tail_b;

	i = 1;
	while (argv[i])
	{
		stack_a = malloc(sizeof(t_list));
		stack_a->data = argv[i];
		stack_a->next = NULL;
		stack_a->prev = NULL;
		i++;
	}
}

int main (int ac, char **av)
{

	if (ac >=2)
	{
		ft_generate_list(argv);
	}
	write(1, "Hello World!\n", 13);
	return (0);
}