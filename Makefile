NAME		= libftprintf.a

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= src
OBJ			= obj
PRS			= parse
PRT			= print

SRCS		= $(addprefix $(SRC)/, ft_printf.c parser.c printer.c utils.c)
PRS_SRC		= $(addprefix $(SRC)/$(PRS)/, flags.c type_char.c type_string.c \
			type_pointer.c type_decimal.c type_unsigned.c type_hex.c \
			type_percent.c utils-prs.c)
PRT_SRC		= $(addprefix $(SRC)/$(PRT)/, types.c out_char.c out_string.c out_pointer.c \
			out_decimal.c out_unsigned.c out_hex.c out_percent.c utils-prt.c)

SRC_OBJ		= $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
PRS_OBJ		= $(subst $(SRC)/$(PRS), $(OBJ), $(PRS_SRC:.c=.o))
PRT_OBJ		= $(subst $(SRC)/$(PRT), $(OBJ), $(PRT_SRC:.c=.o))

CFLAGS		= -g -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAME)

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
