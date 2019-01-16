/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:09:05 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/16 16:44:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_iterative_power(int nb, int power)
{
	time_exe(__func__, cl(clock()));
	int x;

	x = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 0)
		x *= nb;
	return (x);
}

int		binary_size(int length)
{
	time_exe(__func__, cl(clock()));
	return ((length / 8) + 1);
}

void	binary_to_str(char *binary, int size, int binary_position)
{
	time_exe(__func__, cl(clock()));
	binary[binary_position / 8] += ft_iterative_power(2, (binary_position % 8));
}

char	binstrand(char *s1, char *s2, size_t length)
{
	time_exe(__func__, cl(clock()));
	size_t i;

	i = 0;
	length = (length / 8) + 1;
	while (i < length)
	{
		if (s1[i] & s2[i])
			return (1);
		i++;
	}
	return (0);
}
