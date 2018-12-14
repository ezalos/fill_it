/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/14 12:29:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		print_piece_debug(t_piece	*piece, int i)
{
	printf(_RESET"Tetro n*%d" _YELLOW"\tname:\t%s\n", i, (char*)piece->name);
	printf("\tLetter:\t%c\n", piece->letter);
	printf("\tY_size:\t%d\n", piece->y_size);
	printf("\tX_size:\t%d\n", piece->x_size);
	printf("\ti:\t%d\n", piece->i);
	printf("\tNb of placement:\t\t%d\n", piece->pc_pos);
	printf("\tSum until now of placements:\t%d\n", piece->tt_pos);
	printf(_RESET "\n");
	//printf("\t:\t%d\n", piece->);
}

void		print_pieces_debug(t_head *head)
{
	t_piece *tmp;
	int		i;

	tmp = head->next;
	i = 1;
	if (tmp != NULL)
	{
		print_piece_debug(tmp, i);
		tmp = tmp->next;
		while (tmp->next != NULL)
		{
			print_piece_debug(tmp, ++i);
			tmp = tmp->next;
		}
	}
}

void		print_head_soltion_debug(t_head *head)
{
	int		i;

	i = -1;
	while (++i < head->tt_pos_all)
		printf("\t: %s\n", head->solution[i]);
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
	printf(_GREEN "####################### <\\PRINT DEBUG> ######################\n\n" _RESET);
}
