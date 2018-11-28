/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:13:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/27 05:37:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		main(int ac, char **av)
{
	clock_t		t = clock();

	double time_taken;
	t = clock() - t;
	ft_read_check(av[1]);
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("It took %f seconds to execute \n", time_taken);
	return (0);
}
