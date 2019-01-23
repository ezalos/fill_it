/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/23 01:37:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Functions used as a parser and to check input validity.
**	___________________________________________________________________________
**	cre_tetro : allocates memory for a recognized tetromino while naming it
** 	check_two : checks for the number of '#', '\n'
** 				checks the positions of '\n', '\0'
**				checks that we only read valid characters such as '.',
** 				'\n', '\0' and '#'
**	ft_check_input : reads in a securitized manner from the 'fd' and checks
** 					 that '\0' is the final char
**	ft_read_check : opens the file, creates and frees the 'buf' to make the
**					read function operates and initializes 'head'
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

int		check_two(char *buf, int c_hash)
{
	int i;

	i = 0;
	c_hash = 0;
	while (i < 21)
	{
		if ((((i - 4) % 5) == 0) && i != 0)
		{
			if (buf[i] != '\n')
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
		else if ((buf[i] == 0 || buf[i] == '\n') && i == 20)
			return (c_hash);
		else
			return (0);
	}
	return (c_hash);
}

int		ft_check_input(int fd, char *buf, t_head **head)
{
	int		ret;
	int		c_hash;
	int		dest;

	dest = 0;
	while ((ret = (int)read(fd, buf, 21)) >= 20)
	{
		c_hash = check_two(buf, c_hash);
		if (c_hash != 4 || !cre_tetro(recog(buf), head))
			return (0);
		ft_bzero((void*)buf, (size_t)21);
		(*head)->p++;
		if (ret != 0)
			dest = ret;
	}
	ft_strdel(&buf);
	if ((*head)->next == NULL || ret > 0 || dest == 21 || (*head)->p > 26)
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
	if (!(buf = ft_strnew((size_t)21)))
		return (ft_putstr_rnull("error\n"));
	if (!(head = (t_head*)malloc(sizeof(t_head))))
	{
		ft_strdel(&buf);
		return (ft_putstr_rnull("error\n"));
	}
	init_head(head);
	if (ft_check_input(fd, buf, &head))
		return (head);
	free(head);
	return (ft_putstr_rnull("error\n"));
}
