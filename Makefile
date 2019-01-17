# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/17 22:10:40 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

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

LIBFOLD =	./.annex/libft/
LIB =		libft.a

FOLD0 = ./fill_it_files/
FOLD1 = ./libft/

A_SRC_P	=	srcs $(SRC_PATH0) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
 			$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6)

SRC_PATH0 = srcs/main/
SRC_PATH1 = srcs/read/
SRC_PATH2 = srcs/setup/
SRC_PATH3 = srcs/solve/
SRC_PATH4 = srcs/print/
SRC_PATH5 = srcs/free/
SRC_PATH6 = srcs/logistics/

SRCS =	$(SRCS0) $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4) $(SRCS5) $(SRCS6)

SRCS0 = main
SRCS1 = read_check recognize
SRCS2 = setup_struct setup_pieces setup_binary
SRCS3 =	solve
SRCS4 = printing_the_result
SRCS5 = free_all free_pieces free_sols
SRCS6 = binary_str find_struct j_and_maths

TIME_EXE = 	./.annex/time/time_exe.c
PRINT = 	./.annex/printing/print_debug.c \
			./.annex/printing/print_r_in_color.c

SRCPUSH = $(patsubst %, $(FOLD0)%.c,$(SRCS))
OBJS = $(patsubst %, ft_%.o,$(SRCS))

A_SRC =	$(addsuffix .c, $(addprefix $(SRC_PATH0), $(SRCS0))\
						$(addprefix $(SRC_PATH1), $(SRCS1))\
						$(addprefix $(SRC_PATH2), $(SRCS2))\
						$(addprefix $(SRC_PATH3), $(SRCS3))\
						$(addprefix $(SRC_PATH4), $(SRCS4))\
						$(addprefix $(SRC_PATH5), $(SRCS5))\
						$(addprefix $(SRC_PATH6), $(SRCS6)))

#remove TEMPORAIRE
TEMPORAIRE = intlen memalloc memcpy memset putchar putnbr putstr strcmp strdup strlen strstr strnstr

PIECE = ./.annex/tests/good/fit/6_0

VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite

GREEN   = '\x1b[32m'
RED     = '\x1b[31m'
END     = '\x1b[0m'

all :	$(NAME)

$(NAME):
			@$(MAKE) -C $(FOLD1)
			@echo "$(GREEN) $(LIB) has been created $(END)"
			@$(CC) $(SRCPUSH) $(FOLD1)$(LIB) -o $(NAME)
			@echo "$(GREEN)$(NAME) has been created $(END)"

d :
			@$(CC) -c $(DFLAGS) $(patsubst %,%.c,$(A_SRC))
			@$(CC) $(A_SRC) -o $(NAME)

clean :
	@$(MAKE) clean -C $(FOLD1)
	@echo "$(GREEN) $(LIB) has been cleaned $(END)"
	@echo "$(RED) Objects have been removed $(END)"
	@rm -f $(OBJS)

fclean :
	@$(MAKE) fclean -C $(FOLD1)
	@echo "$(GREEN) $(LIB) has been fcleaned $(END)"
	@$(MAKE) clean
	@echo "$(RED) Project has been removed $(END)"
	@rm -f $(NAME)

re :
	@$(MAKE) re -C $(FOLD1)
	@$(MAKE) fclean
	@$(MAKE)
	@echo "$(GREEN) $(LIB) has been recreated $(END)"

a :
			@$(MAKE) -C $(LIBFOLD)
			@echo "$(GREEN) $(LIB) has been created $(END)"
			@$(CC) $(A_SRC) $(TIME_EXE) $(LIBFOLD)$(LIB) -o $(NAME)
			@echo "$(GREEN)$(NAME) has been created $(END)"

ad :
			@$(CC) -c $(DFLAGS) $(patsubst %,%.c,$(A_SRC))
			@$(CC) $(A_SRC) -o $(NAME)

are : fclean a

git :
		@git add *
		@git status
		@git commit -am "Makefile automated push"
		@git push

