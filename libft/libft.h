/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/21 14:11:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);

int					ft_atoi(const char *src);
char				*ft_itoa(int n);

void				ft_lstadd(t_list **alst, t_list *new);
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
size_t				ft_count_lst(t_list *lst, size_t i);
void				ft_del(void *content, size_t size);
int					ft_factorial(int nb);
int					ft_fibonacci(int index);
t_list				*ft_find_lsth(t_list *lst, size_t umpteenth);
float				ft_fsqrt(int nb, int limite);
int					ft_intlen(int n);
void				ft_lstcutone(t_list **alst, void (*del)(void *, size_t));
int					ft_match(char *s1, char *s2);
int					ft_nb_char_to_int(char	c);
int					ft_nmatch(char *s1, char *s2);
int					*ft_nprime(int limite);
int					ft_power(int nb, int power);
void				ft_puttab(const char *s, int separation);
void				ft_puttab_nb(int length, int separation);
int					ft_round_upper(float i);
int					ft_round(float i);
char				*ft_pstrnstr(const char *m, const char *a, size_t len);
int					ft_patoi(const char *str);
int					ft_nb_char_to_int(char c);

#endif
