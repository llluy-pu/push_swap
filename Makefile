# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 01:33:16 by llluy-pu          #+#    #+#              #
#    Updated: 2023/06/01 21:22:18 by llluy-pu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              VARIABLE REFERENCE                              #
# **************************************************************************** #

NAME= push_swap
NAME_BONUS= checker

# CC= gcc
CFLAGS= -Wall -Wextra -Werror -g -I $(INCLUDES)

LIBFT_DIR= libft
LIBFT_LIB= $(LIBFT_DIR)/libft.a
INCLUDES= include
OBJ_DIR= obj/
SRC_DIR= src/

# **************************************************************************** #
#                                .C & .H FILES                                 #
# **************************************************************************** #

SRC_FILE=	\
			chose_rr_or_r.c	\
			main.c	\
			more_three_number.c	\
			under_three_number.c

SRC_COMMON_FILE= \
			chained_list.c	\
			check_args.c	\
			check_sort.c	\
			fill_array.c	\
			fill_chained_list.c	\
			get_array.c	\
			push.c	\
			reverse_rotate.c	\
			rotate.c	\
			swap.c	\
			utils.c

SRC_BONUS_FILE= \
			checker_main.c

SRC=		$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE= 	$(SRC_FILE:.c=.o)
OBJ=		$(addprefix $(OBJ_DIR), $(OBJ_FILE))

SRC_COMMON=		$(addprefix $(SRC_DIR), $(SRC_COMMON_FILE))
OBJ_COMMON_FILE= $(SRC_COMMON_FILE:.c=.o)
OBJ_COMMON=		$(addprefix $(OBJ_DIR), $(OBJ_COMMON_FILE))

SRC_BONUS=		$(addprefix $(SRC_DIR), $(SRC_BONUS_FILE))
OBJ_BONUS_FILE= $(SRC_BONUS_FILE:.c=.o)
OBJ_BONUS=		$(addprefix $(OBJ_DIR), $(OBJ_BONUS_FILE))

#OBJ=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# **************************************************************************** #
#                                HEADER CONFIG                                 #
# **************************************************************************** #

CREATOR_NAME 	= llluy-pu
CREATOR_EMAIL 	= llluy-pu@student.42.fr

COLOR_RED		= \033[0;31m
COLOR_GREEN		= \033[0;32m
COLOR_YELLOW	= \033[0;33m
COLOR_BLUE		= \033[0;34m
COLOR_PURPLE	= \033[0;35m
COLOR_CYAN		= \033[0;36m
COLOR_WHITE		= \033[0;37m
COLOR_END		= \033[m

HEADER =			@echo "${COLOR_CYAN}\
					\n            :::      ::::::::    											\
					\n          :+:      :+:    :+:    											\
					\n        +:+ +:+         +:												\
					\n      +\#+  +:+       +\#+                								\
					\n    +\#+\#+\#+\#+\#+   +\#+               								\
					\n         \#+\#    \#+\#                   								\
					\n        \#\#\#   \#\#\#\#\#\#\#.fr        								\
					\n Project ${NAME} created by: ${CREATOR_NAME} ${CREATOR_EMAIL}	\
					${COLOR_END}"

HEADER_COMPIL =	@echo "${COLOR_YELLOW}\
					\n/* ************************************************************************** */\
					\n/*                                 COMPILING...                               */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_CLEAN =		@echo "${COLOR_RED}\
					\n/* ************************************************************************** */\
					\n/*                                 CLEANING...                                */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_FCLEAN =		@echo "${COLOR_RED}\
					\n/* ************************************************************************** */\
					\n/*                              FORCE CLEANING...                             */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_NORM =		@echo "${COLOR_PURPLE}\
					\n/* ************************************************************************** */\
					\n/*                            CHECKING THE NORM...                            */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_ENTERLIB =	@echo "${COLOR_GREEN}\
					\n/* ************************************************************************** */\
					\n/*                               ENTERING LIBFT                               */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

HEADER_EXITLIB =	@echo "${COLOR_GREEN}\
					\n/* ************************************************************************** */\
					\n/*                               EXITING LIBFT                                */\
					\n/* ************************************************************************** */\n\
					${COLOR_END}"

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ) $(OBJ_COMMON)
	$(HEADER)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(OBJ_COMMON) $(LIBFT_LIB)

malloc_test: $(LIBFT_LIB) $(OBJ) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ $(OBJ) $(OBJ_COMMON) $(LIBFT_LIB) -L. -lmallocator

$(LIBFT_LIB): makelibf ;

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT_LIB) $(OBJ_COMMON) $(OBJ_BONUS)
	$(HEADER)
	$(CC) $(CFLAGS) -o $@ $(OBJ_COMMON) $(OBJ_BONUS) $(LIBFT_LIB)

makelibf :
	$(HEADER_ENTERLIB)
	@make -C $(LIBFT_DIR)
	$(HEADER_EXITLIB)

$(OBJ): | $(OBJ_DIR)

$(OBJ_BONUS): | $(OBJ_DIR)

$(OBJ_COMMON): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_COMMON): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

header:
	$(HEADER)

cleanobj:
	rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_COMMON)

cleanobjdir: cleanobj
	rm -rf $(OBJ_DIR)

clean: cleanobjdir cleanlibft
	
cleanlibft:
	make -C $(LIBFT_DIR) clean

fcleanlibft:
	make -C $(LIBFT_DIR) fclean
	rm -f libft.a

fclean: clean fcleanlibft
	rm -f $(NAME) $(NAME_BONUS)

re: header fclean all

norm: header
	${HEADER_NORM}
	@echo "$(COLOR_GREEN)"
	-python3 -m norminette $(LIBFT_DIR) | awk "!/: OK!/"
	@echo "$(COLOR_CYAN)"
	-python3 -m norminette $(SRC_DIR)
	@echo "$(COLOR_PURPLE)"
	-python3 -m norminette $(INCLUDES)
	@echo "$(COLOR_END)"

.PHONY: all clean fclean re norm header makelibf cleanobj cleanobjdir fcleanlibft debug
