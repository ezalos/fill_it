/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:46:48 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 05:42:52 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_sol	*next_solve_step(t_head *head, int step)
{
	time_exe(__func__, cl(clock()));
	t_sol 	*solution;
	t_sol 	*tmp;
	int		i;

//	printf("Next solve step\n");
	if (head->sol == NULL)
	{
		if (!(solution = (t_sol*)malloc(sizeof(t_sol))))
			return (NULL);
		head->sol = solution;
		solution->sol = NULL;
		solution->y_all_PxNx = ft_strdup(head->y_all_PxNx);
	//	printf("First link of solve created\n");
		return (solution);
	}
	else
	{
		tmp = find_sol(head, step - 1);
		if (!(solution = (t_sol*)malloc(sizeof(t_sol))))
			return (NULL);
		tmp->sol = solution;
		if (!(tmp->sol->y_all_PxNx = ft_memalloc(head->tt_pos_all)))
			return (NULL);
		ft_memcpy(tmp->sol->y_all_PxNx, tmp->y_all_PxNx, head->tt_pos_all);
		tmp->sol->sol = NULL;
//		printf("Last link of solve created\n");
		return (solution);
	}
}

t_piece	*find_piece(t_head *head, int piece)
{
	time_exe(__func__, cl(clock()));
	t_piece	*tetro;
	int i;

/*	if (piece <= 0)
	{
		printf("Piece <= 0\n");
		return (NULL);
	}*/
	tetro = head->next;
	i = 1;
	while (++i <= piece)
	{
		if (tetro == NULL)
		{
			printf("\t\t\tPiece %d does not exist !\n", piece);
			return (NULL);
		}
		tetro = tetro->next;
	}
	//printf("\t\t\tPiece %d found !\n", piece);
	return (tetro);
}

t_sol	*find_sol(t_head *head, int sol)
{
	time_exe(__func__, cl(clock()));
	t_sol *solution;
	int i;

	solution = head->sol;
	i = 1;
	while (++i <= sol)
	{
		if (solution == NULL)
		{
			printf("\t\t\tSol %d does not exist !\n", sol);
			return (NULL);
		}
		solution = solution->sol;
	}
	return (solution);
}

t_piece	*find_piece0(t_head *head, int piece)
{
	time_exe(__func__, cl(clock()));
	static t_piece 		**hash;
	int					i;

	if (!hash)
	{
		i = 0;
		if (!(hash = (t_piece**)malloc(sizeof(t_piece*) * head->p)))
			return (NULL);
		while (++i <= head->p)
			hash[i - 1] = find_piece0(head, i);
	}
	return (hash[piece - 1]);
}

t_sol	*find_sol0(t_head *head, int sol)
{
	time_exe(__func__, cl(clock()));
	static t_sol 		**hash;
	int					i;

	if (!hash)
	{
		i = 0;
		if (!(hash = (t_sol**)malloc(sizeof(t_sol*) * head->p)))
			return (NULL);
		while (++i <= head->p)
			hash[i - 1] = find_sol0(head, i);
	}
	return (hash[sol - 1]);
}
