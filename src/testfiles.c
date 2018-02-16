/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testfiles.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 17:42:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:44:43 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "ft_printf.h"

int		put_link(t_piles *lst)
{
	int		i;
	int		len;

	i = 0;
	len = max(lst->a_len, lst->b_len);
	ft_printf("==PILE A==PILE B==\n");
	while (i < len)
	{
		ft_printf("%5i", i < lst->a_len ? lst->pile_a[i] : 0);
		ft_printf("%8i\n", i < lst->b_len ? lst->pile_b[i] : 0);
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
