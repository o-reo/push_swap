/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttab_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 10:08:28 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 14:33:23 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, int nx, int fd)
{
	int		i;

	i = 0;
	while (tab && tab[i] && nx--)
	{
		ft_putstr_fd(tab[i], fd);
		ft_putchar_fd((int)'\n', fd);
		i++;
	}
}
