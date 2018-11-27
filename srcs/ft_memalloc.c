/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:43:01 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/27 18:43:15 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
