/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_century.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:47:04 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 14:30:55 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			get_dir(t_piles *pile, int med)
{
	int		way1;
	int		way2;

	way1 = 0;
	way2 = 1;
	while (way1 < pile->a_len && pile->index_a[way1] >= med)
		way1++;
	while (way2 < pile->a_len && pile->index_a[pile->a_len - way2] >= med)
		way2++;
	return (way1 > way2 ? pile->index_a[pile->a_len - way2] :
		pile->index_a[way1]);
}

void		algo_century(t_piles **pile)
{
	int		i;
	t_piles	*step;

	i = 0;
	step = *pile;
	while (i < (step->b_len + step->a_len + QS_THRESHOLD))
	{
		step = auto_split_a(step, i, i + QS_THRESHOLD);
		i += QS_THRESHOLD;
	}
	while (step->b_len > 0)
		step = pa_max(step);
}
