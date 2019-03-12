/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:03:00 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:45:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab		*ft_tabnew_ptr(void const *content, size_t content_size)
{
	t_tab		*new;

	if (!(new = (t_tab*)P_MALLOC(sizeof(t_tab))))
		return (NULL);
	ft_bzero(new, sizeof(t_tab));
	if (content_size && content != NULL)
	{
		new->content_size = content_size;
		if (!content_size || !(new->content = P_MALLOC(content_size)))
		{
			ft_memdel((void**)&new);
			return (NULL);
		}
		ft_memmove(new->content, (void*)content, content_size);
	}
	return (new);
}
