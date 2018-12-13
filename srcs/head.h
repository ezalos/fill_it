/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:30:33 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/13 21:34:37 by ldevelle         ###   ########.fr       */
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
	char		letter;
	int			y_size; //piece dimension
	int			x_size;
	int			pc_pos; //number of placement possible for this piece
	int			tt_pos; //total sum of pc_pos until this struct, actual one included //initialize to 0
	int			i; //initialize to 0
	t_coord		*coord[4]; //need to be a tab of 4:1
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
	struct s_sol		*sol; //string of pointers to next possible solution from this one.
}				t_sol;

typedef struct	s_head
{
	char				**solution;
	int					size_square;
	int					p; //number of pieces
	char				*y_all_PxNx;
	int					tt_pos_all;
	int					possible_solutions;//initialize to 0
	int					the_choosen_configuration;//initialize to 0
//	int					y;//initialize to 0
	t_sol		*sol;
	t_piece		*next;
}				t_head;

int			yx_to_j(int y, int x);
t_head		*ft_read_check(char *fillit);
const char	*recognize(char *s);
int			float_to_int(float i);
float		f_sqrt(int nb, int limite);
int			size_square(int p);
void 		ft_bzero(void *s, int n);
void		*ft_memalloc(size_t size);
int			create_tetro(const char *name, t_head **head, char p);
t_piece		*ft_lstnew(const char *name, size_t name_size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
t_sol		*next_solve_step(t_head *head);
t_piece		*find_piece(t_head *head, int piece);
t_sol		*find_sol(t_head *head, int sol);
size_t		ft_strlen(const char *s);

//float_to_int.c
 int		nb_char_to_int(char	c);
 int		ft_char_srch(char src, char *dlt);

// setup.pieces
 int		coord_setup(t_piece *piece);
 void	pieces_yx(t_piece *tmp);
 int	size_pieces(char s, int size);
 void	p_yx(t_piece *piece, int y, int x);

 //setup.c
void	setup_pieces(t_head *head);
char	**malloc_solution(t_head *head);
t_head	*setup_head(t_head *head);

//solve.c
int		solve_solution(t_head *head, int deepness);
int		how_many_paths(t_head *head, int deepness);//need to be values that only live in the function
int		deleter_of_competitors(t_head *head, int deepness, int position_choice);
void	write_solutions(t_head *head);



#endif
