/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:30:55 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/20 12:33:37 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char const *s, int r, int g, int b)
{
	if (s == NULL)
		return ;
	ft_rgb_color(r, g, b);
	write(1, s, ft_strlen(s));
	ft_rgb_color(255, 255, 255);
}
