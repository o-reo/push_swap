/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_select.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 11:36:58 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:49:47 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int 		nearest(t_piles *pile, int n1, int n2)
{
	if (n1 > pile->a_len / 2)
		n1 = n1 - pile->a_len;
	if (n2 > pile->a_len / 2)
		n2 = n2 - pile->a_len;
	return (ft_abs(n1) > ft_abs(n2) ? n2 : n1);
}

t_piles		*far_swap(t_piles *pile, int dst, int src)
{
	int 	nsrc;
	int 	ndst;
	int 	dir;

	ndst = pile->pile_a[dst];
	nsrc = pile->pile_a[src];
	dir = src <= pile->a_len / 2;
	while (pile->pile_a[0] != nsrc)
		pile = launch_cmd(pile, dir ? "ra" : "rra");
	pile = launch_cmd(pile, "pb");
	dir = (src > dst && (src - dst < pile->a_len / 2)) ||
			(src < dst && (src - dst > pile->a_len / 2));
	while (pile->pile_a[0] != ndst)
		pile = launch_cmd(pile, dir ? "rra" : "ra");
	// un ra a ajoute dans certains cas, le get next index est peut etre faux
	pile = launch_cmd(pile, "pa");
	return (pile);
}

t_piles		*simple_swap(t_piles *pile, int dst, int src)
{
	int 	diff;
	int 	ndst;

	ndst = pile->pile_a[dst];
	diff = nearest(pile, dst, src);
	while (diff)
	{
		pile = launch_cmd(pile, diff < 0 ? "rra" : "ra");
		diff += 2 * (diff < 0) - 1;
	}
	if ((src > dst && pile->pile_a[0] == ndst) ||
		(dst > src && pile->pile_a[0] != ndst && dst != pile->a_len - 1))
		pile = launch_cmd(pile, "sa");
	else
	{
		pile = launch_cmd(pile, "rra");
		pile = launch_cmd(pile, "sa");
	}
	return (pile);
}

t_piles		*swap_min(t_piles *pile, int dst, int src)
{
	if (dst >= pile->a_len || src >= pile->a_len)
		return (pile);
	if (ft_abs(dst - src) == 1 ||
			((int)ft_abs(dst - src) == pile->a_len - 1))
		pile = simple_swap(pile, dst, src);
	else
		pile = far_swap(pile, dst, src);
	return (pile);
}

void		algo_select(t_piles *piles)
{
//	piles = far_swap(piles, 2 , 0);
	int		prev;

	if (check_pile(piles, 0))
		return ;
	prev = 0;
	while (piles && !check_pile_rotated(piles) &&
			get_next_index(piles, prev) != -1)
	{
		printf("prev index is %i, index %i will be put before %i\n", prev, get_index(piles, 0, prev) + 1, get_next_index(piles, prev));
		piles = swap_min(piles, get_index(piles, 0, prev) + 1, get_next_index(piles, prev));
		prev++;
	}
	reorder_pile(piles);
}