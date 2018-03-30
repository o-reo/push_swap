/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   postproc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:37:35 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:38:26 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*cmd_replace(t_piles *curpile, int nb, char *cmd)
{
	t_piles		*pi;

	free(curpile->cmd);
	curpile->cmd = ft_strdup(cmd);
	pi = curpile->next;
	while (nb--)
		pi = pi->next;
	curpile->next = NULL;
	curpile->next = pi;
	return (curpile);
}

void		cmd_insert(t_piles *curpile, char *cmd)
{
	t_piles 	*next_pile;

	curpile = curpile->next;
	next_pile = curpile->next;
	curpile->next = NULL;
	curpile->next = launch_cmd(curpile, cmd);
	curpile->next = next_pile;
}

t_piles		*post_process(t_piles *piles)
{
	t_piles		*pi;

	pi = piles;
	while (pi)
	{
		if (pi->cmd && !ft_strcmp(pi->cmd, "ra")
		&& pi->next->cmd && !ft_strcmp(pi->next->cmd, "pb")
		&& pi->next->next->cmd && !ft_strcmp(pi->next->next->cmd, "rra")
		&& pi->next->next->next->cmd && !ft_strcmp(pi->next->next->next->cmd, "pa"))
			pi = cmd_replace(pi, 3, "sa");
		pi = pi->next;
	}
	return (piles);
}