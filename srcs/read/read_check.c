/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/09 04:10:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/head.h"

int		create_tetro(const char *name, t_head **head, char p)
{
time_exe(__func__, cl(clock()));
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

//	printf("Piece %s create\n", tetro->name);int ft_check_input(int fd, char *buf, t_head **head)
{
	int 	i;
	int		c_hash;

	while (read(fd, buf, 21) >= 20)
time_exe(__func__, cl(clock()));	{
		i = 0;
		c_hash = 0;
//		write(1, buf, 21);
		{
			if (((((i - 4) % 5) == 0) && i != 0) || i == 20)
			{
//		printf("one turn \n");				if ((buf[i] != '\n' || (buf[i] == '\0' && i == 20)))
					return (0); // ft_display_error(int error);
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
				return (0);	//	ft_display_error(int error)
		}
		if (c_hash != 4)
			return (0); // ft_display_error(int error);
//		write(1, buf, 21);
		if (!create_tetro(recognize(buf), head, (*head)->p++ + 'A'))
			return (0);
	}
	return (1);
}

t_head	*read_check(char *fillit)
	char 	*buf;
	t_head 	*head;
	int 	fd;

//	printf("OUT OF WHILE\n");	if (!(buf = (char *)malloc(sizeof(char) * 21)))
	if (!(fd = open((const char*)fillit, O_RDONLY)))
		return (NULL);
	if (!(head = (t_head*)malloc(sizeof(t_head))))
		return (NULL);
	head->next = NULL;
time_exe(__func__, cl(clock()));	head->p = 0;
		return (head);
	return (NULL);
