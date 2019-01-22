# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/22 01:53:44 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS =# -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
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

MSRC_PATH	= ./srcs
SRC_PATH0 	= $(MSRC_PATH)/main
SRC_PATH1 	= $(MSRC_PATH)/read
SRC_PATH2 	= $(MSRC_PATH)/setup
SRC_PATH3 	= $(MSRC_PATH)/solve
SRC_PATH4 	= $(MSRC_PATH)/print
SRC_PATH5 	= $(MSRC_PATH)/free
SRC_PATH6 	= $(MSRC_PATH)/logistics
A_SRC_P		=	srcs $(SRC_PATH0) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
 				$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6)

DIR_OBJ = ./objs/
##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################
NPUH		:= $(wildcard ./srcs/main/main.c)
##################
##	   PUSH		##
##################
ifeq ("$(NPUH)","")

SRC_PATH	= fill_it_files
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
NALL_PATH	= ./fill_it_files
HEAD_		= $(HEAD_PATH)/head.h

OBJS = $(A_SRC:$(SRC_PATH)%.c=$(DIR_OBJ)%.o)
##################
##	  ORDER		##
##################
else

LIB_PATH	= ./.annex/libft
NLIB_PATH	= ./libft
HEAD_PATH	= ./includes
HEAD_		= $(HEAD_PATH)
NHEAD_PATH	= ./fill_it_files
NALL_PATH	= ./fill_it_files

SRC_PATH  	= ./srcs
NSRC_PATH	= ./fill_it_files

A_SRC 		= $(addsuffix .c,	$(addprefix $(SRC_PATH0)/, $(SRCS0))\
								$(addprefix $(SRC_PATH1)/, $(SRCS1))\
								$(addprefix $(SRC_PATH2)/, $(SRCS2))\
								$(addprefix $(SRC_PATH3)/, $(SRCS3))\
								$(addprefix $(SRC_PATH4)/, $(SRCS4))\
								$(addprefix $(SRC_PATH5)/, $(SRCS5))\
								$(addprefix $(SRC_PATH6)/, $(SRCS6)))
NA_SRC 		= $(patsubst %,$(SRC_PATH)/%.c,$(SRCS))

OBJS = $(NA_SRC:$(SRC_PATH)%.c=$(DIR_OBJ)%.o)
endif

NOPT		:= $(wildcard ./.annex/time/time_exe.c.old)
##################
##	  W/_OPT	##
##################
ifeq ("$(NOPT)","")
TIME_EXE 	= 	./.annex/time/time_exe.c
TIME_EXE_H	= 	./.annex/time/time_exe.h
PRINT_DBG	=	./.annex/printing/print_debug.c
PRINT_R		=	./.annex/printing/print_r_in_color.c
PRINT		= 	$(PRINT_DBG) $(PRINT_R)

A_SRC 		+= $(TIME_EXE) $(PRINT)
NA_SRC 		+= time_exe.c time_exe.h print_debug.c print_r_in_color.c

##################
##	  NO_OPT	##
##################
else
TIME_EXE	= 	./.annex/time/time_exe.c.old
TIME_EXE_H	= 	./.annex/time/time_exe.h.old
PRINT_DBG	=	./.annex/printing/print_debug.c.old
PRINT_R		=	./.annex/printing/print_r_in_color.c.old
PRINT 		= 	$(PRINT_DBG) $(PRINT_R)

endif

CC_SECU		= 0
ifneq ("$(NPUH)","")
CC_SECU		= 1
endif
ifeq ("$(NOPT)","")
CC_SECU		= 1
endif

LIB			= $(LIB_PATH)/libft.a
HEAD		= $(HEAD_PATH)/head.h

PIECE = ./.annex/tests/bad/I1

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

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

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

$(NAME): $(OBJS) $(HEAD_)
		@$(MAKE) -C $(LIB_PATH)
		@$(call run_and_test, $(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME))

ifeq ($(CC_SECU),0)
$(DIR_OBJ)%.o:$(SRC_PATH)%.c
		@$(call run_and_test, $(CC) $(CFLAGS) -I$(HEAD_DIR) $(LIB) -o $@ -c $<)
else
$(OBJS):
		@$(CC) $(CFLAGS) -I$(HEAD_DIR) $(LIB) -c $(A_SRC)
		@mv -f $(NA_SRC:%.c=%.o) $(DIR_OBJ)
		@echo "\$(BLUE)Compiling \$(CYAN)objects\$(GREEN)\\t\\t\\t\\t  [OK]\$(END)"
endif

clean :
		@$(MAKE) clean -C $(LIB_PATH)
		@echo "\$(YELLOW)fill_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -f $(OBJS)

fclean : clean
		@$(MAKE) fclean -C $(LIB_PATH)
		@echo "\$(YELLOW)$(NAME) \$(END)\\t\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -rf $(NAME) fillit.dSYM

