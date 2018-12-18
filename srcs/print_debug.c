/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/18 10:30:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_grid_j(t_head *head)
{
	int y;
	int x;

	y = -1;
	printf(_GREEN"~~~~~~~~~~~~~~~~~YX_TO_J~~~~~~~~~~~~~~~~~\n");
	while (++y < head->size_square)
	{
		x = -1;
		while (++x < head->size_square)
			printf(_GREEN "%d\t", yx_to_j(y, x));
		printf("\n" _RESET);
	}
	printf("\n");
}

void		print_piece_debug(t_piece	*piece)
{
	printf(_RESET"Tetro n*%d" _YELLOW"\tname:\t%s\t\t[%d;%d]->%d\n", piece->i, (char*)piece->name, piece->coord[0]->y, piece->coord[0]->x, piece->coord[0]->j);
	printf("\t\t\tLetter:\t%c\t\t[%d;%d]->%d\n", piece->letter, piece->coord[1]->y, piece->coord[1]->x, piece->coord[1]->j);
	printf("\t\t\tY_size:\t%d\t\t[%d;%d]->%d\n", piece->y_size, piece->coord[2]->y, piece->coord[2]->x, piece->coord[2]->j);
	printf("\t\t\tX_size:\t%d\t\t[%d;%d]->%d\n", piece->x_size, piece->coord[3]->y, piece->coord[3]->x, piece->coord[3]->j);
	//printf("\t\t\ti:\t%d\n", piece->i);
	printf("\t\t_____\n");
	printf("\t\tNb of placement:\t\t%d\n", piece->pc_pos);
	printf("\t\tSum until now of placements:\t%d\n", piece->tt_pos);
	printf(_RESET "---------\n\n");
	//printf("\t:\t%d\n", piece->);
}

void		print_pieces_debug(t_head *head)
{
	t_piece *tmp;

	tmp = head->next;
	if (tmp != NULL)
	{
		print_piece_debug(tmp);
		tmp = tmp->next;
		while (tmp->next != NULL)
		{
			print_piece_debug(tmp);
			tmp = tmp->next;
		}
		print_piece_debug(tmp);
	}
}

void		print_soltion_link_debug(t_head *head, int step)
{
	t_sol	*tmp;
	int		i;
	int		j;
	char	c;

	tmp = find_sol(head, step);
	if (tmp == NULL)
		return ;
	else
	{
		write(1, "\x1b[32m", 5);
		ft_putstr("\n\n\tStep:\t");
		ft_putnbr(step);
		ft_putstr("\tCurrent path:\t");
		ft_putnbr(tmp->current_path);
		ft_putstr("\n\t\t\tNb of path:\t");
		ft_putnbr(tmp->nb_of_paths);
		write(1, "\n", 1);
			i = -1;
			while (++i < head->tt_pos_all)
			{
				j = -1;
				//printf("%d|", i);
				c = tmp->y_all_PxNx[i] + 48;
				if (c == '0')
					write(1, "\x1b[31m", 5);
				else
					write(1, "\x1b[33m", 5);
				ft_putnbr(i);
				write(1, "\t", 1);
				write(1, &c, 1);
				write(1, "-->", 3);

				while (++j < head->p + (head->size_square * head->size_square))
				{
					c = (char)(head->solution[i][j] + 48);
					write(1, &c, 1);
					if (j == head->p - 1)
						write(1, " ", 1);
				}
				write(1, "\n", 1);
			}
		//	write(1, "\n", 1);
		}
		write(1, "\x1b[32m", 5);
		ft_putstr("\tStep:\t");
		ft_putnbr(step);
		ft_putstr("\tCurrent path:\t");
		ft_putnbr(tmp->current_path);
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

	i = -1;

	while (++i < head->tt_pos_all)
	{
		j = -1;
		//printf("%d|", i);
		c = head->y_all_PxNx[i] + 48;
		if (c == '0')
			write(1, "\x1b[34m", 5);
		else
			write(1, "\x1b[36m", 5);
		ft_putnbr(i);
		write(1, "\t", 1);
		write(1, &c, 1);
		write(1, "-->", 3);

		while (++j < head->p + (head->size_square * head->size_square))
		{
			c = (char)(head->solution[i][j] + 48);
			write(1, &c, 1);
			if (j == head->p - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	//write(1, "\n", 1);

		//printf("%d\t: %s\n", i, head->solution[i]);
}

void		print_head_debug(t_head *head)
{
	printf(_RED "\nSTRUCT HEAD\n");
	printf("\tSize square:\t\t%d -> %d\t\t(%d)\n", head->size_square, head->size_square * head->size_square, head->size_square * head->size_square + head->p);
	printf("\tNb of pieces:\t\t%d\n", head->p);
	printf("\tSum of all PxNx:\t%d\n", head->tt_pos_all);
	//printf("\tPossible soltions: %d\n", head->possible_solutions);
	printf("\tThe choosen config:\t%d\n", head->the_choosen_configuration);
	//printf("\t: %d\n", head->);
	printf("\n\n\n");
}

void	print_debug(t_head *head)
{
	printf(_GREEN "\n####################### <PRINT DEBUG> #######################\n" _RESET);
	print_head_debug(head);
	print_pieces_debug(head);
	print_head_soltion_debug(head);//think to add the little string
	printf(_GREEN "####################### <\\PRINT DEBUG> ######################\n\n" _RESET);
}
