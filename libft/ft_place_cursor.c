/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:27:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/19 15:01:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			place_cursor(size_t line, size_t column)
{
	char		*string;
	char		*tmp;
	char		*nb;

	if (!(nb = ft_itoa(line)))
		return (0);
	if (!(string = ft_strjoin("\033[", nb)))
		return (0);
	ft_strdel(&nb);
	if (!(tmp = ft_strjoin(string, ";")))
		return (0);
	ft_strdel(&string);
	if (!(nb = ft_itoa(column)))
		return (0);
	if (!(string = ft_strjoin(tmp, nb)))
		return (0);
	ft_strdel(&nb);
	ft_strdel(&tmp);
	if (!(tmp = ft_strjoin(string, "H")))
		return (0);
	ft_strdel(&string);
	write(1, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
	return (1);
}
