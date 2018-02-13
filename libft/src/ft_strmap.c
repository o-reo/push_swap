/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:42:55 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 09:42:57 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*so;

	if (!s || !f || !(so = ft_strdup((char *)s)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		so[i] = f(s[i]);
		i++;
	}
	return (so);
}
