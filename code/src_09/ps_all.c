/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:12:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/06/30 01:05:11 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/// @brief 			TEST several action on the stacks`
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
	printf("splits = %zu\n", splits);
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
	if (_SHOWFUNCTION)
		printf("void %sft_px_src%s(t_elem **top_src = %s%p%s)\n"\
		, YLW, WTH, BLU, (*top_src), WTH);
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
	if (_SHOWFUNCTION)
		printf("void %sft_px_dst%s(t_elem **top_dst = %s%p%s)\n"\
		, YLW, WTH, BLU, (*top_dst), WTH);
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

	if (_SHOWFUNCTION)
		printf("void %sft_px_stack%s(t_elem **top_src = %s%p%s,\
		 t_elem **top_dst = %s%p%s)\n"\
		, YLW, WTH, BLU, (*top_src), WTH, BLU, (*top_dst), WTH);

	ft_px_src(&(*top_src));
	new_top_src = (*top_src)->n;
	ft_px_dst(&(*top_src), &(*top_dst));
	*top_src = new_top_src;
	return ;
}

/// @brief 			PUSH the top element of A stack to B stack
/// @param h		Pointer to the stacks
/// @param stack	stack to push to ('A' | 'B')
/// @return			1 if success, 0 if fail
int		ft_px(t_stack *h, char stack)
{
	t_stack	push;

	if (_SHOWFUNCTION)
		printf("void %sft_px%s(t_stack *h = (ta : %s%p%s)(tb : %s%p%s),\
		 char stack : %s%c%s)\n"\
		, YLW, WTH, BLU, h->ta, WTH, BLU, h->tb, WTH, BLU, stack, WTH);

	push = *h;
	if ((!push.ta && stack == 'b') || (!push.tb && stack == 'a'))
	{
		if (_DEBUG)
			printf("p%c error : stack empty\n", stack);
		return (0);
	}
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
	h->moves++;
	printf("%smoves = %d%s\n", YLW, h->moves, WTH);
	return (1);
}

/* ps_action_rrx.c ******************************************************** */
/// @brief 			ROTATION REVERSE the stack bottom element to the top
/// @param p2s		Pointer to the stack
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int		ft_rrx(t_stack *h, char stack)
{
	if (_SHOWFUNCTION)
		printf("void %sft_rrx%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s)"\
		" char stack : %s%c%s)\n"\
		, YLW, WTH, BLU, h->ta, WTH, BLU, h->tb, WTH, BLU, stack, WTH);
	if (stack == 'a' && h->size_a > 1)
	{
		write(1, "rra\n", 4);
		h->ta = h->ta->p;
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		write(1, "rrb\n", 4);
		h->tb = h->tb->p;
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
	}
	else
		return (0);
}

/// @brief 			ROTATION REVERSE both stack A and B
/// @param p2s		Pointer to the stacks
int		ft_rrr(t_stack *h)
{

	if (_SHOWFUNCTION)
		printf("void %sft_rrr%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n"\
		, YLW, WTH, PPL, h->ta, WTH, PPL, h->tb, WTH);
	if (h->size_a > 1)
		h->ta = h->ta->p;
	if (h->size_b > 1)
		h->tb = h->tb->p;
	if (h->size_a > 1 || h->size_b > 1)
	{
		write(1, "rrr\n", 4);
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
	}
	return (1);
}

/* ps_action_rx.c ********************************************************* */
/// @brief 			ROTATION the stack top element to the bottom
/// @param h		Pointer to the stack
/// @param stack	stack to rotate ('A' | 'B')
/// @return			1 if success, 0 if fail
int		ft_rx(t_stack *h, char stack)
{
	if (_SHOWFUNCTION)
		printf("void %sft_rx%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s)"\
		" char stack : %s%c%s)\n"\
		, YLW, WTH, BLU, h->ta, WTH, BLU, h->tb, WTH, BLU, stack, WTH);
	if (stack == 'a' && h->size_a > 1)
	{
		write(1, "ra\n", 3);
		h->ta = h->ta->n;
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
		//return (ft_ra(p2s));
	}
	else if (stack == 'b' && h->size_b > 1)
	{
		write(1, "rb\n", 3);
		h->tb = h->tb->n;
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
		//return (ft_rb(p2s));
	}
	else
		return (0);
}

