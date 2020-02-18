##
## EPITECH PROJECT, 2019
## bootsrap_tetris
## File description:
## __DESCRIPTION__
##

CC			=		@gcc

MAKEFLAGS	+=		--no-print-directory

RM			=		rm		-f

ECHO		=		/bin/echo -e
DEFAULT		=		"\033[00m"
GREEN		=		"\033[1;32m"
YELLOW		=		"\033[0;01;033m"
TEAL		=		"\033[1;01;35m"
RED			=		"\033[1;01;31m"

CFLAGS		+=		-I./include

CFLAGS		+=		-lncurses

LIB	=	-L./lib/my -lmy

NAME		=		tetris

DB			=		src/debug_mode/debug.c		\
					src/debug_mode/display.c	\
					src/debug_mode/display_number.c

SRC			=		src/main.c					\
					src/init_game.c				\
					src/get_next_line.c			\
					src/init_game_board.c		\
					src/init_object.c			\
					src/to_tab.c				\
					src/mini_lib/my_str_to_word_array.c	\
					src/mini_lib/pars_tetriminos.c	\
					src/mini_lib/get_env.c

OPT			=		src/option/check_option.c

SECU		=		src/security/security_command.c	\
					src/security/security_color.c	\
					src/mini_lib/set_term.c

PARS		=		src/parsing_tetriminos/parsing.c	\
					src/parsing_tetriminos/security_tetriminos.c	\
					src/parsing_tetriminos/security_size_tetriminos.c

GM			=		src/graphic_game/init_graphic.c	\
					src/graphic_game/init_key_graph.c	\
					src/graphic_game/init_game_graph.c	\
					src/graphic_game/number_to_string.c	\
					src/graphic_game/data_manage.c		\
					src/graphic_game/display_graph.c	\
					src/graphic_game/choose_tetriminos.c	\
					src/graphic_game/init_tetriminos.c

SRCS		=		$(SRC)	\
					$(OPT)	\
					$(SECU)	\
					$(DB)	\
					$(GM)	\
					$(PARS)

OBJS		=		$(SRCS:.c=.o)

all		:title $(NAME) endt
		@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : Tetris\n" $(DEFAULT)

endt		:
			@$(ECHO) $(RED)"\n → [TETRIS CREATE]\n" $(DEFAULT)

$(NAME):	libcreate $(OBJS)
					@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB) && 	\
					$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
					$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) $(CFLAGS) $(LIB) -c $< -o $@ &&                         \
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||        \
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

libcreate:
			@make -C lib/my all

clean:
			@$(RM) $(OBJS)
			@make -C lib/my clean

fclean:		clean
			@$(RM) $(NAME)
			@make -C lib/my fclean

re:			fclean all

.PHONY  : all clean fclean re
