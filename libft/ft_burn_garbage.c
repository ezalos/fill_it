/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burn_garbage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:21:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 22:30:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_burn_garbage(char *str)
{
	t_list	*garbage;

	garbage = *ft_garbage_collector();
	ft_lst_free(&garbage);
	ft_putstr_fd("Error", 2);
	if (str && *str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	exit (0);
}
