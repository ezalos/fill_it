/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/14 15:54:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		print_piece_debug(t_piece	*piece)
{
	printf(_RESET"Tetro n*%d" _YELLOW"\tname:\t%s\n", piece->i, (char*)piece->name);
	printf("\t\t\tLetter:\t%c\n", piece->letter);
	printf("\t\t\tY_size:\t%d\n", piece->y_size);
	printf("\t\t\tX_size:\t%d\n", piece->x_size);
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
		ft_putnbr(i);
		write(1, "\t:", 2);
		while (++j < head->p + (head->size_square * head->size_square) + 1)
		{
			c = (char)(head->solution[i][j] + 48);
			write(1, &c, 1);
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
	printf("\tSize square:\t\t%d\n", head->size_square);
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
