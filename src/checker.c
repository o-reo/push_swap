/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: uman <uman@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 16:21:08 by uman         #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 20:20:32 by eruaud      ###    #+. /#+    ###.fr     */
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
	return (minflag * res);
}

int			init_piles(int ac, char **av, t_piles **piles)
{
	int			i;
	intmax_t	sw;

	i = 0;
	if (ac < 1 || !(*piles = (t_piles*)malloc(sizeof(t_piles))) ||
			!((*piles)->pile_a = (int*)malloc(sizeof(int) * (ac - 1))) ||
			!((*piles)->pile_b = (int*)malloc(sizeof(int) * (ac - 1))))
		return (0);
	while (i < (ac - 1))
	{
		sw = ft_atoi_secure(av[i + 1]);
		if (sw < CINT_MIN || sw > CINT_MAX)
			return (0);
			(*piles)->pile_a[i] = sw;
		i++;
	}
	while (i--)
		(*piles)->pile_b[i] = 0;
	(*piles)->b_len = 0;
	(*piles)->a_len = ac - 1;
	(*piles)->next = NULL;
	(*piles)->cmd = NULL;
	if ((*piles)->a_len <= 1)
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

int			main(int ac, char **av)
{
	char	*line;
	t_piles	*piles;
	t_piles	*pstart;

	piles = NULL;
	if (!init_piles(ac, av, &piles))
		return (error());
	pstart = piles;
	while (get_next_line(0, &line) && line[0])
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
