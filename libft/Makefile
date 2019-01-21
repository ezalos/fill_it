# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/01/21 13:54:47 by ldevelle         ###   ########.fr        #
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

HEAD = ./includes/

FT_H = libft.h

A_SRC_P	=	$(SRC_PATH1), $(SRC_PATH2), $(SRC_PATH3),\
 			$(SRC_PATH4), $(SRC_PATH5), $(SRC_PATH6), $(SRC_PATH7)

SRC_PATH = srcs/
SRC_PATH1 = srcs/file/
SRC_PATH2 = srcs/int/
SRC_PATH3 = srcs/list/
SRC_PATH4 = srcs/malloc/
SRC_PATH5 = srcs/str/
SRC_PATH6 = srcs/write/
SRC_PATH7 = srcs/mine/

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

A_SRC =	$(addsuffix .c, $(addprefix $(SRC_PATH1)ft_, $(SRCS1))\
						$(addprefix $(SRC_PATH2)ft_, $(SRCS2))\
						$(addprefix $(SRC_PATH3)ft_, $(SRCS3))\
						$(addprefix $(SRC_PATH4)ft_, $(SRCS4))\
						$(addprefix $(SRC_PATH5)ft_, $(SRCS5))\
						$(addprefix $(SRC_PATH6)ft_, $(SRCS6))\
						$(addprefix $(SRC_PATH7)ft_, $(SRCS7)))

OBJS = $(patsubst %,ft_%.o,$(SRCS))

OBJ_PATH = $(SRCS:srcs/=objs/)

DIR_OBJ = ./objs

PATH_OBJ = $(addprefix $(DIR_OBJ)/ft_, $(OBJS))

IFORDER = $(shell ls | grep ft_putchar.c)
IFPUSH = $(shell ls | grep includes)

SRC_PUSH = $(patsubst %,ft_%.c,$(SRCS))

OBJS_ORDER = $(OBJS)

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

#@$(call run_and_test, ar -rc $(NAME) $(D_OBJS_P) $(D_OBJS_L))

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

all :	$(NAME)

$(NAME):	$(OBJS)
			@$(call run_and_test, ar -rcs $(NAME) $(OBJS))

$(OBJS):	$(IFPUSH) $(SRC_PUSH) $(FT_H)
			@$(call run_and_test, $(CC) -c $(CFLAGS) $(patsubst %,ft_%.c,$(SRCS)) -I$(HEAD))

$(IFPUSH) :	push

d :
			@$(CC) -c $(DFLAGS) $(patsubst %,ft_%.c,$(SRCS)) -I$(HEAD)
			@ar -rcs $(NAME) $(OBJS)

clean : push
	@$(call run_and_test, rm -f $(OBJS) libft.h.gch)

fclean : clean
	@$(call run_and_test, rm -f $(NAME))

f : fclean

re : fclean all

a : order
		@echo "Creating objects"
		@$(CC) -c $(CFLAGS) $(A_SRC)
		@echo "Creating $(NAME)"
		@ar -rcs $(NAME) $(OBJS)
		@echo "Moving objects"
		@mkdir $(DIR_OBJ)
		@mv -f $(OBJS) $(DIR_OBJ)

aclean : order
		@echo "Cleaning objects"
		@rm -f $(PATH_OBJ) $(OBJS_) libft.h.gch
		@rm -rf $(patsubst ./%,%,$(DIR_OBJ))

afclean : 	aclean
			@echo "Cleaning project"
			@rm -f $(NAME)

are : 	afclean
		@$(MAKE) a

order :
ifneq ($(IFORDER), )
	@$(MAKE) fclean
	@sed -i '' "s~libft.h~../../includes/libft.h~g" $(patsubst %,ft_%.c,$(SRCS))
	@mkdir	$(SRC_PATH) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
			$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6) $(SRC_PATH7) $(HEAD)
	@mv -f $(FT_H) $(HEAD)
	@mv -f $(patsubst %, ft_%.c, $(SRCS1)) $(SRC_PATH1)
	@mv -f $(patsubst %, ft_%.c, $(SRCS2)) $(SRC_PATH2)
	@mv -f $(patsubst %, ft_%.c, $(SRCS3)) $(SRC_PATH3)
	@mv -f $(patsubst %, ft_%.c, $(SRCS4)) $(SRC_PATH4)
	@mv -f $(patsubst %, ft_%.c, $(SRCS5)) $(SRC_PATH5)
	@mv -f $(patsubst %, ft_%.c, $(SRCS6)) $(SRC_PATH6)
	@mv -f $(patsubst %, ft_%.c, $(SRCS7)) $(SRC_PATH7)
	@echo “Now in order mode”
endif

push :
ifneq ($(IFPUSH), )
		@$(MAKE) afclean
		@sed -i '' "s~../../includes/libft.h~libft.h~g" $(A_SRC)
		@mv -f $(A_SRC) $(HEAD)$(FT_H) ./
		@rm -rf $(SRC_PATH) ./objs/ $(HEAD)
		@echo “Now in push mode”
endif

git :
		@git add -A
		@git status
		@git commit -am "Makefile automated push"
		@git push

check1 :
		bash /Users/ldevelle/42/42FileChecker/42FileChecker.sh

check2 :
		yes n | bash /Users/ldevelle/42/Libftest/grademe.sh

.PHONY : clean fclean re all a aclean afclean are f d order push git check1 check2
