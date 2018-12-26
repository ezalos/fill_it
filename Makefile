# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2018/12/26 17:56:38 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fill_it

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

HEAD = ./includes/

FT_H = libft.h

SRC_PATH0 = srcs/
SRC_PATH1 = srcs/read/
SRC_PATH2 = srcs/setup/
SRC_PATH3 = srcs/solve/
SRC_PATH4 = srcs/print/
SRC_PATH5 = srcs/free/
SRC_PATH6 = srcs/logistics/

SRCS =	$(SRCS0) $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4) $(SRCS5) $(SRCS6)

SRCS0 = main
SRCS1 = read_check recognize
SRCS2 = setup setup_pieces
SRCS3 =	solve binary
SRCS4 = print_debug printing_the_result
SRCS5 = free_all
SRCS6 = float_to_int list_func

A_SRC =	$(addsuffix .c, $(addprefix $(SRC_PATH0), $(SRCS0))\
						$(addprefix $(SRC_PATH1), $(SRCS1))\
						$(addprefix $(SRC_PATH2), $(SRCS2))\
						$(addprefix $(SRC_PATH3), $(SRCS3))\
						$(addprefix $(SRC_PATH4), $(SRCS4))\
						$(addprefix $(SRC_PATH5), $(SRCS5))\
						$(addprefix $(SRC_PATH6), $(SRCS6)))

OBJS = $(patsubst %, %.o,$(SRCS))

all :	$(NAME)

$(NAME):	#$(OBJS)
			@echo "Creating $(NAME)"
			@$(CC) -o $(NAME) $(A_SRC)

$(OBJS):
			@echo "Creating objects"
			@$(CC) -c $(CFLAGS) $(patsubst %,%.c,$(SRCS))

d :
			@$(CC) -c $(DFLAGS) $(patsubst %,%.c,$(SRCS))
			@$(CC) -o $(NAME) $(OBJS)

clean :
	@echo "Cleaning objects"
	@rm -f $(OBJS) libft.h.gch

fclean : clean
	@echo "Cleaning project"
	@rm -f $(NAME)

re : fclean all

git :
		@git add *
		@git status
		@git commit -am "Makefile automated push"
		@git push

check1 :
		bash /Users/ldevelle/42/42FileChecker/42FileChecker.sh

check2 :
		yes n | bash /Users/ldevelle/42/Libftest/grademe.sh

.PHONY : clean fclean re all d git check1 check2
