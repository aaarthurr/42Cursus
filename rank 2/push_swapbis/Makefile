#A MAKE

AR_MAKER = \n\
$(GREEN)┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n\
$(GREEN)┃┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓┃\n\
$(GREEN)┃┃$(CLR_END)                            @@@@@@@@@@@@@@@@@@@@@@                            $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                     $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)                @@@@@@@@..@@@@@@..............@@@@@@..@@@@@@@@                $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)            @@@@@@@.....@@@@@.........$(RED)/\\\\$(CLR_END)..........@@@@.....@@@@@@@            $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)        @@@@@@@........@@@&.......@@@$(RED)/  \\\\$(CLR_END)@@@........@@@@....... @@@@@@        $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)     @@@@@@...........@@@......@@@@@$(RED)/ /\ \\\\$(CLR_END)@@@@@......@@@@..........@@@@@@     $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)  @@@@@@.............@@@......@@@@@$(RED)/ /__\ \\\\$(CLR_END)@@@@@......@@@..............@@@@@  $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)@@@@@................@@@.....@@@@@$(RED)/ _MAKE_ \\\\$(CLR_END)@@@@@.....@@@@............... @@@@$(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)@@@@@@...............@@@.....@@@@$(RED)/ /      \ \\\\$(CLR_END)@@@@.....@@@@...............@@@@@$(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)   @@@@@@............@@@@.....@@$(RED)/ /        \ \\\\$(CLR_END)@@......@@@,............@@@@@   $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)      @@@@@@..........@@@&.....$(RED)/_/$(CLR_END)@@@@@@@@@@$(RED)\_\\\\$(CLR_END)......@@@&.........@@@@@@      $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)         @@@@@@@.......@@@@........@@@@@@@@........@@@@.......&@@@@@@         $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)             @@@@@@@&....@@@@ ...................@@@@@....@@@@@@@             $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)                  @@@@@@@@@@@@@@@@.......... @@@@@@@@@@@@@@@@                 $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)                       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                       $(GREEN)┃┃\n\
$(GREEN)┃┃$(CLR_END)                                @@@@@@@@@@@@@@                                $(GREEN)┃┃\n\
$(GREEN)┃┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛┃\n\
$(GREEN)┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\

#BASICS
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

#COLORS
CLR_END		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

#MINILIBX
LIBXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
MLX_PATH = minilibx-linux/

#PATH
SRC_PRE = src/
PRINTF_PRE = printf/
GNL_PRE = gnl/

#FILES
FILES = algo_bis.c  atoi.c       move_p.c   move_s.c     split.c        other_algo.c\
		algo.c      ft_free.c    move_r.c   mv_opti.c    ranker.c       utils.c \
		algo_ter.c  lst_utils.c  move_rr.c  push_swap.c  secu_social.c  verif.c


PRINTF_FILES = ft_printf.c ft_printf2.c ft_putunbr.c \
				ft_strchr.c ft_strlen.c ft_write.c \
				ft_putnbr_base.c ft_putpoint.c

GNL_FILES = get_next_line.c get_next_line_utils.c \

#MAKE OBJECTS
SRCS = $(addprefix $(SRC_PRE), $(FILES))
PRINTF_SRCS = $(addprefix $(PRINTF_PRE), $(PRINTF_FILES))
GNL_SRCS = $(addprefix $(GNL_PRE), $(GNL_FILES))
LIBFT_SRCS = $(addprefix $(LIBFT_PRE), $(LIBFT_FILES))

OBJS = $(SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

all: $(NAME)

${NAME}: 	${OBJS} logo make_printf #make_gnl
	@echo "\n🚧 $(GREEN)Compilation ${CLR_END}of ${YELLOW}$(NAME) ${CLR_END}... 🚧"
#	@make -sC $(MLX_PATH)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo "\n$(GREEN)   Compilation OK $(CLR_END)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

logo:
	clear
	@echo "$(CLR_END)$(AR_MAKER) $(CLR_END)"

make_printf:
	@echo "\n🚧 $(GREEN)Compiling${CLR_END} :${YELLOW} Printf ${CLR_END}... 🚧"

make_gnl:
	@echo "\n🚧 $(GREEN)Compiling${CLR_END} :${YELLOW} Get_next_line ${CLR_END}... 🚧"

clean:
#	@make clean -sC $(MLX_PATH)
	@rm -f $(OBJS)
	@echo "-> all .o $(RED)     cleaned $(CLR_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "-> executable $(RED) cleaned $(CLR_END)"

re: fclean all