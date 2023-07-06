/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/05 22:10:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_issign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (TRUE);
	else
		return (FALSE);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
	|| c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

int	ft_itoa_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n && i++ >= 0)
		n /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			a_len;
	long int	ln;

	ln = n;
	a_len = ft_itoa_len(n);
	res = (char *)malloc((a_len + 1) * sizeof(char));
	if (res)
	{
		res[a_len] = '\0';
		if (!ln)
			res[0] = '0';
		if (ln < 0)
		{
			ln = -ln;
			res[0] = '-';
		}
		while (ln && a_len-- >= 0)
		{
			res[a_len] = ln % 10 + 48;
			ln /= 10;
		}
		return (res);
	}
	return (NULL);
}

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	number;

	signal = 1;
	number = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
		signal *= ft_issign(*nptr++);
	while (ft_isdigit(*nptr))
		number = number * 10 + (*nptr++ - '0');
	return (number * signal);
}

/// @brief 			Concatenate strings
/// @param s1		Destination string
/// @param s2		Source string
/// @return			The new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1)+ft_strlen(s2)+1;
	dest = malloc(sizeof(char) * len);
	//dest = ft_calloc(len, sizeof(char));
	if (!dest)
		return (NULL);
	while (*s1)
	{
		*dest++ = *s1++;
	}
	while (*s2)
	{
		*dest++ = *s2++;
	}
	*dest = '\0';
	dest -= (len - 1);
	return (dest);
}


int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}

/* ps_libft_px.c ********************************************************* */
/// @brief 		checks if a char is a decimal digit
/// @param c 	the char to check
/// @return 	1 if true 1 otherwise
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int		ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		//printf("array len : array[%i] = %s\n", i , array[i]);
		i++;
	}
	return (i);
}

size_t	ft_split_count(const char *s, char c)
{
	size_t	splits;
	int		split_new;

	splits = 0;
	split_new = 0;
	while (*s)
	{
		if (*s != c && split_new == 0)
		{
			split_new = 1;
			splits++;
		}
		else if (*s == c)
			split_new = 0;
		s++;
	}
	return (splits);
}