/// @brief 			ROTATION FORWARD top to bottom on both stack A and B
/// @param p2s		Pointer to the stacks
int		ft_rr(t_stack *h)
{
	if (_SHOWFUNCTION)
		printf("void %sft_rr%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n"\
		, YLW, WTH, PPL, h->ta, WTH, PPL, h->tb, WTH);
	if (h->size_a > 1)
		h->ta = h->ta->n;
	if (h->size_b > 1)
		h->tb = h->tb->n;
	if (h->size_a > 1 || h->size_b > 1)
	{
		write(1, "rr\n", 3);
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
	}
	return (0);
}

/* ps_action_sx.c ********************************************************* */
/// @brief 			SWAP the top two elements of the stack
/// @param swap_top	Pointer to the stack
void	ft_sx_stack(t_elem **swap_top)
{
	if(_SHOWFUNCTION)
		printf("void %sft_sx_stack%s(t_elem **swap_top = %s%p%s)\n"\
		, YLW, WTH, RED, (*swap_top), WTH);
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
/// @param p2s		Pointer to the stack
/// @param stack	stack to swap
int	ft_sx(t_stack *h, char stack, int print)
{
	t_stack	swap;

	if (_SHOWFUNCTION)
		printf("void %sft_sx%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s)\
		, char stack : %s%c%s, int print = %i)\n", YLW, WTH, RED, h->ta, \
		WTH, RED, h->tb, WTH, RED, stack, WTH, print);

	swap = *h;
	if (((!swap.ta && stack == 'a') || (!swap.tb && stack == 'b')) && _DEBUG)
		return (0);
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
		h->moves++;
		printf("%smoves = %d%s\n", YLW, h->moves, WTH);
		return (1);
	}
}

/// @brief			SWAP the top two elements of the stack A and B
/// @param p2s		Pointer to the stacks
int	ft_ss(t_stack *p2s)
{
	if (_SHOWFUNCTION)
		printf("void %sft_ss%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n"\
		, YLW, WTH, RED, p2s->ta, WTH, RED, p2s->tb, WTH);
	ft_sx(p2s, 'a', _NOPRINT);
	ft_sx(p2s, 'b', _NOPRINT);
	write(1, "ss\n", 3);
	return (1);
}

/// @brief			Display the stack content
/// @param p2s		Pointer to the stack head (top of the stack)
/// @param stack	Stack to display
void	ft_browse_stack(t_stack *p2s, char stack)
{
	if(_SHOWFUNCTION)
		printf("void %sft_browse_stack%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s), char stack : %s%c%s)\n",YLW,WTH, BLU,p2s->ta,WTH, BLU,p2s->tb,WTH, BLU,stack,WTH);
	t_elem	*top;
	t_elem	*bottom;
	if (!_SHOWLIST)
		return ;
	if (stack == 'b' && p2s->tb)
	{
		top = p2s->tb;
		bottom = p2s->tb->p;
	}
	else if (stack == 'a' && p2s->ta)
	{
		top = p2s->ta;
		bottom = p2s->ta->p;
	}
	else
	{
		if (_DEBUG)
			printf("%sStack %c: is empty, %s\n", GRN, stack, WTH);
		return ;
	}
	if (_DEBUG && stack == 'a')
	{
		printf("%sStack %c: %s", BLU, stack, WTH);
	}
	else if (_DEBUG && stack == 'b')
	{
		printf("%sStack %c: %s", PPL, stack, WTH);
	}
	while (top != bottom && top)
	{
		printf("%d ", top->data);
		top = top->n;
	}
	printf("%d\n", top->data);
	return ;
}

