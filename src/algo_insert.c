/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_insert.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 13:34:47 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 13:34:47 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*go_to(t_piles *pile, int ab, int togo)
{
	int 	*index_tab;
	int 	dir;

	dir = get_index(pile, ab, togo) <= pile->a_len / 2;
	index_tab = !ab ? pile->index_a : pile->index_b;
	while (index_tab[0] != togo)
	{
		pile = launch_cmd(pile, dir ? "ra" : "rra");
		index_tab = !ab ? pile->index_a : pile->index_b;
	}
	return (pile);
}

t_piles		*insert(t_piles *pile, int ab, int to_insert)
{
	(void)ab;
	if (to_insert >= pile->a_len - 1 || to_insert == 0)
		return (pile);
	pile = launch_cmd(pile, "pb");
	while (pile->index_a[0] < to_insert)
		pile = launch_cmd(pile, "rra");
	pile = launch_cmd(pile, "pa");
	return (pile);
}

void		algo_insert(t_piles *piles)
{
	int		i;
	int 	*index_tab;

	i = 1;
	index_tab = piles->index_a;
	while (i < piles->a_len && !check_pile_rotated(piles))
	{
		piles = go_to(piles, 0, index_tab[i]);
		piles = insert(piles, 0, index_tab[i]);
		i++;
	}
	reorder_pile(piles);
}

