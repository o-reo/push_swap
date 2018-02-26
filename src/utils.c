/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 15:04:54 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	dup_piles(t_piles *dst, t_piles *src)
{
	int		i;

	if (!src)
		return ;
	if (!(dst->pile_a = malloc(sizeof(int) * (src->a_len + src->b_len))))
		return ;
	if (!(dst->pile_b = malloc(sizeof(int) * (src->a_len + src->b_len))))
		return ;
	dst->b_len = src->b_len;
	dst->a_len = src->a_len;
	i = 0;
	while (i < (dst->a_len + dst->b_len))
	{
		dst->pile_a[i] = src->pile_a[i];
		dst->pile_b[i] = src->pile_b[i];
		i++;
	}
}

void	rotate_pile(t_piles *pile, int ab, int rev)
{
	int		last;
	int		*pile_tab;
	int		pile_len;
	int		i;

	if ((!ab && !pile->a_len) || (ab && !pile->b_len))
		return ;
	pile_tab = !ab ? pile->pile_a : pile->pile_b;
	pile_len = !ab ? pile->a_len : pile->b_len;
	last = rev ? pile_tab[pile_len - 1] : pile_tab[0];
	i = rev ? pile_len - 1 : 0;
	while ((rev && i > 0) || (!rev && i < pile_len))
	{
		pile_tab[i] = pile_tab[i - rev + !rev];
		i = i - rev + !rev;
	}
	if (rev)
		pile_tab[0] = last;
	else
		pile_tab[pile_len - 1] = last;
}

int		iscmd(char *cmd)
{
	return (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb") ||
			!ft_strcmp(cmd, "ss") || !ft_strcmp(cmd, "pa") ||
			!ft_strcmp(cmd, "pb") || !ft_strcmp(cmd, "ra") ||
			!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr") ||
			!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb") ||
			!ft_strcmp(cmd, "rrr"));
}

int		check_pile(t_piles *pilelst, int print)
{
	int		i;

	while (pilelst->next)
		pilelst = pilelst->next;
	if (pilelst->b_len != 0)
		return (print ? ft_printf("KO\n") : 0);
	i = 0;
	while (i < pilelst->a_len - 1)
	{
		if (pilelst->pile_a[i] > pilelst->pile_a[i + 1])
			return (print ? ft_printf("KO\n") : 0);
		i++;
	}
	return (print ? ft_printf("OK\n") : 1);
}

int		free_pilelst(t_piles *pilelst)
{
	while (pilelst)
	{
		free(pilelst->pile_a);
		free(pilelst->pile_b);
		free(pilelst->cmd);
		free(pilelst);
		pilelst = pilelst->next;
	}
	return (0);
}
