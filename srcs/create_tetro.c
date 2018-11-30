/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:43:25 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/01 00:12:14 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "libft.h"

t_piece *create_tetro(const char *buf, t_head *head)
{
	t_piece *tetro;
	t_piece *tmp;
	if (head->next == NULL)
	{
		if (!(tetro = (t_piece*)malloc(sizeof(t_piece))))
			return (NULL);
		tetro->name = (char*)buf;
		tetro->next = NULL;
	}
	else
	{	
		tmp = tetro->next;
		if (!(tetro = (t_piece*)malloc(sizeof(t_piece))))
			return (NULL);
		while (tmp->next->next != NULL)
			tmp = tmp->next;

		tmp->name = (char*)buf;
		tmp->next = NULL;
			
	}
	head->p += 1;
	return (tetro);
}

t_sol	*next_solve_step(t_head *head)
{
	t_sol *solution;
	t_sol *tmp;

	if (head->sol == NULL)
	{
		if (!(solution = (t_sol*)malloc(sizeof(t_sol))))
			return (NULL);
		head->sol = solution;
		solution->sol = NULL;
		solution->y_all_PxNx = ft_strdup(head->y_all_PxNx);
		return (solution);
	}
	else
	{
		tmp = head->sol;
		if (!(solution = (t_sol*)malloc(sizeof(t_sol))))
			return (NULL);
		while (tmp->sol->sol != NULL)
			tmp = tmp->sol;
		tmp->sol = solution;
		tmp->sol->y_all_PxNx = ft_strdup(tmp->y_all_PxNx);
		tmp->sol->sol = NULL;
		return (solution);
	}
}

t_piece	*find_piece(t_head *head, int piece)
{
	t_piece	*tetro;
	int i;

	tetro = head->next;
	i = -1;
	while (++i <= piece && tetro->next != NULL)
		tetro = tetro->next;
	return (tetro);	
}

t_sol	*find_sol(t_head *head, int sol)
{
	t_sol *solution;
	int i;

	solution = head->sol;
	i = -1;
	while (++i <= sol && solution->next != NULL)
		solution = solution->next;
	return (solution);
}