teste : 	re
			./$(NAME) ./.annex/tests/bad/err0
			./$(NAME) ./.annex/tests/bad/err1
			./$(NAME) ./.annex/tests/bad/err2
			./$(NAME) ./.annex/tests/bad/err3
			./$(NAME) ./.annex/tests/bad/err4
			./$(NAME) ./.annex/tests/bad/err5
			./$(NAME) ./.annex/tests/bad/err6
			./$(NAME)
			./$(NAME) ./.annex/test lol
			./$(NAME) ./.annex

testv :	re
		$(VALGRIND) ./$(NAME) $(PIECE)

test3 :	re
		./$(NAME) ./.annex/tests/good/unfit/3_0

test64 :re
		./$(NAME) ./.annex/tests/bad/64_O0

test4 :	re
		./$(NAME) ./.annex/tests/bad/4_0

test6 :	re
		./$(NAME) ./.annex/tests/good/fit/6_0

test7 :	re
		./$(NAME) ./.annex/tests/good/fit/7_0

test12 :re
		./$(NAME) ./.annex/tests/good/fit/12_0

test9 :	re
		./$(NAME) ./.annex/tests/good/unfit/9_0

test8 :	re
		./$(NAME) ./.annex/tests/good/fit/8_0

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

test : 	all
		@bash ./.annex/training_set/make_tests.sh $(p) $(n)
		@bash ./.annex/tests/launch_tests.sh $(NAME) $(n) > ./.annex/tests/last_test
		@cat ./.annex/tests/last_test
		@rm -rf ./.annex/tests/random_generated/*

IFORDER = $(shell ls | grep fill_it_files)
IFPUSH = $(shell ls | grep srcs)

order :
ifeq ($(IFORDER), )
	@echo “Non present”
else
	@sed -i '' "s~head.h~../../includes/head.h~g" $(patsubst %,$(FOLD0)%.c,$(SRCS))
	@sed -i '' "s~../fill_it_files/head.h~../../includes/head.h~g" $(patsubst %, $(FOLD1)ft_%.c,$(TEMPORAIRE))
	@sed -i '' "s~../../libft/libft.h~../libft/libft.h~g" ./.annex/time/time_exe.h
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
endif

echo :
		@echo $(prout)

push :
ifeq ($(IFPUSH), )
	@echo “Non present”
else
	@sed -i '' "s~../../includes/head.h~head.h~g" $(A_SRC)
	@sed -i '' "s~../../includes/head.h~../fill_it_files/head.h~g" $(patsubst %, $(LIBFOLD)ft_%.c,$(TEMPORAIRE))
	@sed -i '' "s~../libft/libft.h~../../libft/libft.h~g" ./.annex/time/time_exe.h
	@mkdir $(FOLD0) $(FOLD1)
	@mv -f $(HEAD)/$(FT_H) $(FOLD0)
	@mv -f $(A_SRC) $(FOLD0)
	@mv -f $(LIBFOLD) ./
	@rm -rf $(A_SRC_P) $(HEAD)
endif

malloc_check :
				grep -n -e "memalloc" -e "strdup" srcs/*/*
#				grep -n "malloc" srcs/*/*

show_ :
		bash ./.annex/show/.show.sh

# to put time_exe in *.c. Note that it will be configured to work when project is using the topush_ file structure.
onption :
	bash .annex/time/input_tim.sh
	mv -f .annex/printing/print_r_in_color.c.old .annex/printing/print_r_in_color.c
	bash .annex/show/show_debug.sh
		

# to remove time_exe from *.c.
# Attention a nos wildcards. Il y en a une autre ligne 212.
offption :
	@sed -i '' '/time_exe/d' fill_it_files/*.c
	@sed -i '' '/print_debug/d' fill_it_files/setup_struct.c
	@sed -i '' 's/print_pieces_color/print_pieces/' fill_it_files/printing_the_result.c
	@sed -i '' '/print_soltion_link/d' fill_it_files/solve.c
	@sed -i '' '/print_time/d' .annex/printing/print_r_in_color.c 
	@mv -f .annex/printing/print_r_in_color.c .annex/printing/print_r_in_color.c.old

grep_ :
		grep -n -e printf -e time_exe $(A_SRC) >> ./.annex/show/.gres.txt

hide_ :
		sed -i '' '/printf/d' $(A_SRC)
		sed -i '' '/time/d' $(A_SRC)

.PHONY : clean fclean re all d git check
