/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_quicksort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:47:04 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 21:54:24 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			next_push(t_piles *pile, int st, int end, int ab)
{
	int		i;
	int		j;
	int		*index_tab;
	int		pile_len;

	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	i = 0;
	while (i < pile_len && (index_tab[i] < st ||
			index_tab[i] > (st + (end - st) / 2)))
		i++;
	j = 1;
	while (j < pile_len && ((index_tab[pile_len - j]) < st ||
			index_tab[pile_len - j] > (st + (end - st) / 2)))
		j++;
	return (i > pile_len / 2 ? -j : i);
}

int			check_push(t_piles *pile, int i, int st, int end, int ab)
{
	int		*index_tab;
	int		pile_len;

	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	if (i >= 0 && i < pile_len)
	{
		return (index_tab[i] <= (st + (end - st) / 2));
	}
	else if (i < 0 && ft_abs(i) < (unsigned int)pile_len)
	{
		return (index_tab[pile_len + i] <= (st + (end - st) / 2));
	}
	else
		return (0);
}

t_piles		*pile_split(t_piles *pile, int st, int end, int ab)
{
	int		i;

	i = next_push(pile, st, end, ab);
	while (check_push(pile, i, st, end, ab))
	{
		if (i >= 0)
		{
			while (i--)
				pile = launch_cmd(pile, ab ? "rb" : "ra");
		}
		else
		{
			while (i++ < 0)
				pile = launch_cmd(pile, ab ? "rrb" : "rra");
		}
		pile = launch_cmd(pile, ab ? "pa" : "pb");
		i = next_push(pile, st, end, ab);
	}
	return (pile);
}

int 		get_median(t_piles *pile, int st, int end, int ab)
{
	int 	i;
	int 	*index_tab;
	int 	j;
	int 	ct;

	i = st;
	ct = 0;
	index_tab = !ab ? pile->index_a : pile->index_b;
	while (i < end && ct != ((end - st) / 2))
	{
		ct = 0;
		j = st;
		while (j < end)
		{
			if (index_tab[j] < index_tab[i])
				ct++;
			j++;
		}
		i++;
	}
	return (i - 1);
}

t_piles		*seq_split(t_piles *pile, int st, int end, int ab)
{
	int			i;
	int			*index_tab;
	int 		med;

	i = st;
	index_tab = !ab ? pile->index_a : pile->index_b;
	med = index_tab[get_median(pile, st, end, ab)];
	while (pile->b_len < (end / 2))
	{
		index_tab = !ab ? pile->index_a : pile->index_b;
		if (index_tab[0] < med)
			pile = launch_cmd(pile, !ab ? "pb" : "pa");
		else
			pile = launch_cmd(pile, !ab ? "ra" : "rb");
	}
	return (pile);
}

t_piles		*seq_split_sup(t_piles *pile, int st, int end)
{
	int			i;
	int 		med;

	i = st;
	med = pile->index_b[get_median(pile, st, end, 1)];
	while (i < end)
	{
		if (pile->index_b[0] >= med)
			pile = launch_cmd(pile, "pa");
		else
			pile = launch_cmd(pile, "rb");
		i++;
	}
	return (pile);
}

t_piles		*go_to_b(t_piles *pile, int togo)
{
	int		dir;
	int		index;

	index = 0;
	while (index < pile->b_len && pile->index_b[index] != togo)
		index++;
	dir = index <= pile->b_len / 2;
	index = dir ? index : pile->b_len - index;
	while (index--)
		pile = launch_cmd(pile, dir ? "rb" : "rrb");
	return (pile);
}

int 		logbin(int n)
{
	int 	pow;

	pow = 0;
	while (n >> pow != 0)
		pow++;
	return (pow);
}

t_piles		*pa_max(t_piles *pile)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (i < pile->b_len)
	{
		if (pile->index_b[i] >= max)
			max = pile->index_b[i];
		i++;
	}
	pile = go_to_b(pile, max);
	pile = launch_cmd(pile, "pa");
	return (pile);
}

t_piles		*pb_min(t_piles *pile)
{
	int		min;
	int		i;

	i = 0;
	min = CINT_MAX;
	while (i < pile->a_len)
	{
		if (pile->index_a[i] <= min)
			min = pile->index_a[i];
		i++;
	}
	pile = go_to(pile, min);
	pile = launch_cmd(pile, "pb");
	return (pile);
}

int			get_max_b(t_piles *pile)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (i < pile->b_len)
	{
		if (pile->index_b[i] > max)
			max = pile->index_b[i];
		i++;
	}
	return (max);
}

int			get_min_b(t_piles *pile)
{
	int		min;
	int		i;

	i = 0;
	min = CINT_MAX;
	while (i < pile->b_len)
	{
		if (pile->index_b[i] < min)
			min = pile->index_b[i];
		i++;
	}
	return (min);
}

