/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:31:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 12:45:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		binary_size(int length)
{ 
	time_exe(__func__, clock()); 
	return ((length / 8) + 1);
}

void	binary_to_str(char *binary, int size, int binary_position)
{ 
	time_exe(__func__, clock()); 
	binary[binary_position / 8] += ft_iterative_power(2, (binary_position % 8));
}

char	binstrand(char *s1, char *s2, size_t length)
{ 
	time_exe(__func__, clock()); 
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

char	binary_string_and_start(char *s1, char *s2, size_t length, size_t start)
{ 
	time_exe(__func__, clock()); 
	size_t	r_del;
	size_t	a_del;
	char	sa;
	char	sb;

	r_del = (start / 8);
	sa = s1[r_del];
	sb = s2[r_del];
	a_del = (start % 8);
	if (sa << a_del & sb << a_del)
		return (1);
	r_del++;
	return (binstrand(s1 + r_del, s2 + r_del, length));
}