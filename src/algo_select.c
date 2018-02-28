/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_select.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 11:36:58 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 19:12:17 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			get_next_index(t_piles *piles, int lastind)
{
	int		i;
	int		inext;
	int		next;

	i = 1;
	next = piles->pile_a[0];
	inext = 0;
	while (i < piles->a_len)
	{
		if (piles->pile_a[i] < next &&
				piles->pile_a[i] > piles->pile_a[lastind])
		{
			next = piles->pile_a[i];
			inext = i;
		}
		i++;
	}
	printf("next vaut %d\n", next);
	return (inext);
}

int			real_index(t_piles *pile, int index)
{
	if (index >= pile->a_len)
		return (index - pile->a_len);
	else if (index < 0)
		return(pile->a_len - 1);
	return (index);
}

t_piles		*swap_min(t_piles *pile, int dst, int src)
{
	int		dir;
	int		nsrc;
	int		ndst;


	if (dst == src)
		return (pile);
	ndst = pile->pile_a[dst];
	nsrc = pile->pile_a[src];
	dir = src <= (pile->a_len / 2);
	while (pile->pile_a[0] != nsrc)
		pile = launch_cmd(pile, "ra");
	if (dst == real_index(pile, src + 1))
		pile = launch_cmd(pile, "sa");
	else if (dst == real_index(pile, src - 1))
	{
		pile = launch_cmd(pile, "rra");
		pile = launch_cmd(pile, "sa");
	}
	else
	{
		pile = launch_cmd(pile, "pb");
		dir = (dst - src) <= (pile->a_len / 2);
		while (pile->pile_a[0] != ndst)
			pile = launch_cmd(pile, dir ? "rra" : "ra");
		pile = launch_cmd(pile, "pa");
	}
	return (pile);
}

void		reorder_pile(t_piles *piles)
{
	int		dir;

	dir = get_min_index(piles) > (piles->a_len / 2);
	while (get_min_index(piles) != 0)
		piles = launch_cmd(piles, dir ? "rra" : "ra");
}

void		algo_select(t_piles *piles)
{
	int		prev;
	int		i;

	i = 0;
	if (check_pile(piles, 0))
		return ;
	prev = -1;
	while (piles && !check_pile_rotated(piles) && i < 5)
	{
		printf("je met %d en position %d\n", get_next_index(piles, prev), real_index(piles, prev + 1));
		prev = prev == -1 ? get_min_index(piles) : get_next_index(piles, prev);
		piles = swap_min(piles, real_index(piles, prev + 1), prev);
//		put_link(piles);
		i++;
	}
//	reorder_pile(piles);
}