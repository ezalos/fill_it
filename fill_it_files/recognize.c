/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:41:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 14:05:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static const char	*part10(char *s, int i, int div, int mod)
{ 
	time_exe(__func__, clock()); 
	if (mod >= 1 && s[i + 5 - 1] == '#')
	{
		if (s[i + (5 * 2) - 1] == '#' && div < 2)
			return ("Z110011120");
		if (mod >= 2 && s[i + 5 - 2] == '#')
			return ("L310110212");
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
	time_exe(__func__, clock()); 
	if (s[i + 5] == '#' && div < 3)
	{
		if (mod <= 2 && s[i + 5 + 1] == '#')
		{
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
				return ("L000102021");
			if (s[i + (5 * 3)] == '#' && div < 1)
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

static const char	*part0(char *s, int i, int div, int mod)
{ 
	time_exe(__func__, clock()); 
	if (mod <= 2 && s[i + 1] == '#')
	{
		if (mod <= 1 && s[i + 2] == '#')
		{
			if (mod <= 0 && s[i + 3] == '#')
				return ("I100010203");
			if (s[i + 2 + 5] == '#' && div < 3)
				return ("J300010212");
			if (s[i + 1 + 5] == '#' && div < 3)
				return ("T000011102");
			if (s[i + 5] == '#' && div < 3)
				return ("L100100102");
		}
		if (s[i + 1 + 5] == '#' && div < 3)
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

const char			*recog(char *s)
{ 
	time_exe(__func__, clock()); 
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
