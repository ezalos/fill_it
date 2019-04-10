/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 21:32:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./head.h"

int		main(int ac, char **av)
{
	time_exe(__func__, clock());
	t_head	*head;
	int		check;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit ./path/file");
		return (0);
	}
	if (!(head = read_check(av[1])))
		return (0);
	if (!(setup_(head)))
		return (0);
	check = 0;
	while (check != 1)
	{
		check = solve_solution(head, 1);
		if (check == 1)
			print_result(head);
		else
		{
			if (!(restart_and_grow(head)))
				return (0);
		}
	}
	ft_clean_garbage();
	return (0);
}
