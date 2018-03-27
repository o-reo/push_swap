/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_quicksort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:47:04 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 17:47:04 by eruaud      ###    #+. /#+    ###.fr     */
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

int 		logbin(int n)
{
	int 	pow;

	pow = 0;
	while (n >> pow != 0)
		pow++;
	return (pow);
}

t_piles		*seq_split(t_piles *pile, int st, int end, int ab)
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
		if (index_tab[0] < med)
			pile = launch_cmd(pile, !ab ? "pb" : "pa");
		else
			pile = launch_cmd(pile, !ab ? "ra" : "rb");
		i++;
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


t_piles		*ft_qsort(t_piles *pile, int st, int end)
{
	pile = seq_split(pile, st, end, 0);
	while (end > 0)
	{
		pile = seq_split_sup(pile, st, end / 2, 1);
		end /= 2;
	}
	pile = launch_cmd(pile, "ra");
//	pile = ft_qsort(pile, 1,3);
	return (pile);
}

void		algo_quicksort(t_piles *piles)
{
//	printf("bilog is %i\n", bilog(piles->pile_a[0]));
	piles = ft_qsort(piles, 0, piles->a_len);
}
