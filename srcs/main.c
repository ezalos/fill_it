/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/25 23:14:49 by ldevelle         ###   ########.fr       */
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
	t_head	*head;
	int		check;

	if (ac != 2)
		return (0);
	time_exe(__func__, cl(clock()));
	if (!(head = ft_read_check(av[1])))
		return (0);
	if (!(setup_head(head)))
			return (0);
	while (check != 1)
	{
		print_debug(head);
		check = solve_solution(head, 1);
		if (check == 1)
			print_result(head);
		else
			if (!(restart_and_grow(head)))
				return (0);
	}
	time_exe(__func__, cl(clock()));
	print_time(time_exe(__func__, cl(clock())));
	return (0);
}
