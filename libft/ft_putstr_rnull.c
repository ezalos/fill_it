/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_rnull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:42:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/11 18:23:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_putstr_rnull(char const *s)
{
	if (s == NULL)
		return (NULL);
	while (*s)
		write(2, s++, 1);
	return (NULL);
}
