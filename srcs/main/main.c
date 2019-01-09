/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 08:01:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

/*void time_exe(const char* s, clock_t *t){
	t_head	*head;

printf(_CYAN "%s took %f seconds to execute \n" _RESET, s, ((double)*t)/CLOCKS_PER_SEC);	if (ac != 2)
		return (0);
	if (!(head = read_check(av[1])))
	{
		return (0);
	}
	if (!(setup_(head)))
			return (0);
	{
		print_debug(head);
time_exe(__func__, cl(clock()));		if (check == 1)
			print_result(head);
		else
printf("error\n");			if (!(restart_and_grow(head)))
				return (0);
	}
	return (0);
}
