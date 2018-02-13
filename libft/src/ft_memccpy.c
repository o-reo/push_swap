/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:37:52 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 09:37:53 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if (*((unsigned char*)dst + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
