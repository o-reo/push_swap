/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:56:49 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/09 14:10:21 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		print_cmds(t_piles *piles)
{
	while (piles->next && piles->cmd)
	{
		ft_printf("%s\n", piles->cmd);
		piles = piles->next;
	}
}

void	pushswap_launcher(t_piles **piles)
{
	// if ((*piles)->a_len > 0 && (*piles)->a_len < 6)
		algo_bogo(piles);
	// else if ((*piles)->a_len > 0 && (*piles)->a_len < 20)
		// *piles = algo_insert(*piles);
	// else
		// *piles = algo_quicksort(*piles);
	// post_process(*piles);
}

int			main(int ac, char **av)
{
	t_piles	*piles;
	char 	**tmp;

	piles = NULL;
	if (ac < 2)
		return (0);
	tmp = av;
	if (ac > 1 && !ft_strcmp("-v", av[1]))
	{
		tmp = av + 1;
		ac--;
	}
	if (!init_piles(ac, tmp, &piles) || !check_dup(piles))
		return (error());
	pushswap_launcher(&piles);
	if (!ft_strcmp(av[1], "-v"))
		print_lst(piles);
	else if (piles->cmd && ft_strlen(piles->cmd) > 0)
		print_cmds(piles);
	free_pilelst(piles);
	return (0);
}