t_piles		*auto_split_b(t_piles *pile, int st, int end)
{
	int			ct;

	ct = 0;
	end = end > pile->b_len + pile->a_len ? pile->b_len + pile->a_len : end;
	st = st < 0 ? 0 : st;
	while (ct < (end - st))
	{
		if (pile->index_b[0] < end && pile->index_b[0] >= st)
		{
			pile = launch_cmd(pile, "pa");
			ct++;
		}
		else
			pile = launch_cmd(pile, "rb");
	}
	return (pile);
}

t_piles		*auto_split_a(t_piles *pile, int st, int end)
{
	int			ct;

	ct = 0;
	end = end > pile->a_len + pile->b_len ? pile->a_len + pile->b_len : end;
	st = st < 0 ? 0 : st;
	while (ct < (end - st))
	{
		if (pile->index_a[0] < end && pile->index_a[0] >= st)
		{
			pile = launch_cmd(pile, "pb");
			ct++;
		}
		else
			pile = launch_cmd(pile, "ra");
	}
	return (pile);
}

t_piles		*rev_split_a(t_piles *pile, int st, int end)
{
	int			ct;

	ct = 0;
	end = end > pile->a_len + pile->b_len ? pile->a_len + pile->b_len : end;
	st = st < 0 ? 0 : st;
	while (ct < (end - st))
	{
		if (pile->index_a[0] < end && pile->index_a[0] >= st)
		{
			pile = launch_cmd(pile, "pb");
			ct++;
		}
		else
			pile = launch_cmd(pile, "rra");
	}
	return (pile);
}

int			end_ordered(t_piles *pile)
{
	int		i;

	i = 0;
	while (pile->index_a[i] != 0)
		i++;
	while (pile->index_a[real_index(pile, i + 1)] == pile->index_a[i] + 1)
		i++;
	return (pile->index_a[i]);
}

t_piles		*pb_next(t_piles *pile, int to_push)
{
	while (to_push-- > 0)
		pile = launch_cmd(pile, "pb");
	return (pile);
}

t_piles		*mini_sort(t_piles *pile, int end)
{
	int		st;

	st = get_max_b(pile);
	while (pile->b_len > 0)
		pile = pa_max(pile);
	pile = go_to(pile, st);
	pile = launch_cmd(pile, "ra");
	pile = pb_next(pile, end - st - 1);
	return (pile);
}

void		launch_qs(t_piles **pile, int end)
{
	int		st;

	st = end_ordered(*pile);
	if ((*pile)->b_len)
		*pile = seq_split_sup(*pile, st, (*pile)->b_len);
	else
		*pile = seq_split(*pile, st, (*pile)->a_len, 0);
	if ((*pile)->b_len > QS_THRESHOLD)
		launch_qs(pile, (*pile)->b_len);
	*pile = mini_sort(*pile, end);
}

void		fixed_split(t_piles **pile)
{
	int		i;

	i = 0;
	while (i < ((*pile)->b_len + (*pile)->a_len + QS_THRESHOLD))
	{
		*pile = auto_split_a(*pile, i, i + QS_THRESHOLD);
		i += QS_THRESHOLD;
	}
	while ((*pile)->b_len > 0)
		*pile = pa_max(*pile);
}

t_piles		*threshold_sort(t_piles *pile)
{
	while (pile->a_len > 0)
		pile = pb_min(pile);
	while (pile->b_len > 0)
		pile = pa_max(pile);
	return (pile);
}

void		double_split(t_piles **pile)
{
	int		i;
	int		blen;
	int		ref1;
	int		ref2;
	int		dir;

	*pile = seq_split(*pile, 0, (*pile)->a_len, 0);
	blen = (*pile)->b_len;
	i = (*pile)->b_len - QS_THRESHOLD;
	while (i >= -QS_THRESHOLD)
	{
		*pile = auto_split_b(*pile, i, i + QS_THRESHOLD);
		i -= QS_THRESHOLD;
	}
	i = (*pile)->b_len + (*pile)->a_len - QS_THRESHOLD;
	ref1 = (*pile)->index_a[0];
	ref2 = (*pile)->index_a[blen - 2];
	dir = 0;
	while (i > blen - QS_THRESHOLD)
	{
		*pile = !dir ? rev_split_a(*pile, i, i + QS_THRESHOLD) :
		auto_split_a(*pile, i, i + QS_THRESHOLD);
		*pile = !dir ? go_to(*pile, ref2) : go_to(*pile, ref1);
		i -= QS_THRESHOLD;
		dir = !dir;
	}
	*pile = threshold_sort(*pile);
}

void		algo_quicksort(t_piles **pile)
{
	t_piles	*step;

	step = *pile;
	double_split(&step);
	// fixed_split(&step);
	// launch_qs(&step, (step->a_len + step->b_len));
}
