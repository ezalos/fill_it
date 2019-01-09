/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 10:07:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 05:26:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

int		deleter_of_binaries(t_head *head, int deepness, int position_choice)
{
time_exe(__func__, cl(clock()));	int	position_review;
	int	the_one_in_the_champion;

	position_review = 0;
	the_one_in_the_champion = 0;
	head->the_choosen_configuration = find_piece(head, deepness)->tt_pos - find_piece(head, deepness)->pc_pos - 1;
	while (++head->the_choosen_configuration <= find_piece(head, deepness)->tt_pos)
		if (find_sol(head, deepness)->y_all_PxNx[head->the_choosen_configuration] == 1)
		{
			if (position_review < position_choice)
			else
time_exe(__func__, cl(clock()));			{
				the_competitor = -1;
				while (++the_competitor < head->tt_pos_all)
					if (the_competitor != head->the_choosen_configuration && binary_string_and(head->solution[head->the_choosen_configuration], head->solution[the_competitor], head->p + (head->size_square * head->size_square)))
						find_sol(head, deepness)->y_all_PxNx[the_competitor] = 0;
				return (1);
			}
	return (0);
}
time_exe(__func__, cl(clock()));
char	binary_string_and(char *s1, char *s2, size_t length)
{
	size_t i;

	i = 0;
	while (i < length)
	{
		if (s1[i] & s2[i])
time_exe(__func__, cl(clock()));			return(1);
		i++;
	}
	return (0);
}

char	binary_string_and_start(char *s1, char *s2, size_t length, size_t start)
{
	size_t	r_del;
	size_t	a_del;
	char	sa;
	char	sb;
	r_del = (start / 8);
	sa = s1[r_del];
	sb = s2[r_del];
	a_del = (start % 8);
time_exe(__func__, cl(clock()));	if (sa << a_del & sb << a_del)
		return (1);
	r_del++;
	return (binary_string_and(s1 + r_del, s2 + r_del, length));
}

int	ft_iterative_power(int nb, int power)
{
	int x;

	x = 1;
	if (power == 0)
		return (1);
		return (0);
	while (power-- > 0)
		x *= nb;
	return (x);
}
time_exe(__func__, cl(clock()));
void	binary_to_str(char *binary, int size, int binary_position)
{
	int one;

	one = 1;
//	ft_putbinary_rev(binary, 4, size);
//	one = one << (binary_position % 8);
	binary[binary_position / 8] += ft_iterative_power(2, (binary_position % 8));
}

void	write_binary(t_head *head)
{
	int	i;
	int current_piece;
time_exe(__func__, cl(clock()));	int y;

	current_piece = 0;
	piece = head->next;
	while (piece != NULL) //for each piece convert y and x of possibilty to j, and write 1 to the 4 coord of piece
//	printf("\n");		y = -1;
		PnNx = -1;
		while (++y <= head->size_square - piece->y_size)
//	printf("\n%d\t[%d]\t[%d]\t\tone: %d\tbinary: %d\n", binary_position, binary_position / 8, binary_position % 8, one, binary[binary_size(binary_position)]);		{
			x = -1;
//	printf("\n\n");			while (++x <= head->size_square - piece->x_size)
			{
				binary_to_str(head->solution[piece->tt_pos - piece->pc_pos + ++PnNx], head->p + (head->size_square * head->size_square), current_piece);//need to write which piece is currently writen +1 & -1 as down
				i = -1;
				while (++i < 4)
time_exe(__func__, cl(clock()));					binary_to_str(head->solution[piece->tt_pos - piece->pc_pos + PnNx], head->p + (head->size_square * head->size_square),
					head->p + yx_to_j(piece->coord[i]->y + y, piece->coord[i]->x + x));
  				//Maxwell idea to implement here
			}
		}
		piece = piece->next;
		current_piece++;
	}
}

int		binary_size(int length)
{
	return ((length / 8) + 1);
}

char	**malloc_binary(t_head *head)
{
	char	**sol;
	int		i;
	int		line;
	int		u;

	if (!(sol = (char**)malloc(sizeof(char*) * head->tt_pos_all)))
		return (NULL); //need to protect if malloc has a pbm during allocation
	line = ((head->p + (head->size_square * head->size_square)) / 8) + 1;
	while (++i < head->tt_pos_all)
	{
		if (!(sol[i] = (char*)malloc(sizeof(char) * line)))
			return (NULL); //need to protect if malloc has a pbm during allocation
		while (++u < line)
			sol[i][u] = 0;
	}
	return (sol);
}
