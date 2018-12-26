/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:46:48 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/26 16:49:53 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.c"

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
		/*if (tmp->sol != NULL)
		{
			i = 0;
			while (find_sol(head, step + i))
				i++;
			while (i > 0)
			{
				printf("Deletion of sol n*%d\n", step + i - 1);
				free(find_sol(head, step + --i));
				find_sol(head, step + i)->sol = NULL;
			}
		}*/
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

/*	if (sol <= 0)
	{
		printf("Sol <= 0\n");
		return (NULL);
	}*/
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
//	printf("\t\t\tSol %d found !\n", sol);
	return (solution);
}
