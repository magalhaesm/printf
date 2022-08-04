NAME		= libftprintf.a

LIBFT_DIR	= libft/libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= src
OBJ			= obj
PRS			= parse
PRT			= print

SRCS		= $(addprefix $(SRC)/, ft_printf.c parser.c printer.c)
PRS_SRC		= $(addprefix $(SRC)/$(PRS)/, flags.c parse_utils.c)
PRT_SRC		= $(addprefix $(SRC)/$(PRT)/, types.c out_char.c              \
				out_string.c out_pointer.c out_signed.c out_unsigned.c    \
				out_percent.c print_utils.c)

SRC_OBJ		= $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
PRS_OBJ		= $(subst $(SRC)/$(PRS), $(OBJ), $(PRS_SRC:.c=.o))
PRT_OBJ		= $(subst $(SRC)/$(PRT), $(OBJ), $(PRT_SRC:.c=.o))

CFLAGS		= -g -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(LIBFT) $(SRC_OBJ) $(PRS_OBJ) $(PRT_OBJ)

$(OBJ)/%.o:	src/%.c
		@mkdir -p $(OBJ)
		$(CC) $(CFLAGS) -c $< -o $@
		ar -rcs $(NAME) $@

$(OBJ)/%.o:	src/parse/%.c
		$(CC) $(CFLAGS) -c $< -o $@
		ar -rcs $(NAME) $@

$(OBJ)/%.o:	src/print/%.c
		$(CC) $(CFLAGS) -c $< -o $@
		ar -rcs $(NAME) $@

$(LIBFT):
		git submodule init
		git submodule update
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT) $(NAME)

clean:
		$(RM) -r $(SRC_OBJ) $(PRS_OBJ) $(PRT_OBJ)
		$(RM) -r $(OBJ)

fclean:		clean
		@make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