/* ps_browse.c ********************************************************* */
/// @brief 			Displays both stacks 'a' and 'b'
/// @param p2s		Pointer to the stacks head (top of the stack)
void	ft_browse_stacks(t_stack *p2s)
{
	if(_SHOWFUNCTION)
		printf("void %sft_browse_stacks%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n",YLW,WTH, YLW, p2s->ta, WTH, YLW, p2s->tb, WTH);
	if (!_SHOWLIST)
		return ;
	ft_browse_stack(p2s, 'a');
	ft_browse_stack(p2s, 'b');

	return ;
}

/* ps_debug.c *************************************************************** */
/// @brief 			TEST several action on the stacks
/// @param p2s		Pointer to the stacks
void	ft_sort_stack_test(t_stack *p2s)
{
	if(_SHOWFUNCTION)
	{
		printf("\n############################################################################\n");
		printf("void %sft_sort_stack_test%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s))\n",YLW,WTH, YLW,p2s->ta,WTH,YLW, p2s->tb,WTH);
		printf("############################################################################\n\n");
	}
	if (!p2s->ta && !p2s->tb)
		return ;

	if (_DEBUG)
		printf("%s****************  unsorted list  **********************%s\n", YLW, WTH);
	ft_browse_stacks(p2s);
	ft_sx(p2s, 'a', _PRINT);
	ft_px(p2s, 'b');
	ft_px(p2s, 'b');
	ft_px(p2s, 'b');
	ft_sx(p2s, 'a', _PRINT);
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
	ft_ss(p2s);
	if (_DEBUG)
		printf("%s****************    sorted list  **********************%s\n", YLW, WTH);
	printf("*\n");
	return ;
}

