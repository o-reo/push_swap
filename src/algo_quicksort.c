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

int 		next_push(t_piles *pile)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < pile->a_len && pile->index_a[i] >=
									(pile->a_len + pile->b_len) / 2)
		i++;
	j = 1;
	while (j < pile->a_len && pile->index_a[pile->a_len - j] >=
									(pile->a_len + pile->b_len) / 2)
		j++;
	return ((j - i) >= (pile->a_len / 2) ? i : -j);6
}

int 		check_push(t_piles *pile, int i)
{
	if (i >= 0 && i < pile->a_len)
	{
		return (pile->index_a[i] < ((pile->a_len + pile->b_len) / 2));
	}
	else if (i < 0 && -i < pile->a_len)
	{
		return (pile->index_a[pile->a_len + i] <
				((pile->a_len + pile->b_len) / 2));
	}
	else
		return (0);
}

t_piles		*pile_split(t_piles *pile)
{
	int		i;

	i = next_push(pile);
	while (check_push(pile, i))
	{
		if (i >= 0)
		{
			while (i--)
				pile = launch_cmd(pile, "rra");
		}
		else
		{
			while (i++ < 0)
				pile = launch_cmd(pile, "ra");
		}
		pile = launch_cmd(pile, "pb");
		i = next_push(pile);
	}
	return (pile);
}

void		algo_quicksort(t_piles *piles)
{
	pile_split(piles);
}