/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 10:07:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 03:58:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

int		deleter_of_binaries(t_head *head, int deepness, int position_choice)
{
	time_exe(__func__, cl(clock()));
	int the_competitor;
	int	position_review;
	int	the_one_in_the_champion;

	position_review = 0;
	the_one_in_the_champion = 0;
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
	while (++head->the_choosen_configuration <= find_piece(head, deepness)->tt_pos)
		if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)
		{
			time_exe(__func__, cl(clock()));
			if (position_review < position_choice)
				position_review++;
			else
			{
				the_competitor = -1;
				while (++the_competitor < head->tt_pos_all)
					if (the_competitor != head->the_choosen_configuration && binary_string_and(head->solution[head->the_choosen_configuration], head->solution[the_competitor], head->p + (head->size_square * head->size_square)))
						find_sol(head, deepness)->y_all_PxNx[the_competitor] = 0;
				time_exe(__func__, cl(clock()));
				return (1);
			}
		}
	return (0);
}

char	binary_string_and(char *s1, char *s2, size_t length)
{
	time_exe(__func__, cl(clock()));
	size_t i;

/*	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (1);*/
	i = 0;
	length = (length / 8) + 1;
	while (i < length)
	{
		if (s1[i] & s2[i])
			return(1);
		i++;
	}
	return (0);
}

int	ft_iterative_power(int nb, int power)
{
	time_exe(__func__, cl(clock()));
	int x;

	x = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 0)
		x *= nb;
	return (x);
}

void	binary_to_str(char *binary, int size, int binary_position)
{
	time_exe(__func__, cl(clock()));
	int one;

	one = 1;
//	ft_putbinary_rev(binary, 4, size);
//	printf("\n");
//	one = one << (binary_position % 8);
	binary[binary_position / 8] += ft_iterative_power(2, (binary_position % 8));
//	printf("\n%d\t[%d]\t[%d]\t\tone: %d\tbinary: %d\n", binary_position, binary_position / 8, binary_position % 8, one, binary[binary_size(binary_position)]);
//	ft_putbinary_rev(binary, 4, size);
//	printf("\n\n");
}

void	write_binary(t_head *head)
{
	time_exe(__func__, cl(clock()));
	t_piece *piece;
	int	i;
	int current_piece;
	int	PnNx;
	int y;
	int x;

	current_piece = 0;
	piece = head->next;
	while (piece != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
	{
		y = -1;
		PnNx = -1;
		while (++y <= head->size_square - piece->y_size)
		{
			x = -1;
			while (++x <= head->size_square - piece->x_size)
			{
				binary_to_str(head->solution[piece->tt_pos - piece->pc_pos + ++PnNx], head->p + (head->size_square * head->size_square), current_piece);//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
					binary_to_str(head->solution[piece->tt_pos - piece->pc_pos + PnNx], head->p + (head->size_square * head->size_square),
					head->p + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x));
  				//Maxwell idea to implement here
			}
		}
		piece = piece->next;
		current_piece++;
	}
//we need to do it on last time for the last piece, it's just a copy/paste
}

int		binary_size(int length)
{
	time_exe(__func__, cl(clock()));
	if (length % 8 != 0)
		return ((length / 8) + 1);
	return ((length / 8) + 1);
}

char	**malloc_binary(t_head *head)
{
	time_exe(__func__, cl(clock()));
	char	**sol;
	int		i;
	int		line;
	int		u;

	//printf("1\n%d\n", head->tt_pos_all);
	if (!(sol = (char**)malloc(sizeof(char*) * head->tt_pos_all)))
		return (NULL); //need to protect if malloc has a pbm during allocation
	i = -1;
	line = ((head->p + (head->size_square * head->size_square)) / 8) + 1;
	while (++i < head->tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
			return (NULL); //need to protect if malloc has a pbm during allocation
		u = -1;
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}
