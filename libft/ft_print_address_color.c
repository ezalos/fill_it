/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:56:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 21:56:53 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_address_color(intmax_t nb)
{
	unsigned char		color;

	color = (unsigned char)nb;
	ft_putstr_color("|", 255, 255, 255);
	if (!nb)
		ft_putstr_color("    0x0     ", 255, 255, 255);
	else
		ft_putstr_color(ft_nb_to_a(nb, 16), ft_random(0, 255, nb, color), ft_random(0, 255, nb, color / 2), ft_random(0, 255, nb, color / 3));
	ft_putstr_color("|", 255, 255, 255);
}
