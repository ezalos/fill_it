/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:36:11 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:45:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static int	count_letters(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static char	**free_scnd(char **s, size_t i)
{
	while (i-- != 0)
		ft_strdel(&(s[i]));
	ft_memdel((void**)&s);
	s = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		word;
	int		letter;
	int		i;

	if (s == NULL)
		return (NULL);
	i = -1;
	word = count_words(s, c);
	if (!(words = (char**)P_MALLOC(sizeof(char*) * (word + 1))))
		return (NULL);
	while (++i < word)
	{
		while (*s == c)
			s++;
		letter = count_letters(s, c);
		if (!(words[i] = ft_strsub(s, 0, letter)))
			return (free_scnd(words, i));
		s += letter;
	}
	words[i] = NULL;
	return (words);
}
