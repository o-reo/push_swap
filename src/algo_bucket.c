/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_bucket.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 16:17:37 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 14:16:22 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_bucket(t_piles **piles)
{
	t_piles	*step;
	int		i;

	i = 0;
	if (check_pile(*piles, 0))
		return ;
	step = *piles;
	while (i < (*piles)->a_len - 1)
	{
		step = go_to(step, 0, i);
		step = launch_cmd(step, "pb");
		i++;
	}
	while (step->b_len > 0)
		step = launch_cmd(step, "pa");
}