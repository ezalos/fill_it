/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sqrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:30:18 by anonymou          #+#    #+#             */
/*   Updated: 2018/11/26 21:24:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>*/

float	f_sqrt(int nb, int limite)
{
	float	x;
	float	n;
	int		i;

	n = (float)nb;
	if (nb <= 0)
		return (0);
	i = 0;
	x = n / 2;
	if (limite == 0)
		limite = 30;
	while (--limite)
		x = (x + (n / x)) / 2;
	return (x);
}

/*int		main(int argc, char **argv)
{
	clock_t t = clock();
	double time_taken;
	if (argc == 2)
		printf("\n%f\n", f_sqrt(atoi(argv[1]), 0));
		t = clock() - t;
		time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		printf("It took %f seconds to execute \n\n", time_taken);
	return (0);
}*/
