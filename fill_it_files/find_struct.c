/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:32:22 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/23 01:37:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Set of functions that return the umpteenth element of a linked list
*/

#include "./head.h"

t_piece	*find_piece(t_head *head, int piece)
{
	time_exe(__func__, clock());
	t_piece				*tetro;
	int					i;

	tetro = head->next;
	i = 1;
	while (++i <= piece)
	{
		if (tetro == NULL)
			return (NULL);
		tetro = tetro->next;
	}
	return (tetro);
}

t_sol	*find_sol(t_head *head, int sol)
{
	time_exe(__func__, clock());
	t_sol				*solution;
	int					i;

	solution = head->sol;
	i = 1;
	while (++i <= sol)
	{
		if (solution == NULL)
			return (NULL);
		solution = solution->sol;
	}
	return (solution);
}

t_piece	*find_piece_hash(t_head *head, int piece)
{
	time_exe(__func__, clock());
	static t_piece		**hash;
	int					i;

	if (!hash)
	{
		i = 0;
		if (!(hash = (t_piece**)malloc(sizeof(t_piece*) * (size_t)head->p)))
			return (NULL);
		while (++i <= head->p)
			hash[i - 1] = find_piece_hash(head, i);
	}
	return (hash[piece - 1]);
}

t_sol	*find_sol_hash(t_head *head, int sol)
{
	time_exe(__func__, clock());
	static t_sol		**hash;
	int					i;

	if (!hash)
	{
		i = 0;
		if (!(hash = (t_sol**)malloc(sizeof(t_sol*) * (size_t)head->p)))
			return (NULL);
		while (++i <= head->p)
			hash[i - 1] = find_sol_hash(head, i);
	}
	return (hash[sol - 1]);
}
