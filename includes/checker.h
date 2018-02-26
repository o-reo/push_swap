/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:09:21 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:49:47 by eruaud      ###    #+. /#+    ###.fr     */
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

typedef struct		s_piles
{
	int				*pile_a;
	int				a_len;
	int				*pile_b;
	int				b_len;
	char			*cmd;
	struct s_piles	*next;
}					t_piles;
int					avtoi(t_piles *piles, int ac, char **av);
intmax_t			ft_atoi_secure(char *str);
int					init_piles(int ac, char **av, t_piles **piles);
t_piles				*fill_piles(t_piles *piles, char **line);
int					check_dup(t_piles *pstart);
void				dup_piles(t_piles *dst, t_piles *src);
int					launch_sort(t_piles *pilelst);
int					max(int a, int b);
int					print_lst(t_piles *lst);
int					error(void);
int					put_link(t_piles *lst);
int					check_pile(t_piles *pilelst, int print);
int					iscmd(char *cmd);
int					free_pilelst(t_piles *pilelst);
void				rotate_pile(t_piles *pile, int ab, int rev);
#endif
