/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:09:21 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 11:10:30 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct  s_piles
{
    int             *pile_a;
    int             *pile_b;
    int             len;
    char            *cmd;
    struct s_piles  *next;
}                   t_piles;
int     iscmd(char *cmd);
int     *swap(t_piles piles);
void    exec_cmd(t_piles piles);
#endif
