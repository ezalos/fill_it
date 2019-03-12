/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:38:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:56:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Allow to free the tetraminos stored in a linked list
*/

#include "./head.h"

void	*free_linked_pieces(t_piece **next)
{
	int i;

	if (next && *next)
	{
		free_linked_pieces(&((*next)->next));
		(*next)->next = NULL;
		i = -1;
		while (++i < 4)
			ft_memdel((void**)&(*next)->coord[i]);
		ft_memdel((void**)next);
	}
	return (NULL);
}
