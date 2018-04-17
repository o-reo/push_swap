/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:37:36 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if (!(new = (void *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(new->content = (void *)malloc(sizeof(content) * content_size)))
			return (NULL);
		new->content = ft_memcpy(new->content, (void*)content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content_size = 0;
		new->content = NULL;
	}
	new->next = NULL;
	return (new);
}
