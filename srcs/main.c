/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/13 22:09:33 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void time_exe(const char* s, clock_t *t)
{
	*t = clock() - *t;
	printf("%s took %f seconds to execute \n", s, ((double)*t)/CLOCKS_PER_SEC);
}

void	print_pieces_list(t_head *head)
{
	t_piece *tmp;

	tmp = head->next;
	if (tmp != NULL)
	{
		printf("\n1RETOUR tetro\t%c\n\t\tname:\t%s\n", head->next->letter, (char*)head->next->name);
		while (tmp->next != NULL)
		{
			printf("XRETOUR tetro\t%c\n\t\tname:\t%s\n", tmp->letter, (char*)tmp->name);
			tmp = tmp->next;
		}
	}
	printf("IN HEAD P=%d\n", head->p);
}

int		main(int ac, char **av)
{
	clock_t	t = clock();
	t_head	*head;
	int		check;

	if (ac != 2)
	{
		return (0);
//		putstr (error);
	}

	if (!(head = ft_read_check(av[1])))
		return (0);
	print_pieces_list(head);
	time_exe("ft_Read_Check", &t);
//		if (!(setup_head(head)))
			return (0);
	time_exe("Setup_Head", &t);
		check = solve_solution(head, -1);
	time_exe("Solve_Solution", &t);


/*		if (check == -1)
		{
			print_solution(&head);
			free_all(&head);
			return (0);
		}
		else
			head->size_square++;
			free_for_restart();//free all t_sol && tab_soltion && y_all_PxNx. Recalculate pc && tt (piece)
			restart();
	}*/
	return (0);
}
