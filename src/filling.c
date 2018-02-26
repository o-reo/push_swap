/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filling.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:59:34 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 15:59:53 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int			error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

intmax_t	ft_atoi_secure(char *str)
{
	int			i;
	intmax_t	res;
	intmax_t	minflag;

	i = 0;
	minflag = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minflag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (!i)
		exit(error());
	return (minflag * res);
}

int			count_numbers(int ac, char **av)
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
				tot++;
			while ((av[i][j] && ((ft_isdigit(av[i][j])) || (av[i][j] == '-'))))
				j++;
		}
		i++;
	}
	return (tot);
}

int			init_piles(int ac, char **av, t_piles **piles)
{
	int			len;

	len = count_numbers(ac, av);
	if (ac < 1 || !(*piles = (t_piles*)malloc(sizeof(t_piles))) ||
		!((*piles)->pile_a = (int*)malloc(sizeof(int) * len)) ||
		!((*piles)->pile_b = (int*)malloc(sizeof(int) * len)))
		return (0);
	if (!avtoi(*piles, ac, av))
		return (0);
	(*piles)->b_len = 0;
	(*piles)->a_len = len;
	(*piles)->next = NULL;
	(*piles)->cmd = NULL;
	if ((*piles)->a_len < 1)
		return (0);
	return (1);
}

t_piles		*fill_piles(t_piles *piles, char **line)
{
	t_piles		*nextpile;

	if (!(nextpile = (t_piles*)malloc(sizeof(t_piles))))
		return (NULL);
	piles->next = nextpile;
	piles->cmd = ft_strdup(*line);
	nextpile->next = NULL;
	return (nextpile);
}
