/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/21 14:07:37 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**************************************
**                                  **
**  functions used as a parser   	**
**  and to check input validity		**
**                                  **
**************************************
*/

#include "./head.h"

int		cre_tetro(const char *name, t_head **head)
{
	t_piece *tetro;

	if (name == NULL)
		return (0);
	if ((*head)->next == NULL)
	{
		if (!((*head)->next = (t_piece*)malloc(sizeof(t_piece))))
			return (0);
		(*head)->next->name = (char*)name;
		(*head)->next->next = NULL;
		return (1);
	}
	tetro = (*head)->next;
	while (tetro->next != NULL)
		tetro = tetro->next;
	if (!(tetro->next = (t_piece*)malloc(sizeof(t_piece))))
	{
		free_linked_pieces(&(*head)->next);
		return (0);
	}
	tetro = tetro->next;
	tetro->name = (char*)name;
	tetro->next = NULL;
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
	int		i;
	int		ret;
	int		c_hash;
	int		dest;

	dest = 0;
	while ((ret = (int)read(fd, buf, 21)) >= 20)
	{
		i = 0;
		c_hash = 0;
		c_hash = check_two(buf, i, c_hash);
		if (c_hash != 4 || !cre_tetro(recog(buf), head))
			return (0);
		(*head)->p++;
		if (ret != 0)
			dest = ret;
	}
	if ((*head)->next == NULL || ret > 0 || dest == 21)
		return (0);
	return (1);
}

t_head	*read_check(char *fillit)
{
	char	*buf;
	t_head	*head;
	int		fd;

	if (0 > (fd = open((const char*)fillit, O_RDONLY)))
		return (ft_putstr_rnull("usage: ./fillit ./path/file\n"));
	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (ft_putstr_rnull("error\n"));
	if (!(head = (t_head*)malloc(sizeof(t_head))))
	{
		ft_strdel(&buf);
		return (ft_putstr_rnull("error\n"));
	}
	head->next = NULL;
	head->p = 0;
	if (ft_check_input(fd, buf, &head))
		return (head);
	ft_strdel(&buf);
	free(head);
	return (ft_putstr_rnull("error\n"));
}
