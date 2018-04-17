/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_quicksort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:47:04 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 13:13:14 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

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
//	printf("i = %i index = %i stuff = %i\n", i, index_tab[i], st + (end - st) / 2);
	j = 1;
	while (j < pile_len && ((index_tab[pile_len - j]) < st ||
			index_tab[pile_len - j] > (st + (end - st) / 2)))
		j++;
//	printf("j = %i index = %i\n", i, index_tab[pile_len - j]);
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
//		printf("%i, check %i\n", i, check_push(pile, i, st, end, ab));
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

t_piles		*seq_split_sup(t_piles *pile, int st, int end, int ab)
{
	int			i;
	int			*index_tab;
	int 		med;

	i = st;
	index_tab = !ab ? pile->index_a : pile->index_b;
	med = index_tab[get_median(pile, st, end, ab)];
	while (i < end)
	{
		index_tab = !ab ? pile->index_a : pile->index_b;
		if (index_tab[0] >= med)
			pile = launch_cmd(pile, !ab ? "pb" : "pa");
		else
			pile = launch_cmd(pile, !ab ? "ra" : "rb");
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

int			end_ordered(t_piles *pile)
{
	int		index;

	index = 0;
	while (pile->index_a[index + 1] == pile->index_a[index] + 1)
		index++;
	return (real_index(pile, index + 1));
}

t_piles		*halfsort(t_piles *pile, int end)
{
	int		current;
	int		max;

	while (pile->b_len > QS_THRESHOLD)
	{
		pile = seq_split_sup(pile, 0, end / 2, 1);
		end /= 2;
	}
	current = 0;
	while (pile->b_len > 0)
	{
		pile = pa_max(pile);
		current++;
	}
	while (current--)
		pile = launch_cmd(pile, "ra");
	max = pile->index_a[pile->a_len - 1];
	while (pile->a_len > 0 && pile->index_a[0] > max &&
	pile->index_a[0] <= (2 * max + 2))
		pile = launch_cmd(pile, "pb");
	return (pile);
}

void		algo_quicksort(t_piles **pile)
{
	int		guard;
	int		end;
	t_piles	*step;

	step = *pile;
	end = (*pile)->a_len;
	guard = 3000;
	step = seq_split(step, 0, end, 0);
	while (guard-- && (!check_pile_rotated(*pile) || (*pile)->b_len != 0))
		step = halfsort(step, end);
}