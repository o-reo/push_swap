/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_bogo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 17:10:17 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 16:22:38 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"


t_piles		*rd_cmd(t_piles *pile, int i)
{	
	if (i == 0)
		pile = launch_cmd(pile, "pb");
	else if (i == 1)
		pile = launch_cmd(pile, "pa");
	else if (i == 2)
		pile = launch_cmd(pile, "ra");
	else if (i == 3)
		pile = launch_cmd(pile, "sa");
	else if (i == 4)
		pile = launch_cmd(pile, "rra");
	return (pile);
}

int		bogo(int seed, int *rand)
{
	seed = (69069 * seed + 1) % 0x100000000;
	*rand = ft_abs(seed % 5);
	return (seed);
}


int			mono_bogo(t_piles **piles, int max)
{
	int		rd;
	int		sd;
	t_piles *pi;
	int		ct;
	int		guard;

	guard = 200 * max * max;
	ct = max;
	pi = *piles;
	sd = (int)&rd;
	while (guard && (!check_pile_rotated(pi) || pi->b_len != 0))
	{
		sd = bogo(sd, &rd);
		pi = rd_cmd(pi, rd);
		if (ct < 0)
		{
			reset_piles(piles);
			pi = *piles;
			ct = max;
			guard--;
		}
		ct--;
	}

	if (!guard || (!check_pile(*piles, 0) && (*piles)->b_len != 0))
		return (0);
	reorder_pile(&pi);
	return (1);
}

void		algo_bogo(t_piles **piles)
{
	int			i;
	t_piles		*try;

	i = 1;
	try = *piles;
	while (i < 200)
	{
		if (mono_bogo(&try, i))
		{
			*piles = try;
			return ;
		}
		i++;
	}
}