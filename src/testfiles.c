/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testfiles.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 17:42:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 17:59:25 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		put_link(t_piles *lst)
{
	int		i;
	int		len;
	char 	*str;

	i = 0;
	len = max(lst->a_len, lst->b_len);
	ft_printf("==PILE A==PILE B==\n");
	while (i < len)
	{
		ft_printf("%5s", str = (i < lst->a_len ?
								ft_itoa(lst->pile_a[i]) : "\0"));
		ft_strdel(&str);
		ft_printf("%8s\n", str = (i < lst->b_len ?
								  ft_itoa(lst->pile_b[i]) : "\0"));
		ft_strdel(&str);
		i++;
	}
	ft_printf("cmd : %s\n", lst->cmd);
	return (1);
}

int		print_lst(t_piles *lst)
{
	while (lst)
	{
		put_link(lst);
		lst = lst->next;
	}
	return (1);
}
