/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 07:46:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

static const char	*part10(char *s, int i, int div, int mod)
{
		if (mod >= 1 && s[i + 5 - 1] == '#')
		{
			if (s[i + (5 * 2) - 1] == '#' && div < 2)
				return ("Z110011120");
			if (mod >= 2 && s[i + 5 - 2] == '#')
				return ("O000100111");
			if (s[i + (5 * 2)] == '#' && div < 2)
				return ("T110011121");
			if (mod <= 2 && s[i + 5 + 1] == '#')
				return ("T210011112");
			if (mod <= 2 && s[i + 1] == '#')
				return ("S010011102");
		}
	return (NULL);
}

static const char	*part1(char *s, int i, int div, int mod)
{
	if (s[i + 5] == '#' && div < 3)
	{
//			printf("1\n");		{
			if (mod <= 1 && s[i + 5 + 2] == '#')
				return ("J100101112");
			if (s[i + (5 * 2) + 1] == '#' && div < 2)
				return ("S100101121");
			if (s[i + (5 * 2)] == '#' && div < 2)
				return ("T300101120");
		}
		if (s[i + (5 * 2)] == '#' && div < 2)
		{
			if (mod <= 2 && s[i + (5 * 2) + 1] == '#')
				return ("I000102030");
//			printf("%s\n",s );			if (mod >= 1 && s[i + (5 * 2) - 1] == '#')
//				printf("2 %d |%c%c%c%c|\n", div, s[i], s[i + (5 * 1)], s[i + (5 * 2)], s[i + (5 * 3)]);			{
				return ("J001112021");
			}
			if (mod <= 2 && s[i + 1] == '#')
		}
		return (part10(s, i, div, mod));
	}
//					printf("3\n");	return (NULL);
}

static const char	*part0(char *s, int i, int div, int mod)
{
	if (mod <= 2 && s[i + 1] == '#')
	{
		if (mod <= 1 && s[i + 2] == '#')
		{
				return ("I100010203");
			if (s[i + 2 + 5] == '#' && div < 3)
				return ("J300010212");
			if (s[i + 1 + 5] == '#' && div < 3)
//	printf("0\n");				return ("T000011102");
			if (s[i + 5] == '#' && div < 3)
				return ("L100100102");
		}
		if (s[i + 1 + 5] == '#' && div < 3)
		{
			if (mod <= 1 && s[i + 2 + 5] == '#')
				return ("Z000011112");
			if (s[i + 1 + 5] == '#')
				return ("L200011121");
			if (mod <= 1 && s[i + 2 + (2 * 5)] == '#' && div < 2)
				return ("L310110212");
		}
	}
	return (part1(s, i, div, mod));
}

const char			*recognize(char *s)
{
	int		i;
	int		div;
	int		mod;
	//const char	*tmp;

	while (s[i] != '#')
		i++;
	div = i / 5;
	mod = (i % 5);
	//tmp = part0(s, i, div, mod);
time_exe(__func__, cl(clock()));	//return(tmp);
	return(part0(s, i, div, mod));
}
