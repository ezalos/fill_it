/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/18 05:17:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./head.h"

int		main(int ac, char **av)
{
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
	free_head(&head);
	return (0);
}
