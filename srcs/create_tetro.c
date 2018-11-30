/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:43:25 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/30 03:01:14 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_piece *create_tetro(const char *buf)
{
	t_piece *tetro;
	t_head 	*head;

	if (buf)
	{
		if (!(tetro = (t_piece*)malloc(sizeof(t_piece))))
			return (NULL);
		if (!(head = (t_head*)malloc(sizeof(t_piece))))
			return (NULL);
		tetro->name = (char*)buf;
		tetro->next = (0);
//	tetro.prev =
		printf("%s\n", tetro->name);
		head->p += 1;
		printf("%i\n", head->p);
	}
	return (tetro);
//	rajouter les pointeurs vers next et vers prev

}
