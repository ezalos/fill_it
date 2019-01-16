/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 10:07:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 16:33:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		deleter_of_binaries(t_head *head, int depth, int pos_choy)
{
	time_exe(__func__, cl(clock()));
	int	comp;
	int	pos_rev;
	int	champ;

	pos_rev = 0;
	champ = 0;
	head->config = find_piece(head, depth)->tt_pos - find_piece(head, depth)->pc_pos - 1;
	while (++head->config <= find_piece(head, depth)->tt_pos)
		if (find_sol(head, depth)->y_all_pxnx[head->config] == 1)
		{
			time_exe(__func__, cl(clock()));
			if (pos_rev < pos_choy)
				pos_rev++;
			else
			{
				comp = -1;
				while (++comp < head->tt_pos_all)
					if (comp != head->config && binstrand(head->solution[head->config], head->solution[comp], head->p + (head->sqsize * head->sqsize)))
						find_sol(head, depth)->y_all_pxnx[comp] = 0;
				time_exe(__func__, cl(clock()));
				return (1);
			}
		}
	return (0);
}

char	binary_string_and_start(char *s1, char *s2, size_t length, size_t start)
{
	time_exe(__func__, cl(clock()));
	size_t	r_del;
	size_t	a_del;
	char	sa;
	char	sb;

	r_del = (start / 8);
	sa = s1[r_del];
	sb = s2[r_del];
	a_del = (start % 8);
	if (sa << a_del & sb << a_del)
		return (1);
	r_del++;
	return (binstrand(s1 + r_del, s2 + r_del, length));
}

void	write_binary(t_head *head)
{
	time_exe(__func__, cl(clock()));
	t_piece *piece;
	int	i;
	int current_piece;
	int	pnnx;
	int y;
	int x;

	current_piece = 0;
	piece = head->next;
	while (piece != NULL)
	{
		y = -1;
		pnnx = -1;
		while (++y <= head->sqsize - piece->y_size)
		{
			x = -1;
			while (++x <= head->sqsize - piece->x_size)
			{
				binary_to_str(head->solution[piece->tt_pos - piece->pc_pos + ++pnnx], head->p + (head->sqsize * head->sqsize), current_piece);
				i = -1;
				while (++i < 4)
					binary_to_str(head->solution[piece->tt_pos - piece->pc_pos + pnnx], head->p + (head->sqsize * head->sqsize),
					head->p + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x));
			}
		}
		piece = piece->next;
		current_piece++;
	}
}

char	**malloc_binary(t_head *head)
{
	time_exe(__func__, cl(clock()));
	char	**sol;
	int		i;
	int		line;
	int		u;

	if (!(sol = (char**)malloc(sizeof(char*) * head->tt_pos_all)))
		return (NULL);
	i = -1;
	line = ((head->p + (head->sqsize * head->sqsize)) / 8) + 1;
	while (++i < head->tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
			return (free_tab_str(&sol, i));
		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}
