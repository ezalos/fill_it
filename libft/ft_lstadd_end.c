/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:53:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 14:14:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list *alst, t_list *new)
{
	t_list		*tmp;

	if (alst != NULL)
	{
		tmp = alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
