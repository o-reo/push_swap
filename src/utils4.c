/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 12:27:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 12:39:56 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int 	get_index(t_piles *pile, int ab, int pos)
{
	int 	i;
	int 	*index_tab;
	int 	pile_len;

	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	i = 0;
	while (i < pile_len && index_tab[i] != pos)
		i++;
	if (i == pile_len)
		return (-1);
	return (i);
}

t_piles		*go_to(t_piles *pile, int ab, int togo)
{
	int		*index_tab;
	int		dir;

	dir = get_index(pile, ab, togo) <= pile->a_len / 2;
	index_tab = !ab ? pile->index_a : pile->index_b;
	while (index_tab[0] != togo)
	{
		pile = launch_cmd(pile, dir ? "ra" : "rra");
		index_tab = !ab ? pile->index_a : pile->index_b;
	}
	return (pile);
}