char	*ft_split_slice(const char *s, char c)
{
	size_t	split_len;
	char	*split;

	split_len = 0;
	while (s[split_len] && s[split_len] != c)
		split_len++;
	split = (char *)malloc((split_len + 1) * sizeof(char));
	if (!split)
	{
		free (split);
		return (NULL);
	}
	while (*s && *s != c)
		*split++ = *s++;
	*split = '\0';
	return (split - split_len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i_split;
	size_t	splits;

	if (!s)
		return (NULL);
	i_split = 0;
	splits = ft_split_count(s, c);
	array = (char **)malloc(sizeof(char *) * (splits + 1));
	if (!array)
	{
		free (array);
		return (NULL);
	}
	while (*s && i_split <= splits)
	{
		while (*s == c && *s)
			s++;
		if (*s && *s != c)
			array[i_split++] = ft_split_slice(s, c);
		while (*s && *s != c)
			s++;
	}
	array[i_split] = NULL;
	return (array);
}

/* ps_action_px.c ********************************************************* */

/// @brief 			Pull TOP element from stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	ft_px_src(t_elem **top_src)
{
	if ((*top_src)->n == (*top_src))
		(*top_src)->n = NULL;
	else
	{
		(*top_src)->p->n = (*top_src)->n;
		(*top_src)->n->p = (*top_src)->p;
	}
	return ;
}

/// @brief 			Push TOP element to stack ( A | B)
/// @param top_src	Pointer to the stack to pull from
/// @param top_dst	Pointer to the stack to push to
void	ft_px_dst(t_elem **top_src, t_elem **top_dst)
{
	if (!*top_dst)
	{
		*top_dst = *top_src;
		(*top_dst)->n = *top_dst;
		(*top_dst)->p = *top_dst;
	}
	else
	{
		(*top_src)->n = *top_dst;
		(*top_src)->p = (*top_dst)->p;
		(*top_dst)->p->n = *top_src;
		(*top_dst)->p = *top_src;
		*top_dst = *top_src;
	}
	return ;
}

/// @brief 			PUSH the top element of src stack to dst stack
/// @param top_src	Pointer to the top of the src stack
/// @param top_dst	Pointer to the top of the dst stack
void	ft_px_stack(t_elem **top_src, t_elem **top_dst)
{
	t_elem	*new_top_src;

	ft_px_src(&(*top_src));
	new_top_src = (*top_src)->n;
	ft_px_dst(&(*top_src), &(*top_dst));
	*top_src = new_top_src;
	return ;
}

/// @brief 			PUSH the top element of A stack to B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to push to ('A' | 'B')
/// @return			1 if success, 0 if fail
int		ft_px(t_stack *h, char stack)
{
	t_stack	push;

	push = *h;
	if ((!push.ta && stack == 'b') || (!push.tb && stack == 'a'))
		return (ERROR);
	if (stack == 'a' && push.tb != NULL)
	{
		ft_px_stack(&push.tb, &push.ta);
		push.size_a++;
		push.size_b--;
	}
	else if (stack == 'b' && push.ta != NULL)
	{
		ft_px_stack(&push.ta, &push.tb);
		push.size_a--;
		push.size_b++;
	}
	printf("p%c\n", stack);
	*h = push;
	ft_check_min_max(h, stack);
	return (SUCCESS);
}

/* ps_action_rrx.c ******************************************************** */
/// @brief 			ROTATION REVERSE the stack bottom element to the top
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int		ft_rrx(t_stack *h, char stack)
{
	if ((stack != 'a' && stack != 'b') || (stack == 'a' && !h->ta) \
	|| (stack == 'b' && !h->tb))
		return (ERROR);
	if (stack == 'a' && h->size_a > 1)
		h->ta = h->ta->p;
	else if (stack == 'b' && h->size_b > 1)
		h->tb = h->tb->p;
	printf("rr%c\n", stack);
	return (SUCCESS);
}

/// @brief 			ROTATION REVERSE both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int		ft_rrr(t_stack *h)
{
	if (!h->ta && !h->tb)
		return (ERROR);
	if (h->size_a > 1)
		h->ta = h->ta->p;
	if (h->size_b > 1)
		h->tb = h->tb->p;
	printf("rrr\n");
	return (SUCCESS);
}

/* ps_action_rx.c ********************************************************* */

/// @brief 			ROTATION the stack top element to the bottom
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int		ft_rx(t_stack *h, char stack)
{
	if (stack == 'a' && h->size_a > 1)
	{
		printf("r%c\n", stack);
		h->ta = h->ta->n;
		return (SUCCESS);
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		printf("r%c\n", stack);
		h->tb = h->tb->n;
		return (SUCCESS);
	}
	else
		return (ERROR);
}

/// @brief 			ROTATION FORWARD top to bottom on both stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int		ft_rr(t_stack *h)
{
	if (h->size_a > 1)
		h->ta = h->ta->n;
	if (h->size_b > 1)
		h->tb = h->tb->n;
	if (h->size_a > 1 || h->size_b > 1)
	{
		printf("rr\n");
		return (1);
	}
	return (0);
}

/* ps_action_sx.c ********************************************************* */
/// @brief 			SWAP the top two elements of the stack
/// @param swap_top	Pointer to the stack
void	ft_sx_stack(t_elem **swap_top)
{
	(*swap_top)->p->n = (*swap_top)->n;
	(*swap_top)->n->p = (*swap_top)->p;

	(*swap_top)->p = (*swap_top)->n;
	(*swap_top)->n = (*swap_top)->n->n;

	(*swap_top)->n->p->n = (*swap_top);
	(*swap_top)->n->p = (*swap_top);

	(*swap_top) = (*swap_top)->p;
	return ;
}

/// @brief 			SWAP the top two elements of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	stack to swap
int		ft_sx(t_stack *h, char stack, int print)
{
	t_stack	swap;

	swap = *h;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')))
		return (ERROR);
	else
	{
		if (stack == 'a' && swap.ta != NULL && swap.size_a > 1)
			ft_sx_stack(&swap.ta);
		if (stack == 'b' && swap.tb != NULL && swap.size_b > 1)
			ft_sx_stack(&swap.tb);
		*h = swap;
		if (print && ((stack == 'a' && swap.size_a > 1) \
		|| (stack == 'b' && swap.size_b > 1)))
			printf("s%c\n", stack);
		return (SUCCESS);
	}
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int		ft_ss(t_stack *h)
{
	ft_sx(h, 'a', _NOPRINT);
	ft_sx(h, 'b', _NOPRINT);
	printf("ss\n");
	return (1);
}

/* ps_browse.c ************************************************************** */

/// @brief			Display the stack content
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to display
void	ft_browse_stack(t_stack *h, char stack)
{
	t_elem	*top;
	t_elem	*bottom;

	if (stack == 'b' && h->tb)
	{
		top = h->tb;
		bottom = h->tb->p;
	}
	else if (stack == 'a' && h->ta)
	{
		top = h->ta;
		bottom = h->ta->p;
	}
	else
	{
		printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
	}
	while (top != bottom && top)
	{
		printf("%d ", top->data);
		top = top->n;
	}
	printf("%d\n", top->data);
	return ;
}

/// @brief 			Displays both stacks 'a' and 'b'
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_browse_stacks(t_stack *h)
{
	if (!_SHOWLIST)
		return ;
	ft_browse_stack(h, 'a');
	ft_browse_stack(h, 'b');
	return ;
}

/// @brief 			Initialize the information about the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_init_stack_status(t_stack *h)
{
	h->ta = NULL;
	h->size_a = 0;
	h->min_a = 0;
	h->max_a = 0;
	h->tb = NULL;
	h->size_b = 0;
	h->min_b = 0;
	h->max_b = 0;
	h->moves = 0;
	return ;
}

/// @brief 			Display the information about the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_display_head(t_stack *h)
{
	printf("%s",YLW);
	printf("p2s  pointer to stacks : %p\n", h);
	printf("p2s->ta = %p\n", h->ta);
	printf("p2s->size_a = %i\n", h->size_a);
	printf("p2s->min_a = %i\n", h->min_a);
	printf("p2s->max_a = %i\n\n", h->max_a);
	printf("p2s->tb = %p\n", h->tb);
	printf("p2s->size_b = %i\n", h->size_b);
	printf("p2s->min_b = %i\n", h->min_b);
	printf("p2s->max_b = %i\n\n", h->max_b);
	printf("p2s->moves = %i\n\n", h->moves);
	printf("%s",WTH);
	return ;
}

/* ps_stacker.c ************************************************************* */

/// @brief 			Check for new values of min and max after push
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack pushed
void	ft_check_min_max(t_stack *h, char stack)
{
	if (stack == 'a')
	{
		if ((h->ta->data == h->min_b || h->ta->data == h->max_b) && h->size_b)
			ft_updt_min_max(h->tb, &h->max_b, &h->min_b);
		if (h->ta->data < h->min_a)
			h->min_a = h->ta->data;
		if (h->ta->data > h->max_a)
			h->max_a = h->ta->data;
	}
	else if (stack == 'b')
	{
		if ((h->tb->data == h->min_a || h->tb->data == h->max_a) && h->size_a)
			ft_updt_min_max(h->ta, &h->max_a, &h->min_a);
		if (h->size_b == 1 && stack == 'b')
		{
			h->min_b = h->tb->data;
			h->max_b = h->tb->data;
		}
		else if (h->size_b > 1 && h->tb->data < h->min_b)
			h->min_b = h->tb->data;
		else if (h->size_b > 1 && h->tb->data > h->max_b)
			h->max_b = h->tb->data;
	}
	return ;
}

/// @brief 			UPDATE MIN and MAX values in the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param stack	Stack to update
void	ft_updt_min_max(t_elem *node, int *max, int *min)
{
	t_elem	*tmp;

	tmp = node;
	*min = tmp->data;
	*max = tmp->data;
	while (tmp->n != node)
	{
		if (tmp->data < *min)
			*min = tmp->data;
		if (tmp->data > *max)
			*max = tmp->data;
		tmp = tmp->n;
	}
	if (tmp->data < *min)
		*min = tmp->data;
	if (tmp->data > *max)
		*max = tmp->data;
	return ;
}

/// @brief 			Add fisrt element to a circular list and update head pointer
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to first element of the stack, NULL if error malloc
t_elem	*ft_stack_add_first(t_stack *h, int data)
{
	t_elem	*stack;

	stack = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	h->ta = stack;
	stack->p = h->ta;
	stack->n = h->ta;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->data = data;
	stack->move_a = HOLD;
	stack->move_b = HOLD;
	h->min_a = data;
	h->max_a = data;
	h->min_b = 0;
	h->max_b = 0;
	return (stack);
}

/// @brief 			Adds a new element to the circular stack
/// @param stack	Pointer to the stack last added element
/// @return			Pointer to the stack current element, NULL if error malloc
t_elem	*ft_stack_add_next(t_elem *stack, int data)
{
	stack->n = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	stack->n->p = stack;
	stack = stack->n;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->data = data;
	stack->move_a = HOLD;
	stack->move_b = HOLD;
	return (stack);
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_stack	*ft_generate_list(int size, char **array)
{
	int		i;
	t_elem	*node;
	t_stack	*h;

	if (!array[0])
		return (NULL);
	i = 0;
	h = malloc(sizeof(t_stack));
	if (!h)
		return (NULL);
	ft_init_stack_status(h);
	node = ft_stack_add_first(h, atoi(array[i]));
	free(array[i]);
	i++;
	while (i < size)
	{
		node = ft_stack_add_next(node, atoi(array[i]));
		free(array[i]);
		i++;
	}
	node->n = h->ta;
	h->ta->p = node;
	h->size_a = size;
	ft_updt_min_max(h->ta, &h->max_a, &h->min_a);
	return (h);
}
/* ps_mover.c *************************************************************** */

/// @brief 			MOVE boths stack together
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best		Pointer to the best element
void	ft_move_both(t_stack *h, t_elem *best)
{
	while (best->cost_a && best->cost_b)
	{
		if (best->move_a == 'F')
			ft_rr(h);
		else if (best->move_a == 'R')
			ft_rrr(h);
		best->cost_a--;
		best->cost_b--;
	}
}

/// @brief 			PUT the 'best' node on top before push it
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param best 	Pointer to the best element
void	ft_move_best2top(t_stack *h, t_elem *best)
{
	if (best->move_a == best->move_b)
		ft_move_both(h, best);
	while (best->cost_a && best->move_a == 'F')
	{
		best->cost_a--;
		ft_rx(h, 'a');
	}
	while (best->cost_a && best->move_a == 'R')
	{
		best->cost_a--;
		ft_rrx(h, 'a');
	}
	while (best->cost_b && best->move_b == 'F')
	{
		best->cost_b--;
		ft_rx(h, 'b');
	}
	while (best->cost_b && best->move_b == 'R')
	{
		best->cost_b--;
		ft_rrx(h, 'b');
	}
	return ;
}

/* ps_get_optimal_cost.c **************************************************** */

/// @brief 			SET COST as 'rr' movement of the node
/// @param node		Pointer to the node to SET COST
/// @return			SUCCESS or ERROR
int		ft_cost_rr(t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else
		node->move_a = RX;
	if (!node->cost_b)
		node->move_b = HOLD;
	else
		node->move_b = RX;
	return (SUCCESS);
}

/// @brief 			SET COST as SUM of individual cost movement of the node
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Pointer to the node to SET COST
/// @return			SUCCESS or ERROR
int		ft_cost_raw(t_stack *h, t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else if (node->cost_a > (h->size_a - node->cost_a))
	{
		node->move_a = RRX;
		node->cost_a = h->size_a - node->cost_a;
	}
	else
		node->move_a = RX;
	if (!node->cost_b)
		node->move_b = HOLD;
	else if (node->cost_b > (h->size_b - node->cost_b))
	{
		node->move_b = RRX;
		node->cost_b = h->size_b - node->cost_b;
	}
	else
		node->move_b = RX;
	return (SUCCESS);
}

/// @brief 			SET COST the best move as 'rrr' for the node
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Pointer to the node to SET COST
int		ft_cost_rrr(t_stack *h, t_elem *node)
{
	if (!node)
		return (ERROR);
	if (!node->cost_a)
		node->move_a = HOLD;
	else
	{
		node->move_a = RRX;
		node->cost_a = h->size_a - node->cost_a;
	}
	if (!node->cost_b)
		node->move_b = HOLD;
	else
	{
		node->move_b = RRX;
		node->cost_b = h->size_b - node->cost_b;
	}
	return (SUCCESS);

}

/// @brief 		COST the best move for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the node
/// @return		SUCCESS or ERROR
int		ft_cost_optimizer(t_stack *h, t_elem *node)
{
	int	raw_cost;
	int	rr_cost;
	int	rrr_cost;

	rr_cost = ft_max_int(node->cost_a, node->cost_b);
	rrr_cost = ft_max_int((h->size_a - node->cost_a) % \
	h->size_a, (h->size_b - node->cost_b) % h->size_b);
	raw_cost = ft_min_int(h->size_a - node->cost_a, node->cost_a) \
	+ ft_min_int(h->size_b - node->cost_b, node->cost_b);
	if (rr_cost < rrr_cost && rr_cost < raw_cost)
		return (ft_cost_rr(node));
	else if (rrr_cost < rr_cost && rrr_cost < raw_cost)
		return (ft_cost_rrr(h, node));
	else if (raw_cost <= rr_cost && raw_cost <= rrr_cost)
		return (ft_cost_raw(h, node));
	return (SUCCESS);
}

/// @brief 		COST OPTIMIZER for the node
/// @param h	Information regarding :
///				POINTERS to top of the STACKS A and B
///				MIN and MAX values of the STACKS A and B,
///				SIZE of the STACKS A and B, and quantity of moves
/// @param node	Pointer to the element to be cost optimized
/// @return		SUCCESS or ERROR
int		ft_cost_optimizer(t_stack *h, char stack_src)
{
	t_elem	*node;
	int		i;
	int		size;

	i = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a')
	{
		node = h->ta;
		size = h->size_a;
	}
	else if (stack_src)
	{
		node = h->tb;
		size = h->size_b;
	}
	while (i++ < size)
	{
		ft_cost_optimizer(h, node);
		node = node->n;
	}
	return (SUCCESS);
}

/* ps_get_base_cost.c ******************************************************* */

/// @brief 			Calculates the cost of push node to the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int		ft_cost_push_b(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!h || !node || !h->tb)
		return (ERROR);
	cur = h->tb;
	if (node->data > h->max_b || node->data < h->min_b)
		while (cur->data < cur->p->data && cost++ < h->size_b)
			cur = cur->n;
	else
	{
		while (cur->data != h->max_b && cost++ < h->size_b)
			cur = cur->n;
		while (++cost && cur->data > node->data && cur->n->data > node->data)
			cur = cur->n;
	}
	node->cost_b = cost % h->size_b;
	return (SUCCESS);
}

/// @brief 			Calculates the cost of push a node to the A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @param node		Current node
/// @return			Cost of the node
int		ft_cost_push_a(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;

	cost = 0;
	if (!h || !node || !h->ta)
		return (ERROR);
	cur = h->ta;
	if (node->data > h->max_a || node->data < h->min_a)
		while (cur->p->data < cur->data && cost++ < h->size_a)
			cur = cur->n;
	else
	{
		while (cur->data != h->min_a && cost++ < h->size_a)
			cur = cur->n;
		while (++cost && cur->data < node->data && cur->n->data < node->data)
			cur = cur->n;
	}
	node->cost_a = cost % h->size_a;
	return (SUCCESS);
}

/// @brief 			Initial setup to calculate the destination cost to place
///					a new node from stack source to stack destination
/// @param h		Pointer to the stack
int		ft_cost_dst(t_stack *h, char stack_src)
{
	t_elem	*cur;
	int		i;

	i = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a' && h->tb)
	{
		cur = h->ta;
		while (i++ < h->size_a)
		{
			ft_cost_push_b(h, cur);
			cur = cur->n;
		}
	}
	else if (stack_src == 'b' && h->ta)
	{
		cur = h->tb;
		while (i++ < h->size_b)
		{
			ft_cost_push_a(h, cur);
			cur = cur->n;
		}
	}
	return (SUCCESS);
}

/// @brief 			Calculates the cost of each element of the stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
int		ft_cost_src(t_stack *h, char stack_src)
{
	t_elem	*cur;
	int		i;

	i = 0;
	if (stack_src != 'a' && stack_src != 'b')
		return (ERROR);
	else if (stack_src == 'a')
	{
		cur = h->ta;
		while (i < h->size_a)
		{
			cur->cost_a = i++;
			cur = cur->n;
		}
	}
	else if (stack_src == 'b')
	{
		cur = h->tb;
		while (i < h->size_b)
		{
			cur->cost_b = i++;
			cur = cur->n;
		}
	}
	return (SUCCESS);
}

/// @brief 			GET MAX COST of any node by offset to head
/// @param cur		head of the stack
/// @param offset	offset to head
/// @return			lowest cost
int		ft_cost_min(t_elem *cur)
{
	int		max;

	if (cur->move_a == cur->move_b)
		max = ft_max_int(cur->cost_a, cur->cost_b);
	else
		max = cur->cost_a + cur->cost_b;
	return (max);
}

/* ps_get_best.c *********************************************************** */

/// @brief			Selects the lowest cost, THE BEST node to push
/// @param cur		head of stack source to select the best node
/// @param size		size of the stack source
/// @param stack_src stack source
/// @return			pointer to the best node
t_elem	*ft_get_best2x(t_elem *cur, int size, char stack_src)
{
	t_elem	*best;
	int		i;
	int		best_cost;
	int		cur_cost;

	i = 0;
	best = cur;
	while (i++ < size)
	{
		best_cost = ft_cost_min(best);
		cur_cost = ft_cost_min(cur);
		if ((cur_cost < best_cost) ||\
			(cur_cost == best_cost && (\
			(cur->data < best->data && stack_src == 'a') ||\
			(cur->data > best->data && stack_src == 'b'))))
			best = cur;
		cur = cur->n;
	}
	return (best);
}

/// @brief 			Selects the lowest cost, best, node to insert in the B stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			Pointer to the best node
t_elem	*ft_get_cost(t_stack *h, char stack_src)
{
	if (stack_src == 'a' || stack_src == 'b')
	{
		ft_cost_src(h, stack_src);
		ft_cost_dst(h, stack_src);
		ft_cost_optimizer(h, stack_src);
		if (stack_src == 'a')
			return (ft_get_best2x(h->ta, h->size_a, stack_src));
		else if (stack_src == 'b')
			return (ft_get_best2x(h->tb, h->size_b, stack_src));
	}
	return (NULL);
}

/* ps_initial_sort.c ******************************************************** */

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

/// @brief 			Check if the A stack is sorted
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
/// @return			TRUE if sorted, FASLE if not
int		ft_check_sort(t_stack *h)
{
	t_elem	*tmp;

	tmp = h->ta;
	while (tmp != h->ta->p)
	{
		if (tmp->data > tmp->n->data)
			return (FALSE);
		tmp = tmp->n;
	}
	return (TRUE);
}

/// @brief 			PUSH back all of nodes from B to A stack
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_final(t_stack *h)
{
	t_elem	*cur;
	int		cost;
	int		mid;

	cost = 0;
	mid = h->size_a / 2 + h->size_a % 2;
	cur = h->ta;
	while (cur->data != h->min_a && ++cost)
		cur = cur->n;
	cost = cost % h->size_a;
	if (!cost)
		return ;
	else if (cost > (mid - h->size_a % 2))
	{
		while (h->ta->data != h->min_a)
			ft_rrx(h, 'a');
	}
	else
	{
		while (h->ta->data != h->min_a)
			ft_rx(h, 'a');
	}
	return ;
}

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
	int swap;

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

void	ft_sort_short(t_stack *h)
{
	t_elem	*cur;
	int		i;

	i = 0;
	cur = h->ta;
	//ft_browse_stacks(h);
	// while (cur->data != h->min_a && ++i)
	// 	cur = cur->n;
	// if (cur->n->data == h->max_a)
	// {
	// 	if (i > h->size_a / 2 - h->size_a % 2)
	// 		while (h->ta->data != h->min_a)
	// 			ft_rrx(h, 'a');
	// 	else
	// 		while (h->ta->data != h->min_a)
	// 			ft_rx(h, 'a');
	// 	ft_sx(h, 'a', _PRINT);
	// }
	while (!ft_check_sort(h))
	{
		i = 0;
		cur = h->ta;
		while (i < h->size_a)
		{
			if (cur->data > cur->n->data  && (cur->data != h->max_a || cur->n->data != h->min_a))
				break ;
			if (cur->p->data > cur->data  && (cur->p->data != h->max_a || cur->data != h->min_a))
			{
				i = h->size_a - 1;
				break ;
			}
			cur = cur->n;
			i++;
		}
		if (i < h->size_a)
		{
			if (i > h->size_a / 2 - h->size_a % 2)
			{
				i = h->size_a - i;
				while (i--)
					ft_rrx(h, 'a');
			}
			else
				while (i--)
					ft_rx(h, 'a');
			if (h->ta->data > h->ta->n->data)
				ft_sx(h, 'a', _PRINT);
		}
		else
		{
			i = 0;
			cur = h->ta;
			while (cur->data != h->min_a)
			{
				i++;
				cur = cur->n;
			}
			if (i > h->size_a / 2 - h->size_a % 2)
			{
				i = h->size_a - i;
				while (i--)
					ft_rrx(h, 'a');
			}
			else
				while (i--)
					ft_rx(h, 'a');
		}
		//ft_browse_stacks(h);
		cur = h->ta;
	}
	return ;
}


void	ft_sort_2_b(t_stack *h)
{
	t_elem	*best;

	while (h->size_a > 3)
	{
		best = ft_get_cost(h, 'a');
		if (best->cost_a || best->cost_b)
			ft_move_best2top(h, best);
		ft_px(h, 'b');
	}
	return ;
}

void	ft_sort_2_a(t_stack *h)
{
	t_elem	*best;

	while (h->size_b)
	{
		best = ft_get_cost(h, 'b');
		if (best->cost_a || best->cost_b)
			ft_move_best2top(h, best);
		ft_px(h, 'a');
	}
	return ;
}

/// @brief			Head function of the 'push swap' function
/// @param h		Information regarding :
///					POINTERS to top of the STACKS A and B
///					MIN and MAX values of the STACKS A and B,
///					SIZE of the STACKS A and B, and quantity of moves
void	ft_sort_machine(t_stack *h)
{
	if (ft_check_sort(h))
		return ;
	if (h->size_a <= 3)
		ft_sort_3(h, 'a');
	else if (h->size_a <= 7)
		ft_sort_short(h);
	else
	{
		ft_start_stack_b(h);
		ft_sort_2_b(h);
		ft_sort_3(h, 'a');
		ft_sort_2_a(h);
		ft_sort_final(h);
	}
	return ;
}

int		ft_args_check_norepeat(char **array, int len)
{
	int		i;
	int		j;
	int		cmp;

	i = 0;

	while (i < len)
	{
		j = i + 1;
		cmp = atoi(array[i]);
		while (j < len)
		{
			if (cmp == atoi(array[j]))
			{
				printf("check args repeat\n");
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int		ft_args_check_void(char **array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!array[i][0])
		{
			printf("check args void\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int		ft_args_check_isnum(char **array, int len)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (array[i][j])
		{
			c = array[i][j];
			if (!ft_isdigit(c) && c != ' ' && !ft_issign(c))
			{
				printf("check args : not int\n");
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int		ft_args_check_limits(char **array, int len)
{
	int		i;
	long	nb1;
	long	nb2;
	int		sign;

	i = 0;
	sign = 1;
	while (i < len)
	{
		if (array[i][0] == '-')
			sign = -1;
		nb1 = ft_atoi(array[i] + ft_strlen(array[i]) - 1);
		nb2 = (ft_atoi(array[i]) % 10) * sign;
		sign = 1;
		if (nb1 != nb2)
		{
			printf("check args : limits\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int		ft_args_check(int len, char **array)
{
	if (len <= 1)
	{
		printf("check args : len <= 1\n");
		return (ERROR);
	}
	if (ft_args_check_isnum(array, len))
		return (ERROR);
	if (ft_args_check_void(array, len))
		return (ERROR);
	if (ft_args_check_norepeat(array, len))
		return (ERROR);
	if (ft_args_check_limits(array, len))
		return (ERROR);
	return (SUCCESS);
}

char	*ft_args_build_n(int ac, char **av)
{
	int		i;
	char	*s1;
	char	*s2;
	char	*tmp;

	i = 1;
	s1 = malloc(sizeof(char) * 1);
	s2 = av[i];
	while (i < (ac))
	{
		if (i - 1)
		s1 = ft_strjoin(s1, " ");
		tmp = s1;
		s1 = ft_strjoin(s1, s2);
		s2 = av[i + 1];
		if (tmp)
			free(tmp);
		i++;
	}
	return (s1);
}

char	*ft_args_bulid_2(char **av)
{
	if (!av[1][0])
	{
		ft_error();
		printf("check args void\n");
		return (NULL);
	}
	return (av[1]);
}

char	**ft_args_build(int ac, char **av)
{
	char	*s1;
	char	**array;

	if (ac > 2)
		s1 = ft_args_build_n(ac, av);

	else if (ac == 2)
		s1 = ft_args_bulid_2(av);

	if (!s1)
		return (NULL);
	array = ft_split(s1, ' ');
	if (s1 != av[1])
	{
		free(s1);
	}
	return (array);
}

int		main(int ac, char **av)
{
	t_stack	*h;
	char	**array;
	int		len;

	//ac = 2;
	//av[1] = " 2 1";

	if (ac >= 2)
	{
		array = ft_args_build(ac, av);
		len = ft_array_len(array);
		if (ft_args_check(len, array))
			return (ft_error());
		h = ft_generate_list(len, array);
		free(array);
		ft_sort_machine(h);
		ft_browse_stacks(h);
	}
	return (0);
}
