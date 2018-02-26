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

	i = 1;
	inext = 0;
	while (i < piles->a_len)
	{
		if (piles->pile_a[i] < piles->pile_a[inext] &&
				piles->pile_a[i] > piles->pile_a[lastind])
			inext  = i;
		i++;
	}
	if (i == 1)
		return (-1);
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


	printf("dst = %i, src = %i\n", dst, src);
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
		//printf("dst = %i, src = %i\n", dst, src);
		pile = launch_cmd(pile, "pb");
		dir = (dst - src) <= (pile->a_len / 2);
		while (pile->pile_a[0] != ndst)
			pile = launch_cmd(pile, dir ? "ra" : "rra");
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

	if (check_pile(piles, 0))
		return ;
	//put_link(piles);
	prev = get_min_index(piles);
	while (piles && !check_pile_rotated(piles))
	{
	//	printf("dst = %i, src = %i\n", real_index(piles, prev + 1), get_next_index(piles, prev));
		piles = swap_min(piles, real_index(piles, prev + 1), get_next_index(piles, prev));
		put_link(piles);
		prev = get_next_index(piles, prev);
	}
	reorder_pile(piles);
//	put_link(piles);
}