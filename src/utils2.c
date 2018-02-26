/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:41:36 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:41:37 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"


int		check_pile_rotated(t_piles *piles)
{
	int		min;
	int		i;

	i = 1;
	min = get_min_index(piles);
	while(i < (piles->a_len))
	{
		if (piles->pile_a[real_index(piles, min + i)] <
			piles->pile_a[real_index(piles, min + i - 1)])
			return (0);
		i++;
	}
	return (1);
}