/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:43:25 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/30 22:55:27 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "libft.h"

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

t_sol	*next_solve_step(t_head head)
{
	t_sol *solution;

	if (!(soluion = (t_sol*)malloc(sizeof(t_sol) * 1)))
		return (NULL);
	while (tmp->sol != NULL)
	{

		head->sol = solution;
		head->sol->y_all_PxNx = ft_strdup(head->y_all_PxNx);
		head->sol->sol == NULL;
	}
	return (solution);
	dernier p* NULL (sol)
	pointeur next = NULL
}
