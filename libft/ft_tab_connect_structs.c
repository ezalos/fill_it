/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_connect_structs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:29:22 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:29:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tab_connect_structs(t_tab *tab_one, t_tab *tab_two, size_t dir_one)
{
	size_t	dir_two;

	dir_two = ft_tab_dir_reverse(dir_one);
	tab_one->dir[dir_one] = tab_two;
	tab_two->dir[dir_two] = tab_one;
}
