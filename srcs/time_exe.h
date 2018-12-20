/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:51:05 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/20 13:01:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_EXE_H
# define TIME_EXE_H

# include "head.h"

# include <time.h>
# include <stdlib.h>
# include <stdio.h>

# define _RED     "\x1b[31m"
# define _GREEN   "\x1b[32m"
# define _YELLOW  "\x1b[33m"
# define _BLUE    "\x1b[34m"
# define _MAGENTA "\x1b[35m"
# define _CYAN    "\x1b[36m"
# define _RESET   "\x1b[0m"

typedef struct			s_time
{
	long double			t;
	long double			percent;
	char				*name;
	struct	s_time		*next;
}						t_time;

//main
t_time	*time_exe(const char* s, long double t);
long double	cl(clock_t t);
void	print_time(t_time *time);

//others
t_time	*time_link_creation(const char* s, long double t);
//char	*ft_strdup(const char *s);
//char	*ft_strstr(const char *meule_de_foin, const char *aiguille);

#endif
