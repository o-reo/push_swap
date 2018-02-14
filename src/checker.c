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
    int     pile_a[ac - 1];
    int     pile_b[ac - 1];
    t_piles *piles;

    if(!(piles = (t_piles*)malloc(sizeof(t_piles))))
        return (error());
    if (ac < 1)
        return (error());
    i = 0;
    while (i < (ac - 1))
    {
        pile_a[i] = ft_atoi(av[i + 1]);
        pile_b[i] = 0;
        i++;
    }
    piles->pile_a = pile_a;
    piles->pile_b = pile_b;
    print_tab(pile_a, ac - 1);
	while (get_next_line(1, &line) && line[0])
    {
        if (!iscmd(line))
            return (error());

    }
    return (0);
}