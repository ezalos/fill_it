# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/18 03:51:33 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

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

#CFLAGS = $(DFLAGS)

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################

NPLL		:= $(wildcard ./srcs/main/main.c)
NOPT		:= $(wildcard ./.annex/time/time_exe.c.old)
IFORDER		= $(shell ls | grep fill_it_files)
IFPUSH		= $(shell ls | grep srcs)

SRCS		= $(SRCS0) $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4) $(SRCS5) $(SRCS6)
SRCS0		= main
SRCS1		= read_check recognize
SRCS2		= setup_struct setup_pieces setup_binary
SRCS3		= solve
SRCS4		= printing_the_result
SRCS5		= free_all free_pieces free_sols
SRCS6		= binary_str find_struct j_and_maths

SRC_PATH0 	= $(SRC_PATH)/main
SRC_PATH1 	= $(SRC_PATH)/read
SRC_PATH2 	= $(SRC_PATH)/setup
SRC_PATH3 	= $(SRC_PATH)/solve
SRC_PATH4 	= $(SRC_PATH)/print
SRC_PATH5 	= $(SRC_PATH)/free
SRC_PATH6 	= $(SRC_PATH)/logistics
A_SRC_P		=	srcs $(SRC_PATH0) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
 				$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6)

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

##################
##	   PULL		##
##################
ifeq ("$(NPLL)","")

SRC_PATH	= ./fill_it_files
NSRC_PATH  	= srcs

A_SRC 		= $(patsubst %,$(SRC_PATH)/%.c,$(SRCS))
NA_SRC 		= $(addsuffix .c,	$(addprefix $(SRC_PATH0)/, $(SRCS0))\
								$(addprefix $(SRC_PATH1)/, $(SRCS1))\
								$(addprefix $(SRC_PATH2)/, $(SRCS2))\
								$(addprefix $(SRC_PATH3)/, $(SRCS3))\
								$(addprefix $(SRC_PATH4)/, $(SRCS4))\
								$(addprefix $(SRC_PATH5)/, $(SRCS5))\
								$(addprefix $(SRC_PATH6)/, $(SRCS6)))

LIB_PATH	= ./libft
NLIB_PATH	= ./.annex/libft
HEAD_PATH	= $(SRC_PATH)
NHEAD_PATH	= ./includes

##################
##	  ORDER		##
##################
else

LIB_PATH	= ./.annex/libft
NLIB_PATH	= ./libft
HEAD_PATH	= ./includes
NHEAD_PATH	= ./fill_it_files
NALL_PATH	= ./fill_it_files

SRC_PATH  	= srcs
NSRC_PATH	= ./fill_it_files

A_SRC 		= $(addsuffix .c,	$(addprefix $(SRC_PATH0)/, $(SRCS0))\
								$(addprefix $(SRC_PATH1)/, $(SRCS1))\
								$(addprefix $(SRC_PATH2)/, $(SRCS2))\
								$(addprefix $(SRC_PATH3)/, $(SRCS3))\
								$(addprefix $(SRC_PATH4)/, $(SRCS4))\
								$(addprefix $(SRC_PATH5)/, $(SRCS5))\
								$(addprefix $(SRC_PATH6)/, $(SRCS6)))
NA_SRC 		= $(patsubst %,$(SRC_PATH)/%.c,$(SRCS))
endif


TIME_EXE = 	./.annex/time/time_exe.c
PRINT = 	./.annex/printing/print_debug.c \
			./.annex/printing/print_r_in_color.c

##################
##	  W/_OPT	##
##################
ifeq ("$(NOPT)","")

A_SRC += $(TIME_EXE) $(PRINT)
endif

SRCPUSH = $(patsubst %, $(FOLD0)%.c,$(SRCS))
OBJS = $(patsubst %, ft_%.o,$(SRCS))

LIB			= $(LIB_PATH)/libft.a
HEAD		= $(HEAD_PATH)/head.h

PIECE = ./.annex/tests/good/fit/7_0

##########################
##						##
##		  DEBUG			##
##						##
##########################

VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite

##########################
##						##
##		 COLORS			##
##						##
##########################

GREEN   = '\x1b[32m'
RED     = '\x1b[31m'
END     = '\x1b[0m'

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :	$(NAME)

$(NAME):
		@$(MAKE) -C $(LIB_PATH)
		@echo "$(GREEN) $(LIB) has been created $(END)"
		@$(CC) $(CFLAGS) $(A_SRC) $(LIB) -o $(NAME)
		@echo "$(GREEN) $(NAME) has been created $(END)"

clean :
		@$(MAKE) clean -C $(LIB_PATH)
		@echo "$(GREEN) $(LIB) has been cleaned $(END)"
		@echo "$(RED) Objects have been removed $(END)"
		@rm -f $(OBJS)

