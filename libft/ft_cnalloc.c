/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 22:47:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*cnalloc(const void *content, size_t size_content)
{
	void	*new_malloc;
	t_list	*garbage;

	if (!size_content)
		return (NULL);
	if (!(new_malloc = malloc(size_content)))
		ft_clean_garbage();
	if (!content)
		ft_bzero(new_malloc, size_content);
	else
		ft_memmove(new_malloc, content, size_content);
	if (!(garbage = ft_lstnew_ptr(new_malloc, sizeof(new_malloc))))
		ft_clean_garbage();
	if (!ft_garbage_collector())
		*ft_garbage_collector() = garbage;
	else
		ft_lstadd_end(*ft_garbage_collector(), garbage);
	return (new_malloc);
}
