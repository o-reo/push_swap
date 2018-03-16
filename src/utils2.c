/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:41:36 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:41:37 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	bit_swapper(int *tab, int i1, int i2)
{
	tab[i1] = tab[i1] ^ tab[i2];
	tab[i2] = tab[i2] ^ tab[i1];
	tab[i1] = tab[i1] ^ tab[i2];
}

int		check_pile_rotated(t_piles *piles)
{
	int		min;
	int		i;

	i = 1;
	min = get_min_index(piles);
	while (i < (piles->a_len))
	{
		if (piles->pile_a[real_index(piles, min + i)] <
			piles->pile_a[real_index(piles, min + i - 1)])
			return (0);
		i++;
	}
	return (1);
}

int			is_next(t_piles *pile, int a, int b)
{
	int		i;

	i = 0;
	while (i < pile->a_len)
	{
		if (pile->pile_a[i] == a && pile->pile_a[real_index(pile, i + 1)] == b)
			return (1);
		i++;
	}
	return (0);
}

t_piles		*match_bubble(t_piles *pile)
{
	int		i;
	int 	j;
	int 	*indexes;

	if (!(indexes = (int*)malloc(sizeof(int) * pile->a_len)))
		return (NULL);
	i = 0;
	while (i < pile->a_len)
	{
		j = 0;
		while (j < pile->a_len && pile->pile_a[i] != pile->index_a[j])
			j++;
		if (j < pile->a_len)
			indexes[i] = j;
		i++;
	}
	free(pile->index_a);
	pile->index_a = indexes;
	return (pile);
}

t_piles		*bubble_sort(t_piles *pile)
{
	int		i;

	i = 0;
	while (i < pile->a_len)
	{
		pile->index_a[i] = pile->pile_a[i];
		i++;
	}
	i = 1;
	while (i < pile->a_len)
	{
		if (pile->index_a[i - 1] > pile->index_a[i])
		{
			bit_swapper(pile->index_a, i - 1, i);
			i = 0;
		}
		pile->index_b[i] = 0;
		i++;
	}
	pile = match_bubble(pile);
	return (pile);
}
