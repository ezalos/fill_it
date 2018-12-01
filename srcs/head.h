/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:30:33 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/01 01:53:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>

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
	struct t_coord		*coord; //need to be a tab of 4:1
	struct s_piece		*next;
//	struct s_piece		*prev;
	struct s_head		*head;
}				t_piece;

typedef struct	s_sol
{
	char		*y_all_PxNx;
//	char		*x_P_J;
	int			current_path;
	int			nb_of_paths;
	s_sol		*next; //string of pointers to next possible solution from this one.
}				t_sol;

typedef struct	s_head
{
	char				**solution;
	int					size_square;
	int					p; //number of pieces
	int					tt_pos_all;
	int					possible_solutions;//initialize to 0
	int					first_try;//initialize to 0
//	int					y;//initialize to 0
	struct t_sol		*sol;
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
t_piece		*create_tetro(const char *buf, t_head *head);
t_piece		*ft_lstnew(const char *name, size_t name_size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
t_sol		*next_solve_step(t_head *head);
t_piece		*find_piece(t_head *head, int piece);
t_sol		*find_sol(t_head *head, int sol);

#endif
