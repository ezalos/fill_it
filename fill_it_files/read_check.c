/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:18 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/09 18:14:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		create_tetro(const char *name, t_head **head, char p)
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
//	printf("Piece %s create\n", tetro->name);
	return (1);
}

int ft_check_input(int fd, char *buf, t_head **head)
{
	time_exe(__func__, cl(clock()));
	int 	i;
	int		yep;
	int		c_hash;
	char	p;
	int		destruction;

	destruction = 0;
	while ((yep = read(fd, buf, 21)) >= 20)
	{
//		printf("one turn \n");
		i = 0;
		c_hash = 0;
//		write(1, buf, 21);
		while (i < 21)
		{
			if (((((i - 4) % 5) == 0) && i != 0) || i == 20)
			{
				if ((buf[i] != '\n' || (buf[i] == '\0' && i == 20)))
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
//		printf("%d\n|%s|\n", yep, buf);
		if (yep > 19 && yep <= 21)
		{
			if (NULL == ft_strnstr(buf, "abc\n\n", yep))
				destruction = 0;
			else
				destruction = 1;
		}
	}
//	printf("OUT OF WHILE\n");
//	printf("%d\n", destruction);
	if (destruction || (*head)->next == NULL || yep > 0)
		return (0);
	return (1);
}

t_head	*read_check(char *fillit)
{
	time_exe(__func__, cl(clock()));
	char 	*buf;
	t_head 	*head;
	int 	fd;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
//	printf("mdr\n");
	if (!(fd = open((const char*)fillit, O_RDONLY)))
		return (NULL);
//	printf("lol\n");
	if (!(head = (t_head*)malloc(sizeof(t_head))))
		return (NULL);
	head->next = NULL;
	head->p = 0;
//	printf("weird\n");
	if (ft_check_input(fd, buf, &head))
		return (head);
	printf("error\n");
//		printf("pbm\n");
//	printf(_YELLOW "FT_READ RETURN 0\n" _RESET);
	return (NULL);
}
