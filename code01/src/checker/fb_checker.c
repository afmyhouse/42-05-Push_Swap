/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/13 14:05:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 		STARTS THE PROGRAM
/// @param ac	args count
/// @param av	args array (expected a string o ints)
/// @return		SUCCESS - no errors, ERROR - otherwise
int	main(int ac, char **av)
{
	t_stack	*h;
	char	**array;
	int		len;
	int		i;

	array = ft_args_build(ac - 1, ++av);
	if (!array)
		return (0);
	if (array == (char **)*(av))
		len = ac - 1;
	else
		len = ft_array_len(array);
	if (ft_args_check(len, array))
		return (ft_error());
	h = ft_stack_init(len, array);
	if (array != av)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
	ft_browse_stacks(h);
	if (check_machine(h) == SUCCESS)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_browse_stacks(h);
	if (h->size_b)
		ft_stack_free_b(h);
	ft_stack_free(h);
	return (SUCCESS);
}

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int	check_machine(t_stack *h)
{
	char	*line;

	if (ft_sort_check(h))
		return (SUCCESS);
	else
	{
		line = get_next_line(0);
		while (line)
		{
			//printf("*%s",line);
			if (check_mover(h, line) == ERROR)
				return (ERROR);
			if (line)
				ft_free_str(&line);
			line = get_next_line(0);
		}
		// if (line)
		// 	ft_free_str(&line);
		if (h->size_b || !ft_sort_check(h))
			return (ERROR);
		else if (ft_sort_check(h))
			return (SUCCESS);
	}
	return (SUCCESS);
}

int	check_mover(t_stack *h, char *m)
{

	if (m[0] == 's' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		ft_sx(h, m[1], 0);
	else if (m[0] == 's' && m[1] == 's' && m[2] == '\n')
		ft_ss(h, 0);
	else if (m[0] == 'p' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		ft_px(h, m[1], 0);
	else if (m[0] == 'r' && (m[1] == 'a' || m[1] == 'b') && m[2] == '\n')
		ft_rx(h, m[1], 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == '\n')
		ft_rr(h, 0);
	else if (m[0] == 'r' && m[1] == 'r' && (m[2] == 'a' || m[2] == 'b') \
	&& m[3] == '\n')
		ft_rrx(h, m[2], 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == 'r' && m[3] == '\n')
		ft_rrr(h, 0);
	else
		return (ERROR);
	return (SUCCESS);
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
void	ft_stack_free_b(t_stack *h)
{
	t_elem	*node;
	t_elem	*tmp;

	if (!h->tb)
		return ;
	node = h->tb;
	node->p->n = NULL;
	while (node)
	{
		tmp = node->n;
		node->n = 0;
		node->p = 0;
		node->cost_a = 0;
		node->cost_b = 0;
		node->data = 0;
		node->move_a = HOLD;
		node->move_b = HOLD;
		free(node);
		node = tmp;
	}
	//ft_stack_init_status(h);
	//free(h);
	return ;
}