/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:09:21 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 17:57:18 by eruaud      ###    #+. /#+    ###.fr     */
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
# include "ft_printf.h"

# define CINT_MAX 2147483647
# define CINT_MIN -2147483648
typedef struct  s_piles
{
    int             *pile_a;
    int             a_len;
    int             *pile_b;
    int             b_len;
    char            *cmd;
    struct s_piles  *next;
}                   t_piles;
void	dup_piles(t_piles *dst, t_piles *src);
int		launch_sort(t_piles *pilelst);
int		max(int a, int b);
int		put_tab(int *tab, int len);
int		print_lst(t_piles *lst);
int		error(void);
int		put_link(t_piles *lst);
int		check_pile(t_piles *pilelst);
int		iscmd(char *cmd);
int		free_pilelst(t_piles *pilelst);
void	rotate_pile(t_piles *pile, int ab, int rev);
#endif
