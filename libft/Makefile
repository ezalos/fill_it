# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/22 17:49:07 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################


SRCS =	$(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4) $(SRCS5) $(SRCS6) $(SRCS7)

SRCS1 = putchar_fd putendl_fd putnbr_fd putstr_fd
SRCS2 = atoi itoa
SRCS3 =	lstadd lstdel lstdelone lstiter lstmap lstnew
SRCS4 = memalloc memccpy memchr memcmp memcpy memdel memmove memset\
		strdel strdup strnew strsplit strjoin
SRCS5 = bzero isalnum isalpha isascii isdigit islower\
		isprint isupper strcat strchr strclr strcmp strcpy strequ\
		striter striteri strlcat strlen strmap strmapi strncat\
		strncmp strncpy strnequ strnstr strrchr strstr strsub strtrim tolower\
		toupper
SRCS6 = putchar putendl putnbr putstr putstr_rnull putstr_r0
SRCS7 = char_srch count_lst del factorial fibonacci find_lsth fsqrt intlen\
		lstcutone nprime power puttab_nb round_upper round nmatch match\
		pstrnstr patoi nb_char_to_int puttab

SRC_DIR1	= file
SRC_DIR2	= int
SRC_DIR3	= list
SRC_DIR4	= malloc
SRC_DIR5	= str
SRC_DIR6	= write
SRC_DIR7	= mine

SRC_PATH	= ./
MSRC_PATH	= srcs
SRC_PATH1	= $(MSRC_PATH)/$(SRC_DIR1)
SRC_PATH2	= $(MSRC_PATH)/$(SRC_DIR2)
SRC_PATH3	= $(MSRC_PATH)/$(SRC_DIR3)
SRC_PATH4	= $(MSRC_PATH)/$(SRC_DIR4)
SRC_PATH5	= $(MSRC_PATH)/$(SRC_DIR5)
SRC_PATH6	= $(MSRC_PATH)/$(SRC_DIR6)
SRC_PATH7	= $(MSRC_PATH)/$(SRC_DIR7)
A_SRC_P		=	$(MSRC_PATH), $(SRC_PATH1), $(SRC_PATH2), $(SRC_PATH3),\
 				$(SRC_PATH4), $(SRC_PATH5), $(SRC_PATH6), $(SRC_PATH7)

FT_H = libft.h

DIR_OBJ = ./objs/

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################
IFORDER		= $(shell ls | grep ft_putchar.c)
##################
##	   PUSH		##
##################
ifneq ("$(IFORDER)","")

SRC_DIR		= ./
NSRC_DIR  	= $(MSRC_PATH)

A_SRC 		= $(patsubst %,ft_%.c,$(SRCS))
NA_SRC 		= $(addsuffix .c,	$(addprefix $(SRC_PATH1)/ft_, $(SRCS1))\
								$(addprefix $(SRC_PATH2)/ft_, $(SRCS2))\
								$(addprefix $(SRC_PATH3)/ft_, $(SRCS3))\
								$(addprefix $(SRC_PATH4)/ft_, $(SRCS4))\
								$(addprefix $(SRC_PATH5)/ft_, $(SRCS5))\
								$(addprefix $(SRC_PATH6)/ft_, $(SRCS6))\
								$(addprefix $(SRC_PATH7)/ft_, $(SRCS7)))

HEAD_DIR	= $(SRC_PATH)
NHEAD_DIR	= ./includes
FT_HE		= $(FT_H)


IFOBJDIR	= $(shell ls | grep objs)
ifeq ("$(IFOBJDIR)","")
DIR_OBJ		= $(SRC_DIR)
endif
OBJS		= $(A_SRC:%.c=$(DIR_OBJ)%.o)
endif
##################
##	  ORDER		##
##################
IFPUSH		= $(shell ls | grep includes)
ifneq ("$(IFPUSH)","")

SRC_DIR  	= $(MSRC_PATH)
NSRC_DIR	=

A_SRC 		= $(addsuffix .c,	$(addprefix $(SRC_PATH1)/ft_, $(SRCS1))\
								$(addprefix $(SRC_PATH2)/ft_, $(SRCS2))\
								$(addprefix $(SRC_PATH3)/ft_, $(SRCS3))\
								$(addprefix $(SRC_PATH4)/ft_, $(SRCS4))\
								$(addprefix $(SRC_PATH5)/ft_, $(SRCS5))\
								$(addprefix $(SRC_PATH6)/ft_, $(SRCS6))\
								$(addprefix $(SRC_PATH7)/ft_, $(SRCS7)))
NA_SRC 		= $(patsubst %,$(SRC_PATH)ft_%.c,$(SRCS))

HEAD_DIR	= ./includes
NHEAD_DIR	= $(NSRC_PATH)
FT_HE		= $(HEAD_DIR)

OBJS = $(NA_SRC:%.c=$(DIR_OBJ)%.o)
endif

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

$(NAME):	$(OBJS) $(FT_HE)
			@$(call run_and_test, ar -rcs $(NAME) $(OBJS))

ifneq ("$(IFORDER)","")
$(DIR_OBJ)%.o:%.c
			@$(call run_and_test, $(CC) $(CFLAGS) -I$(HEAD_DIR) -o $@ -c $<)
else
$(OBJS):
		@$(CC) $(CFLAGS) -I$(HEAD_DIR) -c $(A_SRC)
		@mv -f $(NA_SRC:%.c=%.o) $(DIR_OBJ)
		@echo "\$(BLUE)Compiling \$(CYAN)objects\$(GREEN)\\t\\t\\t\\t  [OK]\$(END)"
endif

clean :
	@rm -f $(OBJS) libft.h.gch
	@echo "\$(YELLOW)lib_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"

re : fclean all

##############################################################################
##############################################################################
##																			##
##									-----									##
##									BONUS									##
##									-----									##
##																			##
##############################################################################
##############################################################################

order : fclean
ifneq ($(IFORDER), )
	@mkdir	$(MSRC_PATH) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
			$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6) $(SRC_PATH7) $(NHEAD_DIR)
	@mv -f $(HEAD_DIR)$(FT_H) $(NHEAD_DIR)
	@mv -f $(patsubst %, ft_%.c, $(SRCS1)) $(SRC_PATH1)
	@mv -f $(patsubst %, ft_%.c, $(SRCS2)) $(SRC_PATH2)
	@mv -f $(patsubst %, ft_%.c, $(SRCS3)) $(SRC_PATH3)
	@mv -f $(patsubst %, ft_%.c, $(SRCS4)) $(SRC_PATH4)
	@mv -f $(patsubst %, ft_%.c, $(SRCS5)) $(SRC_PATH5)
	@mv -f $(patsubst %, ft_%.c, $(SRCS6)) $(SRC_PATH6)
	@mv -f $(patsubst %, ft_%.c, $(SRCS7)) $(SRC_PATH7)
	@echo \$(GREEN) $(NAME) \$(END) Now in \$(MAGENTA)$@ mode \$(END)
endif

push : fclean
ifneq ($(IFPUSH), )
		@mv -f $(A_SRC) $(HEAD_DIR)/$(FT_H) $(SRC_PATH)
		@rm -rf $(MSRC_PATH) $(HEAD_DIR)
		@echo \$(GREEN) $(NAME) \$(END) Now in \$(MAGENTA)$@ mode \$(END)
endif

git :
		@git add -A
		@git status
		@git commit -am "Makefile automated push"
		@git push

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all a aclean afclean are f d order push git check
