NAME	= libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC	= src
OBJ	= obj
PRS	= parse
PRT	= print

SRCS	= $(addprefix $(SRC)/, ft_printf.c parser.c printer.c utils.c)
PRS_SRC	= $(addprefix $(SRC)/$(PRS)/, flags.c spec_c.c spec_s.c \
			spec_p.c spec_d.c spec_i.c spec_u.c spec_lower_x.c \
			spec_upper_x.c spec_percent.c prs-utils.c)
PRT_SRC	= $(addprefix $(SRC)/$(PRT)/, put_c.c put_s.c prt-utils.c)

SRC_OBJ	= $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
PRS_OBJ	= $(subst $(SRC)/$(PRS), $(OBJ), $(PRS_SRC:.c=.o))
PRT_OBJ	= $(subst $(SRC)/$(PRT), $(OBJ), $(PRT_SRC:.c=.o))

CFLAGS	= -g -Wall -Wextra -Werror
RM			= rm -f

all:	$(NAME)

$(NAME):	$(LIBFT) $(SRC_OBJ) $(PRS_OBJ) $(PRT_OBJ)

$(OBJ):
		@mkdir -p $@

$(OBJ)/%.o: src/%.c
		@mkdir -p obj
		$(CC) $(CFLAGS) -c $< -o $@
		ar -rcs $(NAME) $@

$(OBJ)/%.o: src/parse/%.c
		$(CC) $(CFLAGS) -c $< -o $@
		ar -rcs $(NAME) $@

$(OBJ)/%.o: src/print/%.c
		$(CC) $(CFLAGS) -c $< -o $@
		ar -rcs $(NAME) $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
		$(RM) -r $(SRC_OBJ) $(MOD_OBJ) $(CNV_OBJ)
		$(RM) -r $(OBJ)

fclean:		clean
		@make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
