/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:38:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 12:38:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	*free_linked_pieces(t_piece **next)
{
	int i;

	if (next && *next)
	{
		free_linked_pieces(&((*next)->next));
		(*next)->next = NULL;
		i = 0;
		while (i < 4)
		{
			free((*next)->coord[i++]);
			(*next)->coord[i] = NULL;
		}
		free((*next)->next);
		(*next)->next = NULL;
	}
	return (NULL);
}
