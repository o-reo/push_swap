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

t_piles		*swap_min(t_piles *pile, int dst, int src)
{
//	int				dir;
	int				nsrc;
	int				ndst;
	int				dir1;

	if (dst == src)
		return (pile);
	ndst = pile->pile_a[dst];
	nsrc = pile->pile_a[src];
//	ft_printf("%d[%d] -> %d[%d]\n", nsrc, src, ndst, dst);
//	dir = ((int)ft_abs(src - dst)) <= (pile->a_len / 2);
	dir1 = src <= (pile->a_len / 2);
	while (pile->pile_a[!dir1] != nsrc)
		pile = launch_cmd(pile, dir1 ? "rra" : "ra");
	pile = launch_cmd(pile, "sa");
	while (!is_next(pile, nsrc, ndst))
	{
		pile = launch_cmd(pile, "ra");
		pile = launch_cmd(pile, "sa");
	}
	return (pile);
}

void		algo_select(t_piles *piles)
{
	int		prev;
	int		i;

	i = 0;
	if (check_pile(piles, 0))
		return ;
	prev = get_min_index(piles);
//	while (piles && !check_pile_rotated(piles) &&
//			get_next_index(piles, prev) != -1)
//	{
//		piles = swap_min(piles, real_index(piles, prev + 1),
//						get_next_index(piles, prev));
//		prev = get_next_index(piles, prev);
//		i++;
//	}
//	reorder_pile(piles);
}
