/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/21 14:24:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**************************************
**                                  **
**  functions used to recognize   	**
**  tetrominos from valid file		**
**                                  **
**************************************
*/

#include "./head.h"

const char	*part10(char *s, int i, int div, int mod)
{
	if (mod >= 1 && s[i + 5 - 1] == '#')
	{
		if (div < 2 && s[i + (5 * 2) - 1] == '#')
			return ("Z110011120");
		if (mod >= 2 && s[i + 5 - 2] == '#')
			return ("L310110212");
		if (div < 2 && s[i + (5 * 2)] == '#')
			return ("T110011121");
		if (mod <= 2 && s[i + 5 + 1] == '#')
			return ("T210011112");
		if (mod <= 2 && s[i + 1] == '#')
			return ("S010011102");
	}
	return (NULL);
}

const char	*part1(char *s, int i, int div, int mod)
{
	if (div < 3 && s[i + 5] == '#')
	{
		if (mod <= 2 && s[i + 5 + 1] == '#')
		{
			if (mod <= 1 && s[i + 5 + 2] == '#')
				return ("J100101112");
			if (div < 2 && s[i + (5 * 2) + 1] == '#')
				return ("S100101121");
			if (div < 2 && s[i + (5 * 2)] == '#')
				return ("T300101120");
		}
		if (div < 2 && s[i + (5 * 2)] == '#')
		{
			if (mod <= 2 && s[i + (5 * 2) + 1] == '#')
				return ("L000102021");
			if (div < 1 && s[i + (5 * 3)] == '#')
				return ("I000102030");
			if (mod >= 1 && s[i + (5 * 2) - 1] == '#')
				return ("J001112021");
			if (mod <= 2 && s[i + 1] == '#')
				return ("J200100120");
		}
		return (part10(s, i, div, mod));
	}
	return (NULL);
}

const char	*part0(char *s, int i, int div, int mod)
{
	if (mod <= 2 && s[i + 1] == '#')
	{
		if (mod <= 1 && s[i + 2] == '#')
		{
			if (mod <= 0 && s[i + 3] == '#')
				return ("I100010203");
			if (div < 3 && s[i + 2 + 5] == '#')
				return ("J300010212");
			if (div < 3 && s[i + 1 + 5] == '#')
				return ("T000011102");
			if (div < 3 && s[i + 5] == '#')
				return ("L100100102");
		}
		if (div < 3 && s[i + 1 + 5] == '#')
		{
			if (mod <= 1 && s[i + 2 + 5] == '#')
				return ("Z000011112");
			if (s[i + 5] == '#')
				return ("O000100111");
			if (mod <= 2 && s[i + 1 + (2 * 5)] == '#')
				return ("L200011121");
		}
	}
	return (part1(s, i, div, mod));
}

const char	*recog(char *s)
{
	int		i;
	int		div;
	int		mod;

	i = 0;
	while (s[i] != '#')
		i++;
	div = i / 5;
	mod = (i % 5);
	return (part0(s, i, div, mod));
}
