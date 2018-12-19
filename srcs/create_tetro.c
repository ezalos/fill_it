/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:43:25 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/18 13:43:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		create_tetro(const char *name, t_head **head, char p)
{
	t_piece *tetro;

	if (name == NULL)
		return (0);
	if ((*head)->next == NULL)
	{
		if (!((*head)->next = (t_piece*)malloc(sizeof(t_piece))))
			return (0);
		(*head)->next->name = (char*)name;
		(*head)->next->next = NULL;
		(*head)->next->letter = p;
		return (1);
	}
	tetro = (*head)->next;
	while (tetro->next != NULL)
		tetro = tetro->next;
	if (!(tetro->next = (t_piece*)malloc(sizeof(t_piece))))
		return (0);
	tetro = tetro->next;
	tetro->name = (char*)name;
	tetro->next = NULL;
	tetro->letter = p;
	return (1);
}

t_sol	*next_solve_step(t_head *head, int step)
{
	t_sol 	*solution;
	t_sol 	*tmp;
	int		i;

	printf("Next solve step\n");
	if (head->sol == NULL)
	{
		if (!(solution = (t_sol*)malloc(sizeof(t_sol))))
			return (NULL);
		head->sol = solution;
		solution->sol = NULL;
		solution->y_all_PxNx = ft_strdup(head->y_all_PxNx);
		printf("First link of solve created\n");
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
		printf("Last link of solve created\n");
		return (solution);
	}
}

t_piece	*find_piece(t_head *head, int piece)
{
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
