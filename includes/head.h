/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:30:33 by aboitier          #+#    #+#             */
/*   Updated: 2018/12/27 01:20:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <string.h>
# include <time.h>
//# include "time_exe.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//COLORS IN PRINTF
# define COLOR

# ifndef COLOR
#  define _RED     ""
#  define _GREEN   ""
#  define _YELLOW  ""
#  define _BLUE    ""
#  define _MAGENTA ""
#  define _CYAN    ""
#  define _RESET   ""
# endif

# ifdef COLOR
#  define _RED     "\x1b[31m"
#  define _GREEN   "\x1b[32m"
#  define _YELLOW  "\x1b[33m"
#  define _BLUE    "\x1b[34m"
#  define _MAGENTA "\x1b[35m"
#  define _CYAN    "\x1b[36m"
#  define _RESET   "\x1b[0m"
# endif

typedef struct	s_coord
{
	int			y;
	int			x;
	int			j;
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

//print_debug.c
void		print_debug(t_head *head);
void		print_soltion_link_debug(t_head *head, int step, int current_path);

//un peu de tout ?
int			yx_to_j(int y, int x);
t_head		*read_check(char *fillit);
const char	*recognize(char *s);
int			float_to_int(float i);
float		f_sqrt(int nb, int limite);
int			size_square(int p);
void 		ft_bzero(void *s, int n);
void		*ft_memalloc(size_t size);
int			create_tetro(const char *name, t_head **head, char p);
t_piece		*ft_lstnew(const char *name, size_t name_size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
t_sol		*next_solve_step(t_head *head, int step);
t_piece		*find_piece(t_head *head, int piece);
t_sol		*find_sol(t_head *head, int sol);

//print tab_result
int			print_result(t_head *head);

//libft
size_t		ft_strlen(const char *s);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *str, int c, size_t n);
char		*ft_strstr(const char *meule_de_foin, const char *aiguille);
char		*ft_strdup(const char *src);

//float_to_int.c
 int		nb_char_to_int(char	c);
 int		ft_char_srch(char src, char *dlt);
 int		j_to_yx(t_head *head, int j, int o);

// setup.pieces
 int		coord_setup(t_piece *piece);
 void	pieces_yx(t_piece *tmp);
 int	size_pieces(char s, int size);
 void	p_yx(t_piece *piece, int y, int x);

// free
t_head	*restart_and_grow(t_head *head);
void	free_solsol(t_head *head);
void	free_linked_sol(t_sol **sol);
void	update_pieces(t_head *head);

 //setup.c
void	setup_pieces(t_head *head);
char	**malloc_solution(t_head *head);
t_head	*setup_head(t_head *head);
t_head	*setup_head_sol_part(t_head *head);

//binary
void	ft_putbinary_rev(char *str, int piece, int length);
int		deleter_of_binaries(t_head *head, int deepness, int position_choice);
char	binary_string_and(char *s1, char *s2, size_t length);
int		ft_iterative_power(int nb, int power);
void	binary_to_str(char *binary, int size, int binary_position);
void	write_binary(t_head *head);
int		binary_size(int length);
char	**malloc_binary(t_head *head);

//solve.c
int		solve_solution(t_head *head, int deepness);
int		how_many_paths(t_head *head, int deepness);//need to be values that only live in the function
int		deleter_of_competitors(t_head *head, int deepness, int position_choice);
void	write_solutions(t_head *head);

//time_exe
struct	s_time	*time_exe(const char* s, long double t);
long double			cl(clock_t t);
void			print_time(struct s_time *time);

#endif
