/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_bucket.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 16:17:37 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 19:07:39 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"



int		check_pile_b(t_piles *pilelst)
{
	int		i;

	i = 0;
	while (i < pilelst->b_len - 1)
	{
		if (pilelst->pile_b[i] > pilelst->pile_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_min(t_piles *piles, int imin)
{
	int		dir;
	int		i;

	i = 0;
	dir = imin <= (piles->a_len / 2);
	imin = !dir ? ft_abs(imin - piles->a_len) : imin;
	while (i < imin)
	{
		launch_cmd(piles, dir ? "ra" : "rra");
		i++;
	}
	launch_cmd(piles, "pb");
}

void	algo_bucket(t_piles **piles)
{
	int		len;

	if (check_pile(*piles, 0))
		return ;
	len =  (*piles)->a_len;
	while ((*piles)->b_len < len)
		push_min(*piles, get_min_index(*piles));
	while ((*piles)->b_len > 0)
		launch_cmd(*piles, "pa");
}