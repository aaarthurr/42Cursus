# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 18:35:47 by arpages           #+#    #+#              #
#    Updated: 2024/12/12 15:12:35 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c ft_printf2.c ft_putunbr.c \
		ft_strchr.c ft_strlen.c ft_write.c \
		ft_putnbr_base.c ft_putpoint.c test.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): banner $(OBJS)
	@echo "\033[0;32m- - - ft_printf Compiled - - -\n"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;35mGenerating ft_printf objects... %-33.33s\r\n" $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "\033[0;31mft_printf objects cleaned!\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mft_printf removed!\n"

re: fclean all

banner:
	@echo "\033[36m"
	@echo "  ,----,------------------------------,------.  "
	@echo "  | ## |                              |    - |  "
	@echo "  | ## |      - ! ft_printf ! -       |    - |  "
	@echo "  |    |------------------------------|    - |  "
	@echo "  |    ||............................||      |  "
	@echo "  |    ||,-                        -.||      |  "
	@echo "  |    ||___                      ___||    ##|  "
	@echo "  |    ||---'--------------------'---||      |  "
	@echo "  '--mb'|_|______________________==__|'------'  "
	@echo "\033[0m"

.PHONY: all clean fclean re banner