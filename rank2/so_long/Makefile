NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LIBXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
MLX_PATH = minilibx-linux/

SRC_PRE = src/
PRINTF_PRE = ft_printf/

PRINTF_FILES = ft_printf.c ft_printf2.c ft_putunbr.c \
				ft_strchr.c ft_strlen.c ft_write.c \
				ft_putnbr_base.c ft_putpoint.c test.c

FILES = main.c get_next_line_utils.c get_next_line.c move.c \
			mapping.c texturing.c utils.c map_verif.c map_verif_2.c\
			ft_itoa.c enemies.c

SRCS = $(addprefix $(SRC_PRE), $(FILES))
PRINTF_SRCS = $(addprefix $(PRINTF_PRE), $(PRINTF_FILES))

OBJS = $(SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

all: $(NAME)

${NAME}: 	${OBJS}
	make -sC $(MLX_PATH)
	${CC} -o ${NAME} -I. ${OBJS} ${LIBXFLAGS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -sC $(MLX_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all