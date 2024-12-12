# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 15:44:50 by arpages           #+#    #+#              #
#    Updated: 2024/12/12 15:09:11 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): banner $(OBJS)
	@echo "\033[0;32m- - - Mandatory Part Compiled - - -\n"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: banner $(OBJS) $(OBJS_BONUS)
	@echo "\033[0;32m- - - Bonus Part Compiled - - -\n"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;35mGenerating objects... %-33.33s\r\n" $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "\033[0;31mLibft objects cleaned!\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mLibft removed!\n"

re: fclean all

banner:
	@echo "\033[36m"
	@echo " ___       ___  ________  ________ _________   "
	@echo "|\  \     |\  \|\   __  \|\  _____\\___   ___\ "
	@echo "\ \  \    \ \  \ \  \|\ /\ \  \__/\|___ \  \_| "
	@echo " \ \  \    \ \  \ \   __  \ \   __\    \ \  \  "
	@echo "  \ \  \____\ \  \ \  \|\  \ \  \_|     \ \  \ "
	@echo "   \ \_______\ \__\ \_______\ \__\       \ \__\ "
	@echo "    \|_______|\|__|\|_______|\|__|        \|__| "
	@echo "                                               "
	@echo "                                               "
	@echo "                                               "
	@echo "\033[0m"

.PHONY: all bonus clean fclean re banner

                                               