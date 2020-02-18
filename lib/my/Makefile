##
## EPITECH PROJECT, 2018
## make file
## File description:
## make file
##

RM		=	@rm -f

AR		=	@ar rc

MAKEFLAGS	+=		--no-print-directory

SRC		=	my_printf.c		\
			display_print.c	\
			flag_number.c		\
			string_flags.c		\
			get_number.c		\
			assign_number.c	\
			found_assign.c		\
			reco.c				\
			number.c			\
			sepa.c				\
			secu_string.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

ECHO		=		/bin/echo -e
GREEN		=		"\033[1;32m"
YELLOW		=		"\033[0;01;033m"
TEAL		=		"\033[1;01;35m"
BLUE		=		"\033[1;33m"
RED			=		"\033[1;01;31m"
DEFAULT		=		"\033[00m"

title	:
		@$(ECHO) $(RED)"\n → Lib : my_printf\n" $(DEFAULT)

endt	:
		@$(ECHO) $(BLUE)"\n → [LIB MY_PRINTF CREATE]\n" $(DEFAULT)

all:		title $(NAME) endt
			@echo ""

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ) &&	\
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
	$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) -c $< -o $@ &&                         \
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||        \
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
