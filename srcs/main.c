/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/01 03:37:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void time_exe(const char* s, clock_t *t)
{
	*t = clock() - *t;
	printf("%s took %f seconds to execute \n", s, ((double)*t)/CLOCKS_PER_SEC);
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
	time_exe("ft_Read_Check", &t);
		if (!(setup_head(head)))
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
