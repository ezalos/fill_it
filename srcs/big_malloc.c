/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:24:06 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/27 14:38:29 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

##include "head.h"
char	**big_malloc(int p, list pieces)
{
	char	**tab_sol;
	int		size_square;
	int		size_pieces;
	int		all_positions;
	int		i;

	size_square = size_square(p);
	if (!(tab_sol = (char**)malloc(sizeof(char*) *
		(p + (size_square * size_square) + 1))))
		return (NULL); //need to free all preceding mallocs
	tab_sol[p + (size_square * size_square)] = NULL;
	i = -1;
	all_positions = 0;
	while (++i < p)
	{
		all_positions += size_pieces(pieces[i]);
	}
	i = -1;
	while (++i < p + (size_square * size_square))
	{
		if (!(tab_sol[i] = (char*)malloc(sizeof(char) * (all_positions + 1))))
			return (NULL); //need to free all preceding mallocs
		tab_sol[i][all_positions] = '\0';
	}
	return (tab_sol);
}
