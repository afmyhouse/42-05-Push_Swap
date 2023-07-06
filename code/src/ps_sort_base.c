/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:40:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/06 18:06:37 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			SORTS the 3 elements of the any stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to sort
void	ft_sort_3(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if (h->size_a == 3)
			ft_sort_3a(h);
		else if (h->size_a == 2)
		{
			if (h->ta->data > h->ta->n->data)
				ft_sx(h, 'a', _PRINT);
		}
	}
	else if (stack == 'b')
	{
		if (h->size_b == 3)
			ft_sort_3b(h);
		else if (h->size_b == 2)
		{
			if (h->tb->data < h->tb->n->data)
				ft_sx(h, 'b', _PRINT);
		}
	}
}

/// @brief			SORT ASCENDING the 3 nodes, A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_3a(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->ta->data > h->ta->n->data)
		{
			if (h->ta->data < h->ta->p->data)
				swap = !ft_sx(h, 'a', _PRINT);
			if (h->ta->data > h->ta->p->data)
				swap = !ft_rx(h, 'a');
		}
		if ((h->ta->data < h->ta->n->data) && (h->ta->n->data > h->ta->p->data))
			swap = !ft_rrx(h, 'a');
	}
}

/// @brief			SORT DESCENDING the 3 nodes, B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_3b(t_stack *h)
{
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		if (h->tb->data < h->tb->n->data)
		{
			if (h->tb->data > h->tb->p->data)
				swap = ft_sx(h, 'b', _PRINT);
			if (h->tb->data < h->tb->p->data)
				swap = ft_rx(h, 'b');
		}
		if ((h->tb->data > h->tb->n->data) && (h->tb->n->data < h->tb->p->data))
			swap = !ft_rrx(h, 'b');
	}
}

/// @brief 			SORTS the 5 elements of the any stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_short(t_stack *h)
{
	t_elem	*cur;
	int		i;
	char	teste1;
	char	teste2;
	char	teste3;
	i = 0;
	cur = h->ta;
	while (!ft_check_sort(h))
	{
		i = 0;
		cur = h->ta;
		printf("%scur->data = %d%s\n", YLW, cur->data, WTH);
		ft_browse_stacks(h);
		while (i < h->size_a)
		{
			printf("%si = %i\n", BLU, i);
			printf("cur->data = %d\n", cur->data);
			printf("cur->n->data = %d%s\n", cur->n->data, WTH);
			if (cur->data > cur->n->data && cur->data != h->max_a && cur->n->data != h->min_a)
				break ;
			//if ((cur->data < cur->n->data) && (cur->data == h->min_a && cur->n->data == h->max_a))
			//	break ;
			cur = cur->n;
			i++;
		}
		printf("%si = %i | cur->data = %d%s\n", RED, i, cur->data, WTH);
		ft_browse_stacks(h);
		//i = i % h->size_a;
		if (i != 0)
		{
			printf("aqui!!\n");
			if (i <= (h->size_a / 2 - h->size_a % 2 && i > 0))
				ft_rx(h, 'a');
			if (i > (h->size_a / 2 - h->size_a % 2))
				ft_rrx(h, 'a');
//			else if (i <= (h->size_a / 2 - h->size_a % 2 && i > 0))
//				ft_rx(h, 'a');
			// if (i = h->size_a)
			// 	while (cur->data != h->min_a)
			// 		cur=cur->n;
			// ;

		}
		printf("head = %d\n", h->ta->data);
		printf("head->n = %d\n", h->ta->n->data);
		teste1 = h->ta->data > h->ta->n->data;
		teste2 = h->ta->data != h->max_a || h->ta->n->data != h->min_a;
		teste3 = h->ta->data == h->min_a || h->ta->n->data == h->max_a;
		printf("teste1  = %d (data > n->data)\n", teste1);
		printf("teste2  = %d (data!= max || n->data !=min)\n", teste2);
		printf("teste3  = %d (data== min || n->data !=max)\n", teste3);
		//if ((h->ta->data > h->ta->n->data) && \
		//(h->ta->data != h->max_a || h->ta->n->data != h->min_a))
		if ((teste1 && teste2)) //|| (!teste1 && teste3))
			ft_sx(h, 'a', _PRINT);
		if /*((teste1 && teste2) ||*/((!teste1 && teste3))
		{
			ft_sx(h, 'a', _PRINT);
			ft_rx(h, 'a');
		}

		ft_browse_stacks(h);
		sleep(1);
		i = 0;
		cur = h->ta;
	}
	return ;
}

/// @brief 			Inializes B stack with the up to 3 elements of A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_start_stack_b(t_stack *h)
{
	int	i;

	i = 3;
	while (h->size_a > 3 && i--)
		ft_px(h, 'b');
	ft_sort_3(h, 'b');
}

