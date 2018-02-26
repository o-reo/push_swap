/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 17:51:09 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 17:51:09 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"


int		avtoi(t_piles *piles, int ac, char **av)
{
	int			i;
	int			j;
	int			tot;

	i = 1;
	tot = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if ((av[i][j] && ((ft_isdigit(av[i][j])) || (av[i][j] == '-'))))
			{
				piles->pile_a[tot] = ft_atoi_secure(av[i] + j);
				tot++;
			}
			while ((av[i][j] && ((ft_isdigit(av[i][j])) || (av[i][j] == '-'))))
				j++;

		}
		i++;
	}
	return (1);
}
