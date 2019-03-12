/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 22:29:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;



typedef	struct		s_tab
{
	struct s_tab	*dir[4];
	void			*content;
	size_t			content_size;
}					t_tab;

/*
**	dir[0] : up;
**	dir[1] : right;
**	dir[2] : down;
**	dir[3] : left;
*/

# define BUFF_SIZE 256

# ifndef P_MALLOC
#  define P_MALLOC nalloc
# endif

//# define LINUX


# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif


# ifdef LINUX
#  define intmax_t long long
#  define uintmax_t unsigned long long
# endif

#  define C_RED			write(1, "\x1b[31m", 5);
#  define C_GREEN		write(1, "\x1b[32m", 5);
#  define C_BLUE		write(1, "\x1b[34m", 5);
#  define C_YELLOW		write(1, "\x1b[33m", 5);
#  define C_BLUE		write(1, "\x1b[34m", 5);
#  define C_MAGENTA		write(1, "\x1b[35m", 5);
#  define C_CYAN		write(1, "\x1b[36m", 5);
#  define C_RESET		write(1, "\x1b[0m", 5);
#  define C_BROWN		write(1, "\x1b[38;2;238;205;163m", 19);
#  define C_PINK		write(1, "\x1b[38;2;239;100;100m", 19);
#  define C_PURPLE		write(1, "\x1b[38;2;101;78;163m", 18);
#  define C_ORANGE		write(1, "\x1b[38;2;155;75;43m", 17);
#  define C_TURQUOISE	write(1, "\x1b[38;2;68;140;121m", 18);
#  define CURSOR_RESET	write(1, "\033[0;0H", 6);
#  define CURSOR_LOAD	write(1, "\033[u", 3);
#  define CURSOR_SAVE	write(1, "\033[s", 3);
#  define CLEAR_SCREEN	write(1, "\033[2J", 4);

int					get_next_line(const int fd, char **line);

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);

int					ft_atoi(const char *src);
char				*ft_itoa(int n);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);

void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char	*haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				*ft_putstr_rnull(char const *s);
int					ft_putstr_r0(char const *s);

int					ft_char_srch(const char src, const char *dlt);
size_t				ft_lst_count(t_list *lst, size_t i);
void				ft_del(void *content, size_t size);
int					ft_factorial(int nb);
int					ft_fibonacci(int index);
t_list				*ft_lstfind_th(t_list *lst, size_t umpteenth);
float				ft_fsqrt(int nb, int limite);
int					ft_intlen(int n);
void				ft_lstcutone(t_list **alst, void (*del)(void *, size_t));
int					ft_match(char *s1, char *s2);
int					ft_nb_char_to_int(char	c);
int					ft_nmatch(char *s1, char *s2);
int					*ft_nprime(int limite);
intmax_t			ft_power(int nb, int power);
size_t				ft_puttab(const char *s, size_t separation);
size_t				ft_puttab_len(size_t length, size_t separation, size_t n);
int					ft_round_upper(float i);
int					ft_round(float i);
char				*ft_pstrnstr(const char *m, const char *a, size_t len);
int					ft_patoi(const char *str);
int					ft_nb_char_to_int(char c);
int					place_cursor(size_t line, size_t column);
intmax_t			ft_random(intmax_t min, intmax_t max, intmax_t rando,
					size_t len);
void				ft_swap(void *one, void *two, size_t size);
size_t				ft_strnlen(const char *s, size_t size);
char				*ft_u_nb_to_a(uintmax_t n, size_t base);
char				*ft_nb_to_a(intmax_t n, size_t base);
size_t				ft_nb_len(intmax_t n, size_t base);
size_t				ft_u_nb_len(uintmax_t nb, size_t base);
void				ft_putbnbr_str(int i, uintmax_t n, char *nb, size_t base);
void				ft_putnstr(char const *s, size_t n);
t_list				*ft_lstnew_ptr(void const *content, size_t content_size);
void				ft_lstadd_here(t_list *alst, t_list *new);
t_list				*ft_lst_reach_end(t_list *alst);
void				ft_lstadd_end(t_list *alst, t_list *new);
void				ft_lstadd(t_list **alst, t_list *new, int position);
void				ft_lstadd_start(t_list **alst, t_list *new);
int					ft_rgb_color(int red, int green, int blue);
char				*ft_strjoin_multi(size_t nb, ...);
void				ft_strdel_multi(size_t nb, ...);
void				ft_putstr_color(char const *s, int r, int g, int b);
int					ft_rgb_bcolor(int red, int green, int blue);
void				ft_wait_pls(uintmax_t wait);
void				ft_print_address_color(intmax_t nb);
int					ft_tab_print_one_elmnt(t_tab *tmp, size_t lin, size_t col, int structh);
int					ft_tab_print_dir(t_tab *tab, size_t dir, int lin);
void				ft_tabiter(t_tab *tab, size_t dir, int(*f)(t_tab *, size_t, int), size_t dirf);
t_tab				*ft_tabnew_ptr(void const *content, size_t content_size);
size_t				ft_tab_lendir(t_tab *tab, size_t dir);
t_tab				*ft_tab_dirth(t_tab *tab, size_t dir, size_t umpteenth);
size_t				ft_tab_dir_clock(size_t dir);
size_t				ft_tab_dir_nclock(size_t dir, size_t move);
size_t				ft_tab_dir_rclock(size_t dir);
size_t				ft_tab_dir_reverse(size_t dir);
t_tab				*ft_tabnew_dir(size_t len, size_t dir);
int					ft_tab_connect_dir(size_t dir_line, t_tab *line_one, t_tab *line_two, size_t dir_connec);
t_tab				*ft_tab_square_it(t_tab *tab, size_t dir);
void				*nalloc(size_t size_content);
void				*cnalloc(const void *content, size_t size_content);
void				ft_clean_garbage(void);
void				ft_burn_garbage(char *str);
size_t				ft_lst_free(t_list **delete_me);
t_list				**ft_garbage_collector(void);
void				ft_tabadd(t_tab	**tab, t_tab *new, size_t dir, int umpteenth);
void				ft_tabadd_here(t_tab *alst, t_tab *new, size_t dir);
void				ft_tabadd_end(t_tab *alst, t_tab *new, size_t dir);
void				ft_tabadd_start(t_tab **alst, t_tab *new, size_t dir);
t_tab				*ft_tab_reach_end(t_tab *tab, size_t dir);
t_tab				*ft_tabnew_rectangle(size_t x_axis, size_t y_axis, size_t x_dir);
t_tab				*ft_tab_access(t_tab *tab, int dir_y, int dir_x, int rot);
size_t				ft_tab_delete_row_len(t_tab *tab, size_t dir, size_t len);
size_t				ft_tab_delete_row(t_tab *tab, size_t dir);
void				ft_tab_connect_structs(t_tab *tab_one, t_tab *tab_two, size_t dir_one);
t_tab				*ft_tab_cutone(t_tab *to_cut);
size_t				ft_tabloop_lendir(t_tab *tab, size_t dir);
size_t				ft_tabloop_it(t_tab *tab, size_t dir);

#endif
