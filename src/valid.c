/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   valid.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:01:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 11:17:45 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int     iscmd(char *cmd)
{
    return (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb") ||
            !ft_strcmp(cmd, "ss") || !ft_strcmp(cmd, "pa") ||
            !ft_strcmp(cmd, "pb") || !ft_strcmp(cmd, "ra") ||
            !ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr") ||
            !ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb") ||
            !ft_strcmp(cmd, "rrr"));
}