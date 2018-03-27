/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:06:42 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:06:42 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		reorder_pile(t_piles *piles)
{
	int		dir;

	dir = get_min_index(piles) > (piles->a_len / 2);
	while (get_min_index(piles) != 0)
		piles = launch_cmd(piles, dir ? "rra" : "ra");
}

int			get_next_index(t_piles *piles, int lastind)
{
	int 	i;

	if (lastind < piles->a_len - 1)
	{
		i = 0;
		while (i < piles->a_len)
		{
			if (piles->index_a[i] == lastind + 1)
				return (i);
			i++;
		}
	}
	return (-1);
}

int			real_index(t_piles *pile, int index)
{
	if (index >= pile->a_len)
		return (index - pile->a_len);
	else if (index < 0)
		return (pile->a_len - 1);
	return (index);
}

int		get_min_index(t_piles *piles)
{
	int		i;
	int		imin;

	i = 1;
	imin = 0;
	while (i < piles->a_len)
	{
		if (piles->index_a[i] == 0)
			imin  = i;
		i++;
	}
	return (imin);
}

t_piles		*launch_cmd(t_piles *pile, char *cmd)
{
	if (cmd)
		pile->next = fill_piles(pile, &cmd);
	else
		pile->next = NULL;
	return (exec_cmd(pile));
}