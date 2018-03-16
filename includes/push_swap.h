/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 11:09:21 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:57:32 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
	int 			*index_a;
	int				a_len;
	int				*pile_b;
	int 			*index_b;
	int				b_len;
	char			*cmd;
	struct s_piles	*next;
}					t_piles;
int					value_to_index(t_piles *pile, int ab, int value);
int					index_to_value(t_piles *pile, int ab, int index);
t_piles				*launch_cmd(t_piles *pile, char *cmd);
int					get_min_index(t_piles *piles);
void				reorder_pile(t_piles *piles);
int					get_next_index(t_piles *piles, int lastind);
intmax_t			ft_atoi_secure(char *str);
int					avtoi(t_piles *piles, int ac, char **av);
int					launch_sort(t_piles *pilelst);
void				bit_swapper(int *tab, int i1, int i2);
int					put_indexes(t_piles *lst);
t_piles				*bubble_sort(t_piles *pile);
int					is_next(t_piles *pile, int a, int b);
int					count_numbers(int ac, char **av);
void				dup_piles(t_piles *dst, t_piles *src);
int					print_lst(t_piles *lst);
t_piles				*launch_cmd(t_piles *pile, char *cmd);
t_piles				*exec_cmd(t_piles *pile);
int					real_index(t_piles *pile, int index);
int					check_pile_rotated(t_piles *piles);
int					get_min_index(t_piles *piles);
int					check_pile(t_piles *pilelst, int print);
void				algo_select(t_piles *piles);
void				algo_bucket(t_piles *piles);
void				algo_quicksort(t_piles *piles);
int					init_piles(int ac, char **av, t_piles **piles);
t_piles				*fill_piles(t_piles *piles, char **line);
int					check_dup(t_piles *pstart);
int					error(void);
int					put_link(t_piles *lst);
int					iscmd(char *cmd);
int					free_pilelst(t_piles *pilelst);
void				rotate_pile(t_piles *pile, int ab, int rev);
#endif
