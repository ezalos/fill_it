/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:41:56 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/29 00:46:40 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_piece	*ft_lstnew(const char *name, size_t name_size)
{
	t_piece *new;

	name_size = sizeof(char);
	if (!(new = (t_piece*)malloc(sizeof(t_head))))
		return (NULL);
	if (name)
	{
		if (!(new->name = ft_memalloc(name_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->name, name, name_size);
	//	new-> = name_size;
	}
	else
	{
		new->name = NULL;
//		new-> = 0;
	}
	new->next = NULL;
	return (new);
}
