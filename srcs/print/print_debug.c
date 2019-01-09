/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 04:01:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

void	print_grid_j(t_head *head)
{
time_exe(__func__, cl(clock()));	int x;

	y = -1;
	while (++y < head->size_square)
		x = -1;
printf(_GREEN"~~~~~~~~~~~~~~~~~YX_TO_J~~~~~~~~~~~~~~~~~\n");		while (++x < head->size_square)
	}
}
{

printf(_GREEN "%d\t", yx_to_j(y, x));void		print_pieces_debug(t_head *head)
printf("\n" _RESET);{
	t_piece *tmp;
printf("\n");		print_piece_debug(tmp);
	}
}

{
time_exe(__func__, cl(clock()));	size_t	i;
printf(_RESET"Tetro n*%d" _YELLOW"\tname:\t%s\t\t[%d;%d]->%d\n", piece->i, (char*)piece->name, piece->coord[0]->y, piece->coord[0]->x, piece->coord[0]->j);	int		nb;
printf("\t\t\tLetter:\t%c\t\t[%d;%d]->%d\n", piece->letter, piece->coord[1]->y, piece->coord[1]->x, piece->coord[1]->j);	int		stop;
printf("\t\t\tY_size:\t%d\t\t[%d;%d]->%d\n", piece->y_size, piece->coord[2]->y, piece->coord[2]->x, piece->coord[2]->j);	size_t	j;
printf("\t\t\tX_size:\t%d\t\t[%d;%d]->%d\n", piece->x_size, piece->coord[3]->y, piece->coord[3]->x, piece->coord[3]->j);	char	c;
//printf("\t\t\ti:\t%d\n", piece->i);
printf("\t\t_____\n");	i = 0;
printf("\t\tNb of placement:\t\t%d\n", piece->pc_pos);	stop = length;
printf("\t\tSum until now of placements:\t%d\n", piece->tt_pos);	length = (length / 8) + 1;
printf(_RESET "---------\n\n");	while (i < length)
//printf("\t:\t%d\n", piece->);	{
		j = 0;
		nb = (unsigned char)str[i];
		while (j < 8)
		{
time_exe(__func__, cl(clock()));			c = (nb % 2) + '0';
			write(1, &c, 1);
				write(1, ".", 1);
			if (stop == (i * 8) + j)
				return ;
			nb = nb / 2;
			j++;
		}
		write(1, " ", 1);
		i++;
	}
}

void		print_soltion_link_debug(t_head *head, int step, int current_path)
{
	t_sol	*tmp;
	int		i;
	int		j;
	char	c;
time_exe(__func__, cl(clock()));
	tmp = find_sol(head, step);
	if (tmp == NULL)
		return ;
	else
	{
		write(1, "\x1b[32m", 5);
		ft_putstr("\n\n\tStep:\t");
		ft_putnbr(step);
		ft_putstr("\tCurrent path:\t");
		ft_putnbr(current_path);
		ft_putstr("\n\t\t\tNb of path:\t");
		ft_putnbr(tmp->nb_of_paths);
		write(1, "\n", 1);
			while (++i < head->tt_pos_all)
			{
				j = -1;
				c = tmp->y_all_PxNx[i] + 48;
				if (c == '0')
					write(1, "\x1b[31m", 5);
				else
					write(1, "\x1b[33m", 5);
				ft_putnbr(i);
				write(1, "\t", 1);
				write(1, &c, 1);
				write(1, "-->", 3);
				ft_putbinary_rev(head->solution[i], head->p, head->p + (head->size_square * head->size_square) - 1);

/*				while (++j < head->p + (head->size_square * head->size_square))
				{
					c = (char)(head->solution[i][j] + 48);
					write(1, &c, 1);
time_exe(__func__, cl(clock()));					if (j == head->p - 1)
						write(1, " ", 1);
				}*/
				write(1, "\n", 1);
		//	write(1, "\n", 1);
		}
		write(1, "\x1b[32m", 5);
		ft_putstr("\tStep:\t");
		ft_putnbr(step);
		ft_putstr("\tCurrent path:\t");
		ft_putnbr(current_path);
		ft_putstr("\n\t\t\tNb of path:\t");
		ft_putnbr(tmp->nb_of_paths);
		write(1, "\n\n\n", 3);
		write(1, "\x1b[0m", 5);

}

void		print_head_soltion_debug(t_head *head)
{
	int		i;
	int		j;
	char	c;
//printf("%d|", i);
	i = -1;

	while (++i < head->tt_pos_all)
	{
		j = -1;
		c = head->y_all_PxNx[i] + 48;
		if (c == '0')
			write(1, "\x1b[34m", 5);
		else
			write(1, "\x1b[36m", 5);
		ft_putnbr(i);
		write(1, "\t", 1);
		write(1, &c, 1);
		write(1, "-->", 3);
		ft_putbinary_rev(head->solution[i], head->p, head->p + (head->size_square * head->size_square) - 1);

		{
			c = (char)(head->solution[i][j] + 48);
			write(1, &c, 1);
			if (j == head->p - 1)
				write(1, " ", 1);
		}*/
		write(1, "\n", 1);
	}
	write(1, "\n", 1);

}

void		print_head_debug(t_head *head)
{
}

void	print_debug(t_head *head)
{
	print_head_debug(head);
	print_pieces_debug(head);
time_exe(__func__, cl(clock()));	print_head_soltion_debug(head);//think to add the little string
}
