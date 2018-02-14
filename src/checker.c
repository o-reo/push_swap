/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: uman <uman@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 16:21:08 by uman         #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 16:35:47 by uman        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		error()
{
	write(2, "Error\n", 6);
	return (0);
}

/*
 *	piles chained list contains the piles after each command and the current
 *	piles.
*/

int		launch_sort(t_piles *pilelst)
{
	(void)pilelst;
	return (0);
}

t_piles	*fill_piles(t_piles *piles, char *cmd)
{
	(void)cmd;
	return(piles);
}

int		main(int ac, char **av)
{
	char	*line;
	int		i;
	t_piles	*piles;
	t_piles	*pstart;

	if(ac < 1 || !(piles = (t_piles*)malloc(sizeof(t_piles))) ||
			!(piles->pile_a = (int*)malloc(sizeof(int) * (ac - 1))))
		return (error());
	pstart = piles;
	i = 0;
	while (i < (ac - 1))
	{
		piles->pile_a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	piles->a_len = ac - 1;
	piles->b_len = 0;
	while (get_next_line(0, &line) && line[0])
	{
		if (!iscmd(line))
			return (error());
		piles = fill_piles(piles, line);
	}
	return (launch_sort(pstart));
}