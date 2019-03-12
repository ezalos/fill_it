/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_conect_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:10:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 22:11:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tab_connect_dir(size_t dir_line, t_tab *line_one, t_tab *line_two, size_t dir_connec)
{
	t_tab	*tmp_one;
	t_tab	*tmp_two;
	int		already;

	if (!line_one || dir_line > 3 || !line_two || dir_connec > 3)
		return (-1);
	tmp_one = line_one;
	tmp_two = line_two;
	already = 0;
	while ((tmp_one && tmp_two) && ((tmp_one != line_one && tmp_two != line_two) || !already))
	{
		tmp_one->dir[dir_connec] = tmp_two;
		tmp_one->dir[dir_connec]->dir[ft_tab_dir_reverse(dir_connec)] = tmp_one;
		tmp_one = tmp_one->dir[dir_line];
		tmp_two = tmp_two->dir[dir_line];
		already++;
	}
	return (0);
}
