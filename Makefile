# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/02 19:46:52 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fill_it.out

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

HEAD = ./includes
FT_H = head.h

LIBFOLD =	./annex/libft/
LIB =		libft.a

A_SRC_P	=	srcs $(SRC_PATH0) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
 			$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6)

SRC_PATH0 = srcs/main/
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

TIME_EXE = ./annex/time/time_exe.c

A_SRC =	$(addsuffix .c, $(addprefix $(SRC_PATH0), $(SRCS0))\
						$(addprefix $(SRC_PATH1), $(SRCS1))\
						$(addprefix $(SRC_PATH2), $(SRCS2))\
						$(addprefix $(SRC_PATH3), $(SRCS3))\
						$(addprefix $(SRC_PATH4), $(SRCS4))\
						$(addprefix $(SRC_PATH5), $(SRCS5))\
						$(addprefix $(SRC_PATH6), $(SRCS6)))

OBJS = $(patsubst %, %.o,$(SRCS))

TEMPORAIRE = intlen memalloc memcpy memset putchar putnbr putstr strcmp strdup strlen strstr

PIECE = ./annex/tests/good/fit/6_0

GREEN   = '\x1b[32m'
RED     = '\x1b[31m'
END     = '\x1b[0m'

all :	$(NAME)

$(NAME):
			@$(CC) $(A_SRC) $(TIME_EXE) $(patsubst %, ./annex/libft/ft_%.c,$(TEMPORAIRE)) -o $(NAME)
			@echo "$(GREEN)$(NAME) has been created $(END)"
#			@cd libft && $(MAKE)
			@echo "$(GREEN) $(LIB) has been created $(END)"

d :
			@$(CC) -c $(DFLAGS) $(patsubst %,%.c,$(A_SRC))
			@$(CC) $(A_SRC) -o $(NAME)

clean :
	@echo "$(RED) Objects have been removed $(END)"
	@rm -f $(OBJS)

fclean : clean
	@echo "$(RED) Project has been removed $(END)"
	@rm -f $(NAME)

re : fclean all

git :
		@git add *
		@git status
		@git commit -am "Makefile automated push"
		@git push

testg :	re
		./$(NAME) $(PIECE)

test :	re
		./$(NAME) ./annex/tests/good/unfit/3_0

testb :	re
		./$(NAME) ./annex/tests/bad/64_O0

testg6 :	re
		./$(NAME) ./annex/tests/good/fit/6_0

testg7 :	re
		./$(NAME) ./annex/tests/good/fit/7_0

testg12 :	re
		./$(NAME) ./annex/tests/good/fit/12_0

check1 :
		bash /Users/ldevelle/42/42FileChecker/42FileChecker.sh

check2 :
		yes n | bash /Users/ldevelle/42/Libftest/grademe.sh

bhead :
		@sed -i '' "s~../../includes/head.h~head.h~g" $(A_SRC)
		@sed -i '' "s~../../includes/head.h~../fill_it_files/head.h~g" $(patsubst %, $(LIBFOLD)ft_%.c,$(TEMPORAIRE))

ahead :
		@sed -i '' "s~head.h~../../includes/head.h~g" $(patsubst %,$(FOLD0)%.c,$(SRCS))
		@sed -i '' "s~../fill_it_files/head.h~../../includes/head.h~g" $(patsubst %, $(FOLD1)ft_%.c,$(TEMPORAIRE))

before :	bhead
			@mkdir $(FOLD0) $(FOLD1)
			@mv -f $(HEAD)/$(FT_H) $(FOLD0)
			@mv -f $(A_SRC) $(FOLD0)
			@mv -f $(LIBFOLD) ./
			@rm -rf $(A_SRC_P) $(HEAD)

after :	ahead
		@mkdir $(A_SRC_P) $(HEAD)
		@mv -f $(FOLD0)$(FT_H) $(HEAD)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS0)) $(SRC_PATH0)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS1)) $(SRC_PATH1)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS2)) $(SRC_PATH2)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS3)) $(SRC_PATH3)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS4)) $(SRC_PATH4)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS5)) $(SRC_PATH5)
		@mv -f $(patsubst %, $(FOLD0)%.c, $(SRCS6)) $(SRC_PATH6)
		@mv -f $(FOLD1) $(LIBFOLD)
		@rm -rf libft fill_it_files

malloc check :
				grep -n -e "memalloc" -e "strdup" srcs/*/*
#				grep -n "malloc" srcs/*/*

showprt :
		bash ./show/.show.sh

hideprt :
		grep -n  printf ./*/*.c >> ./annex/show/.saves/.gres.txt


.PHONY : clean fclean re all d git check1 check2
