# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2018/12/27 00:52:18 by ldevelle         ###   ########.fr        #
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
FT_H = head.h

LIBFOLD =	./annex/libft/
LIB =		libft.a

A_SRC_P	=	$(SRC_PATH0), $(SRC_PATH1), $(SRC_PATH2), $(SRC_PATH3),\
 			$(SRC_PATH4), $(SRC_PATH5), $(SRC_PATH6)

SRC_PATH0 = srcs/
SRC_PATH1 = srcs/read/
SRC_PATH2 = srcs/setup/
SRC_PATH3 = srcs/solve/
SRC_PATH4 = srcs/print/
SRC_PATH5 = srcs/free/
SRC_PATH6 = srcs/logistics/

FOLD0 = ./fill_it_files/
FOLD1 = ./libft/

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

bhead :
		@sed -i "s~../../includes/head.h~head.h~g" $(A_SRC)

ahead :
		@sed -i "s~head.h~../../includes/head.h~g" $(patsubst %,$(FOLD0)%.c,$(SRCS))

before :	bhead
			@mkdir $(FOLD0) $(FOLD1)
			@mv -f $(HEAD)$(FT_H) $(FOLD0)
			@mv -f $(A_SRC) $(FOLD0)
			@mv -f $(LIBFOLD) $(FOLD1)
			@rm -rf $(SRC_PATH) $(HEAD)

after :	ahead
		@mkdir	$(SRC_PATH0) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
				$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6) $(HEAD)
		@mv -f $(FT_H) $(HEAD)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS0)) $(SRC_PATH0)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS1)) $(SRC_PATH1)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS2)) $(SRC_PATH2)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS3)) $(SRC_PATH3)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS4)) $(SRC_PATH4)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS5)) $(SRC_PATH5)
		@mv -f $(FOLD0)$(patsubst %, %.c, $(SRCS6)) $(SRC_PATH6)
		@mv -f $(FOLD0)$(FOLD1) $(LIBFOLD)
		@rm -rf $(FOLD0) $(FOLD1)

hide :
		grep -n  printf ./*/*.c >> ./annex/show/.saves/.gres.txt

show :
		bash ./show/.show.sh

.PHONY : clean fclean re all d git check1 check2
