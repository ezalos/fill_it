/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:48:51 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/27 18:48:52 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fcpy;

	if (lst)
	{
		if (!(fcpy = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		fcpy = f(lst);
		if (lst->next)
			fcpy->next = ft_lstmap(lst->next, f);
		return (fcpy);
	}
	return (NULL);
}
