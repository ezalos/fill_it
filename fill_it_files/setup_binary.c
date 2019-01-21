/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 10:07:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/21 20:04:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**************************************
**                                  **
**  functions used to set up   		**
**  our binary solver               **
**                                  **
**************************************
*/

#include "./head.h"

void	while_in_write_binary(t_head *head, t_piece *piece, int *box)
{
	binary_to_str(head->solution
		[piece->tt_pos - piece->pc_pos + ++box[1]], box[0]);
	box[4] = -1;
	while (++box[4] < 4)
		binary_to_str(head->solution
			[piece->tt_pos - piece->pc_pos + box[1]],
			head->p + yx_to_j(piece->coord[box[4]]->y + box[2],
			piece->coord[box[4]]->x + box[3]));
}

/*
**	int box[5] is containing
** 	box[0] = current_piece;
** 	box[1] = pnnx;
** 	box[2] = y;
** 	box[3] = x;
** 	box[4] = i;
*/

void	write_binary(t_head *head)
{
	t_piece	*piece;
	int		box[6];

	box[0] = 0;
	piece = head->next;
	while (piece != NULL)
	{
		box[2] = -1;
		box[1] = -1;
		while (++box[2] <= head->sqsize - piece->y_size)
		{
			box[3] = -1;
			while (++box[3] <= head->sqsize - piece->x_size)
				while_in_write_binary(head, piece, box);
		}
		piece = piece->next;
		box[0]++;
	}
}

char	**malloc_binary(t_head *head)
{
	char	**sol;
	int		i;
	int		line;
	int		u;

	if (!(sol = (char**)malloc(sizeof(char*) * (size_t)head->tt_pos_all)))
		return (NULL);
	i = -1;
	line = ((head->p + (head->sqsize * head->sqsize)) / 8) + 1;
	while (++i < head->tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * (size_t)line)))
			return (free_tab_str(&sol, i));
		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}
