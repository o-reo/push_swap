/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:56:49 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 19:11:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		print_cmds(t_piles *piles)
{
	while (piles && piles->cmd)
	{
		ft_printf("%s\n", piles->cmd);
		piles = piles->next;
	}
}

int			pushswap_launcher(t_piles *piles)
{
//	if (piles->a_len > 0 && piles->a_len < 6)
		algo_quicksort(piles);
	return (0);
}

int			main(int ac, char **av)
{
	t_piles	*piles;

	piles = NULL;
	if (ac < 2)
		return (0);
	if (!init_piles(ac, av, &piles) || !check_dup(piles))
		return (error());
	pushswap_launcher(piles);
//	print_lst(piles);
	print_cmds(piles);
	free_pilelst(piles);
	return (0);
}
