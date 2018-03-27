/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: uman <uman@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 16:21:08 by uman         #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	char	*line;
	t_piles	*piles;
	t_piles	*pstart;

	piles = NULL;
	if (ac == 1)
		return (0);
	if (!init_piles(ac, av, &piles) || !check_dup(piles))
		return (error());
	pstart = piles;
	while ((get_next_line(0, &line) == 1))
	{
		if (!iscmd(line))
		{
			ft_strdel(&line);
			return (error());
		}
		piles = fill_piles(piles, &line);
		ft_strdel(&line);
	}
	launch_sort(pstart);
	free_pilelst(pstart);
	return (0);
}