/// @brief 			TEST the stack
/// @param p2s		Pointer to the top of stack A and top of stack B
void	ft_inital_stack_test(t_stack *p2s)
{
	if (_SHOWFUNCTION)
	{
		printf("void %sft_initial_stack_test%s(t_stack *p2s = (ta : %s%p%s)\
		(tb : %s%p%s))\n", YLW, WTH, GRN, p2s->ta, WTH, GRN, p2s->tb, WTH);
	}
	if (!p2s->ta)
		return ;
	printf("\n\n******** test list********\n\n");
	ft_browse_stacks(p2s);
	ft_rx(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_rx(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_rrx(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_rrx(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_sx(p2s, 'a', _PRINT);
	ft_browse_stacks(p2s);
	ft_sx(p2s, 'b', _PRINT);
	ft_browse_stacks(p2s);
	ft_px(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_rx(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_rx(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_rrx(p2s, 'b');
	ft_browse_stacks(p2s);
	printf("\n\n******** test list line ********\n\n");
	ft_rrx(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_rr(p2s);
	ft_browse_stacks(p2s);
	ft_rrr(p2s);
	ft_browse_stacks(p2s);
	printf("\n\n******** test list line ********\n\n");
	ft_sx(p2s, 'b', _PRINT);
	ft_browse_stacks(p2s);
	ft_sx(p2s, 'b', _PRINT);
	ft_browse_stacks(p2s);
	printf("\n\n******** test list line ********\n\n");
	ft_px(p2s, 'b');
	ft_browse_stacks(p2s);
	ft_px(p2s, 'a');
	ft_browse_stacks(p2s);
	printf("\n\n******** test list line ********\n\n");
	ft_ss(p2s);
	ft_browse_stacks(p2s);
	ft_px(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_px(p2s, 'a');
	ft_browse_stacks(p2s);
	ft_px(p2s, 'a');
	ft_browse_stacks(p2s);
	printf("\n\n******** test list end ********\n\n");
	return ;
}

/* ps_extras.c ************************************************************** */
/// @brief 			Print a banner with the program name and version
/// @param mydebug	Flag to print debug mode
/// @param ac		Number of arguments
void	ft_banner(int mydebug, int ac)
{
	printf("\n");
	printf("#########################################################################\n");
	printf("##                  push_swap : %s                                    ##\n", VERSION);
	if (!mydebug)
		printf("##                  real mode : args OK                                ##\n");
	else
		printf("##                 debug mode : no args                                ##\n");
	printf("##             number of args = %04i                                   ##\n", ac -1);
	printf("#########################################################################\n\n");
}

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
/// @param h		Pointer to the top of stack A and top of stack B
/// @param stack	Stack to update
void	ft_updt_min_max(t_elem *node, int *max, int *min)
{
	t_elem	*tmp;

	if (_SHOWFUNCTION)
		printf("void %sft_find_min_max%s\
		(t_stack *h = %s%p%s, int max = %s%i%s, int min = %s%i%s)\n", \
		YLW, WTH, YLW, node, WTH, YLW, *max, WTH, YLW, *max, WTH);
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
/// @param p2s		Pointer to the stack head (top of the stack)
/// @return			Pointer to first element of the stack, NULL if error malloc
t_elem	*ft_stack_add_first(t_stack *h, int data)
{
	t_elem	*stack;

	if (_SHOWFUNCTION)
		printf("t_elem \t%s*ft_stack_add_first%s(t_stack *p2s = %s%p%s)\n", \
		YLW, WTH, YLW, h, WTH);
	stack = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	h->ta = stack;
	stack->p = h->ta;
	stack->n = h->ta;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->data = data;
	stack->move_a = HALT;
	stack->move_b = HALT;
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
	if (_SHOWFUNCTION)
		printf("t_elem \t%s*ft_stack_add_next%s(t_elem *stack = %p)\n"\
		, YLW, WTH, stack);
	stack->n = malloc(sizeof(t_elem));
	if (!stack)
		return (NULL);
	stack->n->p = stack;
	stack = stack->n;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->data = data;
	stack->move_a = HALT;
	stack->move_b = HALT;
	return (stack);
}

/// @brief 		Generates a list of elements
/// @param array	Arguments
/// @param ac	Number of arguments
/// @return		Pointer to the stack
t_stack	*ft_generate_list(int size, char **array)
{
	int		i;
	t_elem	*node;
	t_stack	*h;

	if (_SHOWFUNCTION)
		printf("t_stack %s*ft_generate%s(int size = %i, char **array = %s)\n"\
		, YLW, WTH, size, array[1]);
	if (!array[0])
		return (NULL);
	i = 0;
	h = malloc(sizeof(t_stack));
	if (!h)
		return (NULL);
	node = ft_stack_add_first(h, atoi(array[i++]));
	while (i < size)
		node = ft_stack_add_next(node, atoi(array[i++]));
	node->n = h->ta;
	h->ta->p = node;
	h->size_a = size;
	ft_updt_min_max(h->ta, &h->max_a, &h->min_a);
	if (_DEBUG)
		ft_display_head(h);
	return (h);
}

/// @brief 		Find value of lowest element of a stack of elements
/// @param p2s	Pointer to the stack
/// @return		Value of lowest element
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
		printf("############################################################################\n");
		printf("void %sft_sort_machine%s(t_stack *p2s = (ta : %s%p%s)(tb : %s%p%s), int size = %i)\n",YLW,WTH, GRN,p2s->ta,WTH, GRN,p2s->tb,WTH, size);
		printf("############################################################################\n");
	}
	int lowest;
	while (p2s->ta != p2s->ta->n)
	{
		lowest = ft_get_lowest(p2s);
		while (p2s->ta->data != lowest)
			ft_rx(p2s, 'a');
		ft_px(p2s, 'b');
	}
	//ft_browse_stacks(p2s);
	while (p2s->tb)
		ft_px(p2s, 'a');
	return ;
}

/// @brief 		MOVE boths stack together
/// @param h	Pointer to the stacks
/// @param best	Pointer to the best element
void	ft_action_all(t_stack *h, t_elem *best)
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

/// @brief 		PUT the 'best' node on top before push it
/// @param p2s	Pointers to the stacks
/// @param best Pointer to the best element
void	ft_best2top(t_stack *h, t_elem *best)
{
	if (best->move_a == best->move_b)
		ft_action_all(h, best);
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

/* ps_costs.c *************************************************************** */
/// @brief 		Calculates the cost of placing node in the B stack
/// @param p2s	Pointer to the stack
/// @param node	Current node
/// @return		Cost of the node
int		ft_cost_b(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;
	int		mid;

	cost = 0;
	if (!h->tb)
	{
		node->move_b = HALT;
		return (0);
	}
	cur = h->tb;
	mid = h->size_b / 2 + h->size_b % 2;
	if (node->data > h->max_b)
		while (cur->data < h->max_b && cost++ < h->size_b)
			cur = cur->n;
	else if (node->data < h->min_b)
		while (++cost < h->size_b && cur->data > h->min_b)
			cur = cur->n;
	else
	{
		while (cur->data != h->max_b && cost++ < h->size_b)
			cur = cur->n;
		while (++cost && cur->data > node->data && cur->n->data > node->data)
			cur = cur->n;
	}
	cost = cost % h->size_b;
	if (!cost)
		node->move_b = HALT;
	else if (cost == mid && !(h->size_b % 2))
	{
		if (node->move_a == RX || node->move_a == RRX)
			node->move_b = node->move_a;
		else
			node->move_b = RX;
	}
	else if (cost < (mid))
		node->move_b = RX;
	else if (cost > (mid - (h->size_a % 2)))
	{
		node->move_b = RRX;
		cost = h->size_b - cost;
	}
	else
		node->move_b = RX;
	return (cost);
}

/// @brief 		Calculates the cost of placing node in the A stack
/// @param h	Pointer to the stack
/// @param node	Current node
/// @return		Cost of the node
int		ft_cost_a(t_stack *h, t_elem *node)
{
	int		cost;
	t_elem	*cur;
	int		mid;

	cost = 0;
	if (!h->ta)
	{
		node->move_a = HALT;
		return (0);
	}
	cur = h->ta;
	mid = h->size_a / 2 + h->size_a % 2;
	/**** BIG or SMALL****/
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
	cost = cost % h->size_a;
	if (!cost)
	{
		node->move_a = HALT;
		//cost = 0;
	}
	else if (cost == (mid) && !(h->size_a % 2))
	{
		if (node->move_b == RX || node->move_b == RRX)
			node->move_a = node->move_b;
		else
			node->move_a = RX;
	}
	else if (cost < (mid))
		node->move_a = RX;
	else if (cost > (mid - h->size_a % 2))
	{
		node->move_a = RRX;
		cost = h->size_a - cost;
	}
	else
		node->move_a = RX;
	return (cost);
}

void	ft_cost_src_save(t_elem *node, char move, int cost, char stack)
{
	if (stack == 'a')
	{
		node->move_a = move;
		node->cost_a = cost;
	}
	else if (stack == 'b')
	{
		node->move_b = move;
		node->cost_b = cost;
	}
	return ;
}

/// @brief 				Calculates the cost of removing node from stack src
/// @param node			node from stack src to calculate cost
/// @param range		range of nodes to calculate cost
/// @param stack_src
void	ft_cost_src_x(t_elem *node, int range, char stack_src)
{
	t_elem	*cur;
	int		i;

	i = range;
	while (i >= -range)
	{
		cur = ft_get_location(node, i);
		if ( i > 0)
			ft_cost_src_save(cur, 'F', i, stack_src);
		else if (i < 0)
			ft_cost_src_save(cur, 'R', -i, stack_src);
		else
			ft_cost_src_save(cur, 0, 0, stack_src);
		i--;
	}
	return ;
}

/// @brief 				Calculates the cost of each element of the stack
/// @param p2s	Pointer to the stack
int		ft_cost_src(t_stack *h, char stack)
{
	if (stack != 'a' && stack != 'b')
		return (0);
	else if (stack == 'a')
		ft_cost_src_x(h->ta, h->size_a / RANGE, stack);
	else if (stack == 'b')
		ft_cost_src_x(h->tb, h->size_b / RANGE, stack);
	return (1);
}

/// @brief 				Calculates the cost of placing a new element on stack dst
/// @param h			Pointers to head and, sizes, max and min of each stack
/// @param cur			stack src nth node to cvalculate cost
/// @param range		Range of places to calculate cost
/// @param stack_src	Stack source of the node
void	ft_cost_dst_x(t_stack *h, t_elem *node, int range, char stack_src)
{
	t_elem	*tmp;
	int		i;

	i = range;
	while (i >= -range)
	{
		tmp = ft_get_location(node, i);
		if (stack_src == 'a')
			tmp->cost_b = ft_cost_b(h, tmp);
		else if (stack_src == 'b')
			tmp->cost_a = ft_cost_a(h, tmp);
		i--;
	}
}

/// @brief 				Calculates the cost of each element of the stack
/// @param p2s			Pointer to the stack
void	ft_cost_dst(t_stack *h, char stack_src)
{
	t_elem	*cur;
	int		range;

	if (stack_src == 'a')
	{
		range = h->size_a / RANGE;
		cur = h->ta;
	}
	else if (stack_src == 'b')
	{
		range = h->size_b / RANGE;
		cur = h->tb;
	}
	else
		return ;
	ft_cost_dst_x(h, cur, range, stack_src);
	return ;
}

/// @brief 			GET MAX COST of any node by offset to head
/// @param cur		head of the stack
/// @param offset	offset to head
/// @return			lowest cost
int		ft_max_cost(t_elem *cur, int offset)
{
	int		max;

	if (offset < 0)
		while (offset++ < 0)
			cur = cur->p;
	else if (offset > 0)
		while (offset-- > 0)
			cur = cur->n;
	if (cur->move_a == cur->move_b)
	{
		if (cur->cost_b >= cur->cost_a)
			max = cur->cost_b;
		else
			max = cur->cost_a;
	}
	else
		max = cur->cost_a + cur->cost_b;
	return (max);
}

/// @brief 			GET POINTER of any node by offset to head
/// @param cur		head of the stack
/// @param offset	offset to head
/// @return			pointer to the node
t_elem	*ft_get_location(t_elem *cur, int offset)
{
	if (offset < 0)
		while (offset++ < 0)
			cur = cur->p;
	else if (offset > 0)
		while (offset-- > 0)
			cur = cur->n;
	return (cur);
}

/// @brief 			Selects the lowest cost, THE BEST, node to insert in the B stack
/// @param h		Pointer to the stack
/// @return			Pointer to the best node
t_elem	*ft_get_best(t_stack *h, char stack_src)
{
	t_elem	*cur;
	t_elem	*best;
	int		i;
	int		range;
	int 	ct1;
	int 	ct2;

	if (stack_src == 'a')
	{
		range = h->size_a / RANGE;
		cur = h->ta;
	}
	else if (stack_src == 'b')
	{
		range = h->size_b / RANGE;
		cur = h->tb;
	}
	else
		return (0);
	i = range;
	best = ft_get_location(cur, i);
	i--;
	while (i >= -range)/************ALTERADO******************/
	{
		ct1 = ft_max_cost(best, 0);
		ct2 = ft_max_cost(cur, i);
		if (ct1 > ct2 || (ct1 == ct2 && \
		best->data > ft_get_location(cur, i)->data))
			best = ft_get_location(cur, i);
		i--;
	}
	return (best);
}

/// @brief 		Selects the lowest cost, best, node to insert in the B stack
/// @param p2s	Pointer to the stack
/// @return		Pointer to the best node
t_elem	*ft_get_cost(t_stack *h, char stack)
{
	t_elem	*best;

	ft_cost_src(h, stack);
	ft_cost_dst(h, stack);
	best = ft_get_best(h, stack);
	return (best);
}

/// @brief 		Inializes B stack with the up to 3 excedent elements of A stack
/// @param h	Pointers to the stacks
void	ft_start_stack_b(t_stack *h)
{
	int	i;

	i = 3;
	while (h->size_a > 3 && i--)
		ft_px(h, 'b');
	ft_browse_stacks(h);
	//if (h->size_b <= 3)
		ft_sort_3(h, 'b');
	ft_browse_stacks(h);
}

/// @brief 		Check if the A stack is sorted
/// @param h	Pointers to the stacks
/// @return		1 if sorted, 0 if not
int		ft_check_sort(t_stack *h)
{
	t_elem	*tmp;

	tmp = h->ta;
	while (tmp != h->ta->p)
	{
		if (tmp->data > tmp->n->data)
			return (0);
		tmp = tmp->n;
	}
	return (1);
}

void	ft_sort_final(t_stack *h)
{
	t_elem *cur;
	int		cost;
	int		mid;

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


/// @brief		Head fucntion of the 'push swap' function
/// @param h	Pointers to the stacks
void	ft_sort_ai(t_stack *h)
{
	t_elem	*best;

	if (ft_check_sort(h))
		return ;
	ft_start_stack_b(h);
	while (h->size_a > 3)
	{
		best = ft_get_cost(h, 'a');
		if (best->cost_a || best->cost_b)
			ft_best2top(h, best);
		ft_px(h, 'b');
		ft_browse_stacks(h);
	}
	ft_sort_3(h, 'a');
	ft_browse_stacks(h);
	printf("**************************\n");
	while (h->size_b)
	{
		best = ft_get_cost(h, 'b');
		if (best->cost_a || best->cost_b)
			ft_best2top(h, best);
		ft_px(h, 'a');
		ft_browse_stacks(h);
	}
	ft_sort_final(h);
	return ;
}

/// @brief 			SORTS the 3 elements of the any stack
/// @param h		Pointers to the stacks
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

/// @brief		Sorts` the 3 elements of the A stack
/// @param h	Pointers to the stacks
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
				swap = ft_sx(h, 'a', _PRINT);
			if (h->ta->data > h->ta->p->data)
				swap = ft_rx(h, 'a');
		}
		if ((h->ta->data < h->ta->n->data) && (h->ta->n->data > h->ta->p->data))
			swap = ft_rrx(h, 'a');
	}
}

/// @brief		Sorts the 3 elements of the B stack
/// @param h	Pointers to the stacks
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
			swap = ft_rrx(h, 'b');
	}
}

/*void	ft_sort_5(t_stack *p2s)
{
	int lowest;
	int highest;
	int i;

	i = 0;
	lowest = ft_get_lowest(p2s);
	highest = ft_get_highest(p2s);
	while (p2s->ta->data != lowest)
	{
		ft_ra(p2s);
		i++;
	}
	ft_px(p2s, 'b');
	while (p2s->ta->data != highest)
	{
		ft_ra(p2s);
		i++;
	}
	ft_px(p2s, 'b');
	ft_sort_3(p2s, 'b');
	while (i > 0)
	{
		ft_rra(p2s);
		i--;
	}
	ft_px(p2s, 'a');
	ft_px(p2s, 'a');
}*/

int	main(int ac, char **av)
{
	t_stack	*p2s;
	int 	mydebug;
	char 	**array;
	int 	i = ft_array_len(av);
	int		j = 0;
	int 	len = 0;

	if (ac > 2)
	{
		mydebug = 0;
	}
	else
	{
		mydebug = 1;
		/**
		ac = 6;
		av[1] = "5";
		av[2] = "4";
		av[3] = "3";
		av[4] = "2";
		av[5] = "1";
		**/
		/**/ac = 2;
		/*av[1] = "5 2 7 1 6 3 9 4 8";*/
		/*av[1] = "5 4 3 2 1";*/
		av[1] = "128 79 94 183 6 40 137 96 189 131 243 26 18 113 200 176 112 237 114 109 34 10 238 226 67 171 129 165 157 61 143 77 72 15 130 160 60 54 134 29 11 106 119 224 58 152 8 95 182 101 201 158 57 216 199 125 154 64 146 179 156 1 47 48 169 167 59 215 195 181 107 219 38 231 30 117 188 175 24 155 97 221 141 4 246 23 222 245 247 110 161 148 163 103 208 138 116 214 115 44 27 33 65 121 172 122 133 55 74 239 13 196 218 248 28 86 240 68 69 145 62 56 220 88 184 250 14 126 174 16 124 45 36 98 144 49 46 206 92 151 3 90 228 37 85 63 187 229 102 12 123 82 209 205 2 170 241 162 180 227 132 244 153 207 87 166 66 142 32 19 99 249 76 225 25 20 78 52 186 178 204 100 51 50 234 84 210 127 70 235 135 147 5 177 89 168 140 39 53 242 91 7 191 159 75 71 139 198 203 81 9 194 31 185 108 80 197 41 173 212 104 105 111 73 136 236 22 164 93 35 83 42 150 120 43 118 223 217 233 17 149 192 232 211 213 230 190 21 193 202";
	/**
		ac = 10;
		av[1] = "5";
		av[2] = "2";
		av[3] = "7";
		av[4] = "1";
		av[5] = "6";
		av[6] = "3";
		av[7] = "9";
		av[8] = "4";
		av[9] = "8";**/
/*
		ac = 31;
		av[1] = "24";
		av[2] = "20";
		av[3] = "30";
		av[4] = "6";
		av[5] = "9";
		av[6] = "19";
		av[7] = "8";
		av[8] = "5";
		av[9] = "4";
		av[10] = "29";
		av[11] = "2";
		av[12] = "22";
		av[13] = "3";
		av[14] = "27";
		av[15] = "16";
		av[16] = "13";
		av[17] = "25";
		av[18] = "21";
		av[19] = "7";
		av[20] = "28";
		av[21] = "17";
		av[22] = "15";
		av[23] = "12";
		av[24] = "14";
		av[25] = "1";
		av[26] = "11";
		av[27] = "18";
		av[28] = "23";
		av[29] = "26";
		av[30] = "10";*/
	}
	if (_DEBUG)
		ft_banner(mydebug, ac);
	if (ac >= 2)
	{
		if (ac == 2)
		{


			printf("i = %d\n", i);
			while (av[1][j])
			{
				printf("av[1][%i] = %c\n", j, av[1][j]);
				j++;
			}
			array = ft_split(av[1], ' ');
			len = ft_array_len(array);
			printf("ac = %d\n", len);
			j = 0;
			while (array[j])
			{
				printf("array[%i] = %s\n", j, array[j]);
				j++;
			}
			p2s = ft_generate_list(len, array);
		}
		else
		{
			array = (char **)malloc(sizeof(char *) * (ac));
			array[ac-1] = NULL;
			while (j < (ac - 1))
			{
				array[j] = av[j+1];
				printf("array[%i] = %s\n", j, array[j]);
				j++;
			}
			len = ft_array_len(array);
			p2s = ft_generate_list(len, array);
		}
		ft_browse_stacks(p2s);
		if (_TEST)
		{
			ft_inital_stack_test(p2s);
			//ft_sort_stack_test(p2s);
		}
		//ft_sort_machine(p2s, ac - 1);
		//p2s = ft_generate_list(ac, av);
		ft_sort_ai(p2s);
		/**if (p2s->size_b == 3)
			ft_sort_3(p2s, 'b');*/
		ft_browse_stacks(p2s);
	}
	printf("Number of operations: %d\n", p2s->moves);
	if (_DEBUG)
	{
		ft_banner(mydebug, ac);
		printf("*PROUDLY PRINTED with printf by antoda-s*\n");
		write(1, "Hello World!\n", 13);
	}
	return (0);
}

/*./push_swap 86 16 6 69 93 23 12 70 52 28 47 22 40 60 24 10 95 44 65 100 3 63 51 82 71 39 17 5 33 43 53 34 89 27 37 2 32 50 98 57 1 46 21 64 8 45 18 14 13 15 25 76 79 91 9 81 85 4 11 68 59 55 7 84 73 66 87 19 92 29 67 42 90 77 80 54 38 20 35 83 62 49 30 75 31 74 58 36 26 72 56 61 99 88 94 48 96 78 41 97*/