/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/10 22:39:41 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		cre_tetro(const char *name, t_head **head, char p)
{
	time_exe(__func__, cl(clock()));
	t_piece *tetro;

	if (name == NULL)
		return (0);
	if ((*head)->next == NULL)
	{
		if (!((*head)->next = (t_piece*)malloc(sizeof(t_piece))))
			return (0);
		(*head)->next->name = (char*)name;
		(*head)->next->next = NULL;
		(*head)->next->letter = p;
		return (1);
	}
	tetro = (*head)->next;
	while (tetro->next != NULL)
		tetro = tetro->next;
	if (!(tetro->next = (t_piece*)malloc(sizeof(t_piece))))
		return (0);
	tetro = tetro->next;
	tetro->name = (char*)name;
	tetro->next = NULL;
	tetro->letter = p;
	return (1);
}

int		check_two(char *buf, int i, int c_hash)
{
	while (i < 21)
	{
		if (((((i - 4) % 5) == 0) && i != 0) || i == 20)
		{
			if ((buf[i] != '\n' || (buf[i] == '\0' && i == 20)))
				return (0);
			i++;
		}
		else if (buf[i] == '#')
		{
			c_hash++;
			i++;
		}
		else if (buf[i] == '.')
			i++;
		else
			return (0);
	}
	return (c_hash);
}

int		ft_check_input(int fd, char *buf, t_head **head)
{
	time_exe(__func__, cl(clock()));
	int		i;
	int		ret;
	int		c_hash;
	int		dest;

	dest = 0;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		i = 0;
		c_hash = 0;
		c_hash = check_two(buf, i, c_hash);
		if (!cre_tetro(recog(buf), head, (*head)->p++ + 'A') || c_hash != 4)
			return (0);
		if (ret != 0)
			dest = ret;
	}
	if ((*head)->next == NULL || ret > 0 || dest == 21)
		return (0);
	return (1);
}

t_head	*read_check(char *fillit)
{
	time_exe(__func__, cl(clock()));
	char	*buf;
	t_head	*head;
	int		fd;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	if (!(fd = open((const char*)fillit, O_RDONLY)))
		return (NULL);
	if (!(head = (t_head*)malloc(sizeof(t_head))))
		return (NULL);
	head->next = NULL;
	head->p = 0;
	if (ft_check_input(fd, buf, &head))
		return (head);
	ft_putstr("error\n");
//	printf(_YELLOW "FT_READ RETURN 0\n" _RESET);
	return (NULL);
}
