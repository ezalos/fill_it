/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_print_one_elmnt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:58:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 21:58:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_print_one_elmnt(t_tab *tmp, size_t lin, size_t col, int structh)
{
	size_t				addr;

	addr = 14;
	place_cursor(lin, col);
	ft_putnbr(structh);
	place_cursor(lin, col + addr);

	ft_print_address_color((intmax_t)tmp->dir[0]);//	UP

	place_cursor(lin + 1, col);
	ft_print_address_color((intmax_t)tmp->dir[3]);//	LEFT
	ft_print_address_color((intmax_t)tmp);//			HERE
	ft_print_address_color((intmax_t)tmp->dir[1]);//	RIGHT

	place_cursor(lin + 2, col + addr);
	ft_print_address_color((intmax_t)tmp->dir[2]);//	DOWN
	return (0);
}
