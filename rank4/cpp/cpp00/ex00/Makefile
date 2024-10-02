# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arpages <arpages@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 16:09:11 by arthur            #+#    #+#              #
#    Updated: 2024/06/16 15:48:31 by arpages          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

#Colors:
RESET		:= \033[0m
RED		    := \033[1;5;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[24;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

BANNER = \n\
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n\
┃   _____ _____  _____     ___   ___   ┃ \n\
┃  / ____|  __ \|  __ \   / _ \ / _ \  ┃ \n\
┃ | |    | |__) | |__) | | | | | | | | ┃ \n\
┃ | |    |  ___/|  ___/  | | | | | | | ┃ \n\
┃ | |____| |    | |      | |_| | |_| | ┃ \n\
┃  \_____|_|  __|_| ___   \___/ \___/  ┃ \n\
┃                                      ┃ \n\
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ \n\
:                EX 00                 : \n\

.PHONY: all clean re

all: $(NAME)

$(NAME): print
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(FLAGS) megaphone.cpp -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

clean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

fclean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: clean all

print:
	@echo "$(BLUE)$(BANNER)$(CLR_END)"