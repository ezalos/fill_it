/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_bcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:13:14 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/22 22:30:03 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

int			ft_rgb_bcolor(int red, int green, int blue)
{
	char		*color;
	char		*s_red;
	char		*s_green;
	char		*s_blue;

	if (red < 0)
		red = ft_random(0, 255, clock(), 10);
	if (green < 0)
		green = ft_random(0, 255, clock(), 10);
	if (blue < 0)
		blue = ft_random(0, 255, clock(), 10);
	if (!(s_red = ft_itoa(red)))
		return (-1);
	if (!(s_green = ft_itoa(green)))
		return (-1);
	if (!(s_blue = ft_itoa(blue)))
		return (-1);
	if (!(color = ft_strjoin_multi(7, "\x1b[48;2;", s_red, ";", s_green, ";", s_blue, "m")))
		return (-1);
	write(1, color, ft_strlen(color));
	ft_strdel(&s_green);
	ft_strdel(&s_blue);
	ft_strdel(&s_red);
	ft_strdel(&color);
	return (1);
}
