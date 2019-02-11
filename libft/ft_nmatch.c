/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:27:04 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/07 15:27:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		match2(char *s1, char *s2, int *i)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		(*i)++;
		return (0);
	}
	if (*s1 == '\0' && *s2 == '*')
		return (match2(s1, s2 + 1, i));
	if (*s1 == *s2 && *s1 == '*')
		return (match2(s1 + 1, s2, i));
	if (*s1 == *s2)
		return (match2(s1 + 1, s2 + 1, i));
	if (*s2 == '*' && *s1 != *s2)
		return (match2(s1 + 1, s2, i) || match2(s1, s2 + 1, i));
	return (0);
}

int				ft_nmatch(char *s1, char *s2)
{
	int i;

	i = 0;
	match2(s1, s2, &i);
	return (i);
}
