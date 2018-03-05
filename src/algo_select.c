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

	i = 0;
	next = CINT_MAX;
	inext = -1;
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
	int				dir;
	int				nsrc;
	int				ndst;
	int				i;

	i = 0;
	if (dst == src)
		return (pile);
	ndst = pile->pile_a[dst];
	nsrc = pile->pile_a[src];
	ft_printf("%d[%d] -> %d[%d]\n", nsrc, src, ndst, dst);
	dir = (int)ft_abs(src - dst) <= (pile->a_len / 2);
	ft_printf("dir %d\n", dir);
	while (pile->pile_a[!dir] != nsrc)
		pile = launch_cmd(pile, dir ? "ra" : "rra");
	pile = launch_cmd(pile, "sa");
	printf ("ecart vaut %d\n", real_index(pile, src - dst));
	while (i < real_index(pile, src - dst))
	{
		pile = launch_cmd(pile, "ra");
		pile = launch_cmd(pile, "sa");
		i++;
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
	prev = get_min_index(piles);
//	while (piles && !check_pile_rotated(piles) && i < 5)
//	{
//		printf("je met %d en position %d\n", get_next_index(piles, prev), real_index(piles, prev + 1));
		if (prev == -1)
			return ;
		piles = swap_min(piles, real_index(piles, prev + 1), get_next_index(piles, prev));
		prev = get_next_index(piles, prev);
//		put_link(piles);
		i++;
//	}
//	reorder_pile(piles);
}