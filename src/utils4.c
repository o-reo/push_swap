/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 12:27:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 12:27:38 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		value_to_index(t_piles *pile, int ab, int value)
{
	int		index;
	int 	*pile_tab;
	int 	pile_len;
	int 	i;

	index = -1;
	i = 0;
	pile_tab = !ab ? pile->pile_a : pile->pile_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	while (i < pile_len)
	{
		if ((index == -1 || pile_tab[i] <= pile_tab[index]) &&
			pile_tab[i] >= value)
			index = i;
		i++;
	}
	return (index);
}

int		index_to_value(t_piles *pile, int ab, int index)
{
	int		value;
	int 	*pile_tab;
	int 	*index_tab;
	int 	pile_len;
	int 	i;

	i = 0;
	pile_tab = !ab ? pile->pile_a : pile->pile_b;
	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	value = CINT_MIN;
	while (i < pile_len && index_tab[i] != index)
		i++;
	if (index_tab[i] == index)
		value = pile_tab[i];
	return (value);
}

int 	get_index(t_piles *pile, int ab, int pos)
{
	int 	i;
	int 	*index_tab;
	int 	pile_len;

	index_tab = !ab ? pile->index_a : pile->index_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	i = 0;
	while (i < pile_len && index_tab[i] != pos)
		i++;
	if (i == pile_len)
		return (-1);
	return (i);
}