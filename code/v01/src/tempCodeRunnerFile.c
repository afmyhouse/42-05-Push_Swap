void	ft_push_a(t_stack *p2s)
{
	t_stack	*swap;

	swap = p2s;

	if(!swap->tb)
		return ;

	swap->ta = swap->tb;

	if(swap->tb->nb == swap->tb)
		swap->tb = NULL;
	else
	{
		swap->tb = swap->tb->nb;
		swap->tb->pb = swap->bb;
		swap->bb->nb = swap->tb;
	}
	if(!p2s->ta)
	{
		p2s->ta = swap->ta;
		p2s->ta->na = p2s->ta;
		p2s->ta->pa = p2s->ta;
		p2s->ba = p2s->ta;
	}
	else
	{
		swap->ta->na = p2s->ta;
		swap->ta->pa = p2s->ba;
		p2s->ba->na = swap->ta;
		p2s->ta->pa = swap->ta;
		p2s->ta = swap->ta;
	}

}