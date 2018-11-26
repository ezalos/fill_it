/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:02:54 by anonymou          #+#    #+#             */
/*   Updated: 2018/11/26 19:39:43 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	recognize(char *s)
{
	int		i;
	int		div;
	int		mod;

	i = 0;
	while (s[i] != '#')
		i++;
	div = i / 5;
	mod = i % 5;
	if (mod <= 2 && s[i + 1] == '#')
	{
		if (mod <= 1 && s[i + 2] == '#')
		{
			if (mod <= 0 && s[i + 3] == '#')
				return("I1");
			if (s[i + 2 + 5] == '#' && div < 3)
				return("J3");
			if (s[i + 1 + 5] && div < 3)
				return ("T0");
			if (s[i + 5] && div < 3)
				return ("L1");
		}
		if (s[i + 1 + 5] && div < 3)
		{
			if (mod <= 1 && s[i + 2 + 5])
				return("S0");
			if (s[i + 1 + 5])
				return ("O0");
			if (mod <= 1 && s[i + 2 + (2 * 5)] && div < 2)
				return ("L2");
		}
	}
	if (s[i + 5] && div < 3)
		if (mod <= 2 && s[i + 5 + 1])
			if (mod <= 1 && s[i + 5 + 2])
				return ("J1");
			if (s[i + (5 * 2) + 1] && div < 2)
				return ("Z1");
			if (s[i + (5 * 2) && div < 2]
				return ("T3");
		if (s[i + (5 * 2)] && div < 2)
			if (mod <= 2 && s[i + (5 * 2) + 1])
				return ("L0");
			if (s[i + (5 * 3)] && div < 1)
				return ("I0");
			if (mod >= 2 && s[i + (5 * 2) - 1])
				return ("J0");
			if (mod <= 2 && s[i + 1])
				return ("J2");
		if (mod >= 2 && s[i + 5 - 1])
			if (s[i + (5 * 2) - 1] && div < 2)
				return ("S1");
			if (mod >= 3 && s[i + 5 - 2)])
				return ("L3");
			if (s[i + (5 * 2)] && div < 2)
				return ("T1");
			if (mod <= 2 && s[i + 5 + 1])
				return ("T2");
			if (mod <= 2 && s[i + 1])
				return ("Z0");
	}
	return (NULL);
}