fclean :
		@$(MAKE) fclean -C $(LIB_PATH)
		@echo "$(GREEN) $(LIB) has been fcleaned $(END)"
		@$(MAKE) clean
		@echo "$(RED) Project has been removed $(END)"
		@rm -f $(NAME)

re :
		@$(MAKE) re -C $(LIB_PATH)
		@$(MAKE) fclean
		@$(MAKE)
		@echo "$(GREEN) $(LIB) has been recreated $(END)"

git :
		@git add -A
		@git status
		@git commit -am "Makefile automated push"
		@git push

##########################
##						##
##		  TESTS			##
##						##
##########################

teste : re
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


testp :	re
		./$(NAME) $(PIECE)

testa : 	all
		@bash ./.annex/training_set/make_tests.sh $(p) $(n)
		@bash ./.annex/tests/launch_tests.sh $(NAME) $(n) > ./.annex/tests/last_test
		@cat ./.annex/tests/last_test
		@rm -rf ./.annex/tests/random_generated/*

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

##########################
##						##
##		 OPTIONS		##
##						##
##########################

order :
ifneq ($(IFORDER), )
		@sed -i '' "s~head.h~../../includes/head.h~g" $(A_SRC)
		@sed -i '' "s~../../libft/libft.h~../libft/libft.h~g" ./.annex/time/time_exe.h
		@mkdir $(A_SRC_P) $(NALL_PATH)
		@mv -f $(SRC_PATH) $(NHEAD_PATH)
		@mv -f $(LIB_PATH) $(NLIB_PATH)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS0)) $(SRC_PATH0)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS1)) $(SRC_PATH1)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS2)) $(SRC_PATH2)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS3)) $(SRC_PATH3)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS4)) $(SRC_PATH4)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS5)) $(SRC_PATH5)
		@mv -f $(patsubst %, $(NALL_PATH)%.c, $(SRCS6)) $(SRC_PATH6)
		#@rm -rf libft fill_it_files
endif

push :
ifneq ($(IFPUSH), )
		@sed -i '' "s~../../includes/head.h~head.h~g" $(A_SRC)
		@sed -i '' "s~../libft/libft.h~../../libft/libft.h~g" ./.annex/time/time_exe.h
		@mkdir $(NALL_PATH)
		@mv -f $(HEAD_PATH)/$(HEAD) $(NALL_PATH)
		@mv -f $(A_SRC) $(NALL_PATH)
		@mv -f $(NLIB_PATH) ./
		#@rm -rf $(A_SRC_P) $(HEAD)
endif

malloc_check :
		grep -n -e "memalloc" -e "strdup" srcs/*/*
#		grep -n "malloc" srcs/*/*


# to put time_exe in *.c. Note that it will be configured to work when project is using the topush_ file structure.
onption :
ifneq ("$(NOPT)","")
	bash .annex/time/input_tim.sh
	mv -f .annex/printing/print_r_in_color.c.old .annex/printing/print_r_in_color.c
	mv -f .annex/time/time_exe.h.old .annex/time/time_exe.h
	mv -f .annex/time/time_exe.c.old .annex/time/time_exe.c
	mv -f .annex/printing/print_debug.c.old .annex/printing/print_debug.c
	bash .annex/show/show_debug.sh
endif

# to remove time_exe from *.c.
# Attention a nos wildcards. Il y en a une autre ligne 212.
offption :
ifeq ("$(NOPT)","")
	@sed -i '' '/time_exe/d' fill_it_files/*.c
	@sed -i '' '/print_debug/d' fill_it_files/setup_struct.c
	@sed -i '' 's/print_pieces_color/print_pieces/' fill_it_files/printing_the_result.c
	@sed -i '' '/print_soltion_link/d' fill_it_files/solve.c
	@sed -i '' '/print_time/d' .annex/printing/print_r_in_color.c
	@mv -f .annex/printing/print_r_in_color.c .annex/printing/print_r_in_color.c.old
	@mv -f .annex/time/time_exe.h .annex/time/time_exe.h.old
	@mv -f .annex/time/time_exe.c .annex/time/time_exe.c.old
	@mv -f .annex/printing/print_debug.c .annex/printing/print_debug.c.old
	@sed -i '' 's/# define ONPTION/# define OFFPTION/' fill_it_files/head.h
endif

show_ :
			bash ./.annex/show/.show.sh
grep_ :
		grep -n -e printf -e time_exe $(A_SRC) >> ./.annex/show/.gres.txt

hide_ :
		sed -i '' '/printf/d' $(A_SRC)
		sed -i '' '/time/d' $(A_SRC)

.PHONY : clean fclean re all d git check
