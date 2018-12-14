/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:43:25 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/14 13:55:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest[size] = '\0';
	i = -1;
	while (++i < size)
		dest[i] = src[i];
	return (dest);
}

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
	i = 1;
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
	while (++i <= sol && solution->sol != NULL)
		solution = solution->sol;
	return (solution);
}
