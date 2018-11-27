/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:20 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/27 02:45:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static const char	*part10(char *s, int i, int div, int mod)
{
		if (mod >= 1 && s[i + 5 - 1] == '#')
		{
			if (s[i + (5 * 2) - 1] == '#' && div < 2)
				return ("Z1");
			if (mod >= 2 && s[i + 5 - 2] == '#')
				return ("L3");
			if (s[i + (5 * 2)] == '#' && div < 2)
				return ("T1");
			if (mod <= 2 && s[i + 5 + 1] == '#')
				return ("T2");
			if (mod <= 2 && s[i + 1] == '#')
				return ("Z0");
		}
	return (NULL);
}

static const char	*part1(char *s, int i, int div, int mod)
{
	if (s[i + 5] == '#' && div < 3)
	{
//			printf("1\n");
		if (mod <= 2 && s[i + 5 + 1] == '#')
		{
			if (mod <= 1 && s[i + 5 + 2] == '#')
				return ("J1");
			if (s[i + (5 * 2) + 1] == '#' && div < 2)
				return ("S1");
			if (s[i + (5 * 2)] == '#' && div < 2)
				return ("T3");
		}
		if (s[i + (5 * 2)] == '#' && div < 2)
		{
//			printf("%s\n",s );
//				printf("2 %d |%c%c%c%c|\n", div, s[i], s[i + (5 * 1)], s[i + (5 * 2)], s[i + (5 * 3)]);
			if (mod <= 2 && s[i + (5 * 2) + 1] == '#')
				return ("L0");
			if (s[i + (5 * 3)] == '#' && div < 1)
				return ("I0");
			if (mod >= 1 && s[i + (5 * 2) - 1] == '#')
			{
//					printf("3\n");
				return ("J0");
			}
			if (mod <= 2 && s[i + 1] == '#')
				return ("J2");
		}
		return (part10(s, i, div, mod));
	}
	return (NULL);
}

static const char	*part0(char *s, int i, int div, int mod)
{
//	printf("0\n");
	if (mod <= 2 && s[i + 1] == '#')
	{
		if (mod <= 1 && s[i + 2] == '#')
		{
			if (mod <= 0 && s[i + 3] == '#')
				return ("I1");
			if (s[i + 2 + 5] == '#' && div < 3)
				return ("J3");
			if (s[i + 1 + 5] == '#' && div < 3)
				return ("T0");
			if (s[i + 5] == '#' && div < 3)
				return ("L1");
		}
		if (s[i + 1 + 5] == '#' && div < 3)
		{
			if (mod <= 1 && s[i + 2 + 5] == '#')
				return ("S0");
			if (s[i + 1 + 5] == '#')
				return ("O0");
			if (mod <= 1 && s[i + 2 + (2 * 5)] == '#' && div < 2)
				return ("L2");
		}
	}
	return (part1(s, i, div, mod));
}

const char			*recognize(char *s)
{
	int		i;
	int		div;
	int		mod;

	i = 0;
	while (s[i] != '#')
		i++;
	div = i / 5;
	mod = (i % 5);

	return(part0(s, i, div, mod));
}