re :	fclean all

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

teste : all
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
		./$(NAME) ./.annex/tests/bad/otherTest/binary1.txt
		./$(NAME) ./.annex/tests/bad/otherTest/binary2.txt
		./$(NAME) ./.annex/tests/bad/otherTest/binary3.txt
		./$(NAME) ./.annex/tests/bad/otherTest/eof.txt
		./$(NAME) ./.annex/tests/bad/otherTest/twentyseven.txt
		./$(NAME) ./.annex/tests/bad/otherTest/twentysix.txt
		./$(NAME) ./.annex/tests/bad/otherTest/wrongdot1.txt
		./$(NAME) ./.annex/tests/bad/otherTest/wrongdot2.txt
		./$(NAME) ./.annex/tests/bad/otherTest/wrongdot3.txt

testv :	all
		$(VALGRIND) ./$(NAME) $(PIECE)


testp :	all
		./$(NAME) $(PIECE)

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

##############################################################################
##############################################################################
##																			##
##									-----									##
##									BONUS									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		AUTO-TEST		##
##						##
##########################

testa : all
		@bash ./.annex/training_set/make_tests.sh $(p) $(n)
		@bash ./.annex/tests/launch_tests.sh $(NAME) $(n) > ./.annex/tests/last_test
		@cat ./.annex/tests/last_test
		@rm -rf ./.annex/tests/random_generated/*

##########################
##						##
##		ARCHITECT		##
##						##
##########################

order :
ifneq ($(IFORDER), )
		@$(MAKE) offption
		@sed -i '' "s~head.h~../../includes/head.h~g" $(A_SRC)
		@sed -i '' "s~../../libft/libft.h~../libft/libft.h~g" $(TIME_EXE_H)
		@sed -i '' "s~../libft/libft.h~../.annex/libft/libft.h~g" $(HEAD)
		@sed -i '' "s~fill_it_files/head.h~includes/head.h~g" $(PRINT)
		@mkdir $(A_SRC_P) $(NHEAD_PATH)
		@mv -f $(HEAD_PATH)/head.h $(NHEAD_PATH)
		@mv -f $(LIB_PATH) $(NLIB_PATH)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS0)) $(SRC_PATH0)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS1)) $(SRC_PATH1)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS2)) $(SRC_PATH2)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS3)) $(SRC_PATH3)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS4)) $(SRC_PATH4)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS5)) $(SRC_PATH5)
		@mv -f $(patsubst %, $(NALL_PATH)/%.c, $(SRCS6)) $(SRC_PATH6)
		@rm -rf libft fill_it_files
endif

push :
ifneq ($(IFPUSH), )
		@$(MAKE) offption
		@sed -i '' "s~../../includes/head.h~head.h~g" $(A_SRC)
		@sed -i '' "s~../libft/libft.h~../../libft/libft.h~g" $(TIME_EXE_H)
		@sed -i '' "s~../.annex/libft/libft.h~../libft/libft.h~g" $(HEAD)
		@sed -i '' "s~includes/head.h~fill_it_files/head.h~g" $(PRINT)
		@mkdir $(NALL_PATH)
		@mv -f $(HEAD_PATH)/head.h $(NALL_PATH)
		@mv -f $(A_SRC) $(NALL_PATH)
		@mv -f $(LIB_PATH) ./
		@rm -rf $(SRC_PATH) $(HEAD_PATH)
endif

malloc_check :
		grep -n -e "memalloc" -e "strdup" srcs/*/*
#		grep -n "malloc" srcs/*/*


##########################
##						##
##	   ON/OFF PTION		##
##						##
##########################

# to put time_exe in *.c. Note that it will be configured to work when project is using the topush_ file structure.
onption :
ifneq ("$(NOPT)","")
	@bash .annex/time/input_tim.sh
	@mv -f .annex/printing/print_r_in_color.c.old .annex/printing/print_r_in_color.c
	@mv -f .annex/time/time_exe.h.old .annex/time/time_exe.h
	@mv -f .annex/time/time_exe.c.old .annex/time/time_exe.c
	@mv -f .annex/printing/print_debug.c.old .annex/printing/print_debug.c
	@bash .annex/show/show_debug.sh
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
	@sed -i '' 's/define ONPTION/define OFFPTION/' fill_it_files/head.h
endif

##########################
##						##
##		  SHOW			##
##						##
##########################

show_ :
			bash ./.annex/show/.show.sh
grep_ :
		grep -n -e printf -e time_exe $(A_SRC) >> ./.annex/show/.gres.txt

hide_ :
		sed -i '' '/printf/d' $(A_SRC)
		sed -i '' '/time/d' $(A_SRC)

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all d git check show_ grep_ hide_ malloc_check onption offption push order testa testv teste testp
