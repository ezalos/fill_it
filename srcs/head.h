/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:30:33 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/29 07:05:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct	s_coord
{
	int			y;
	int			x;
}				t_coord;

typedef struct	s_piece
{
	char		*name;
	int			y_size; //piece dimension
	int			x_size;
	int			pc_pos; //number of placement possible for this piece
	int			tt_pos; //total sum of pc_pos until this struct, actual one included //initialize to 0
	int			i; //initialize to 0
	t_coord		*coord; //need to be a tab of 4:1
	t_piece		*next;
	t_piece		*prev;
	t_piece		*head;
}				t_piece;

typedef struct	s_head
{
	char				**solution;
	int					size_square;
	int					p; //number of pieces
	int					tt_pos_all;
	int					o;//initialize to 0
	int					x;//initialize to 0
	int					y;//initialize to 0
	struct t_piece		*next;
}				t_head;

char		*ft_read_check(char *fillit);
const char	*recognize(char *s);
int			float_to_int(float i);
float		f_sqrt(int nb, int limite);
int			size_square(int p);
int			size_pieces(char *s, int size);
void 		ft_bzero(void *s, int n);
void		*ft_memalloc(size_t size);
t_piece		*ft_lstnew(const char *name, size_t name_size);
void		*ft_memcpy(void *dest, const void *src, size_t n);



#endif
