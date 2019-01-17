/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_rnull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:42:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 11:53:03 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_putstr_rnull(char const *s)
{
	if (s == NULL)
		return (NULL);
	while (*s)
		write(1, s++, 1);
	return (NULL);
}
