/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 13:38:44 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:44:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper((int)(str[i]));
		i++;
	}
	return (str);
}
