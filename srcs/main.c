/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/20 11:31:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*void time_exe(const char* s, clock_t *t)
{
	*t = clock() - *t;
	printf(_CYAN "%s took %f seconds to execute \n" _RESET, s, ((double)*t)/CLOCKS_PER_SEC);
}*/

int		main(int ac, char **av)
{
	clock_t	t = clock();
	t_head	*head;
	int		check;

	if (ac != 2)
		return (0);
	time_exe(__func__, cl(clock()));
	if (!(head = ft_read_check(av[1])))
		return (0);
//	time_exe("ft_Read_Check", &t);
	if (!(setup_head(head)))
			return (0);
//	time_exe("Setup_Head", &t);

	while (check != -1)
	{
		print_debug(head);
		check = solve_solution(head, 1);
		printf("Check = %d\n", check);
//		time_exe("Solve_Solution", &t);
		if (check == -1)
			print_result(head);
		else
			if (!(restart_and_grow(head)))
				return (0);
	}
//	time_exe("Print_Solution", &t);
	//free everything
	print_time(time_exe(__func__, cl(clock())));
	return (0);
}
