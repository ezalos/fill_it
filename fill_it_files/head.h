/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:30:33 by aboitier          #+#    #+#             */
/*   Updated: 2019/01/21 13:48:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

/*
**			-------
**			 BONUS
**			-------
**														ONPTION		OFFPTION
**
**	has magnificient colors								YES			NO
**	solution is displayed in a friendly format			YES			NO
** 	show time taken for each function 					YES			NO
**	can show the logic of the program					YES			NO
**	allow follow-up of solve on each step				YES			NO
**	has been coded with a lot of love					YES			NO
**	can pass moulinette									NO			YES
**
**	Please, only use the commands "make offption" & "make onption"
**	to pass from one code to the other.
**
**	Thank you
*/

/*
******************************************************************************
******************************************************************************
**																			**
**								--------									**
**								INCLUDES									**
**								--------									**
**																			**
******************************************************************************
******************************************************************************
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./../libft/libft.h"

# define OFFPTION

# ifdef ONPTION
#  include "../.annex/time/time_exe.h"
# endif

/*
******************************************************************************
******************************************************************************
**																			**
**								----------									**
**								STRUCTURES									**
**								----------									**
**																			**
******************************************************************************
******************************************************************************
*/
typedef struct			s_coord
{
	int					y;
	int					x;
	int					j;
}						t_coord;

typedef struct			s_piece
{
	char				*name;
	int					y_size;
	int					x_size;
	int					pc_pos;
	int					tt_pos;
	int					i;
	t_coord				*coord[4];
	struct s_piece		*next;
}						t_piece;

typedef struct			s_sol
{
	char				*y_all_pxnx;
	int					current_path;
	int					nb_of_paths;
	struct s_sol		*sol;
}						t_sol;

typedef struct			s_head
{
	char				**solution;
	int					sqsize;
	int					p;
	char				*y_all_pxnx;
	int					tt_pos_all;
	int					pos_sol;
	int					config;
	t_sol				*sol;
	t_piece				*next;
}						t_head;

/*
******************************************************************************
******************************************************************************
**																			**
**								-------										**
**								OPTIONS										**
**								-------										**
**																			**
******************************************************************************
******************************************************************************
*/
# ifdef ONPTION
#  define OPTION	1
#  define _RED		"\x1b[31m"
#  define _GREEN	"\x1b[32m"
#  define _YELLOW	"\x1b[33m"
#  define _BLUE		"\x1b[34m"
#  define _MAGENTA	"\x1b[35m"
#  define _CYAN		"\x1b[36m"
#  define _RESET	"\x1b[0m"

void					print_debug(t_head *head);
void					print_soltion_link_debug(t_head *head,
		int step, int current_path);
void					print_advance(t_head *head, int deepness,
		int threshold);
void					print_debug(t_head *head);
void					print_advance(t_head *head, int deepness,
		int threshold);

void					ft_putchar_color(char c);
void					ft_put(const char *s, int separation);
void					print_pieces_color(t_head *head, char **tab_result);

# endif

# ifdef OFFPTION
#  define OPTION	0
#  define _RED		""
#  define _GREEN	""
#  define _YELLOW	""
#  define _BLUE		""
#  define _MAGENTA	""
#  define _CYAN		""
#  define _RESET	""
# endif

/*
******************************************************************************
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
******************************************************************************
*/

/*
**************
**	FREE	**
**************
*/
void					*free_head(t_head **head);
void					*free_tab_str(char ***ptr_on_tab, int lines);
t_head					*restart_and_grow(t_head *head);

void					*free_linked_pieces(t_piece **next);

void					*free_linked_sol(t_sol **sol);
void					*free_linked_sols(t_sol **sol);
void					*free_solsol(t_head *head);
void					*free_solsols(t_head *head);

/*
**************
** LOGISTIC **
**************
*/
int						binary_size(int length);
void					binary_to_str(char *binary,	int binary_position);
char					binstrand(char *s1, char *s2, size_t length);
char					binary_string_and_start(char *s1, char *s2,
size_t length, size_t start);

t_piece					*find_piece(t_head *head, int piece);
t_sol					*find_sol(t_head *head, int sol);
t_piece					*find_piece_hash(t_head *head, int piece);
t_sol					*find_sol_hash(t_head *head, int sol);

int						yx_to_j(int y, int x);
int						j_to_yx(t_head *head, int j, int o);
int						ft_iterative_power(int nb, int power);

/*
**************
**	PRINT	**
**************
*/
void					print_pieces(t_head *head, char **tab_result);
int						pos_one_binary(char *str, size_t length,
		size_t umpteenth);
void					show_pieces_binary(t_head *head, char **tab_result);
int						print_result(t_head *head);

/*
**************
**	READ	**
**************
*/
int						cre_tetro(const char *name, t_head **head);
int						check_two(char *buf, int i, int c_hash);
int						ft_check_input(int fd, char *buf, t_head **head);
t_head					*read_check(char *fillit);

const char				*part10(char *s, int i, int div, int mod);
const char				*part1(char *s, int i, int div, int mod);
const char				*part0(char *s, int i, int div, int mod);
const char				*recog(char *s);

/*
**************
**	SETUP	**
**************
*/
void					while_in_write_binary(t_head *head,
		t_piece *piece, int *box);
void					write_binary(t_head *head);
char					**malloc_binary(t_head *head);

void					update_pieces(t_head *head);
void					p_yx(t_piece *piece, int y, int x);
int						size_pieces(char s, int size);
void					pieces_yx(t_piece *tmp);
int						coord_setup(t_piece *piece);

t_sol					*next_solve_step(t_head *head, int step);
void					*setup_pieces(t_head *head);
t_head					*setup_head_sol_part(t_head *head);
t_head					*setup_(t_head *head);

/*
**************
**	SOLVE	**
**************
*/
int						deleter_of_binaries(t_head *head,
		int depth, int pos_choy);
int						how_many_paths(t_head *head, int deepness);
void					sol_turn_mem(t_head *head, int deepness);
int						solve_solution(t_head *head, int deepness);

#endif
