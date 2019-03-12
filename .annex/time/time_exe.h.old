/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:51:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:52:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_EXE_H
# define TIME_EXE_H

# include "../../libft/libft.h"
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

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

typedef struct			s_time
{
	double				t;
	int					nb_call;
	char				*name;
	struct	s_time		*next;
}						t_time;

//main
t_time	*time_exe(const char* s, double t);
double	cl(clock_t t);
void	print_time(t_time *time);

//others
static t_time	*time_link_creation(const char* s, double t);

//libft
size_t		ft_strlen(const char *s);
char		*ft_strstr(const char *meule_de_foin, const char *aiguille);
char		*ft_strdup(const char *src);
int			ft_intlen(int n);
int			ft_strcmp(const char *s1, const char *s2);


#endif
