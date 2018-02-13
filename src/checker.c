/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:01:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 11:17:45 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		error()
{
	write(2, "Error\n", 6);
	return (0);
}

void    print_tab(int *tab, int len)
{
    int     i;

    i = 0;
    while (i < len)
    {
        printf("%i\n", tab[i]);
        i++;
    }
}

int		main(int ac, char **av)
{
	char	*line;
    int     i;
    int     tab[ac - 1];

    i = 0;
    while (i < (ac - 1))
    {
        tab[i] = ft_atoi(av[i + 1]);
        i++;
    }
    print_tab(tab, ac - 1);
	if (ac < 1)
		return (error());
    line = NULL;
	while (get_next_line(1, &line) && line[0])
    {
        printf("%s\n", line);
    }
    return (0);
}