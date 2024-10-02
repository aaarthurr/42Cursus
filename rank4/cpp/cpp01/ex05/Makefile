# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arpages <arpages@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 14:05:39 by arpages           #+#    #+#              #
#    Updated: 2024/06/16 15:49:15 by arpages          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Harl
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main Harl

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Harl.hpp

#Colors:
RESET		:= \033[0m
RED		    := \033[1;5;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[24;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m


#ascii name: big
BANNER = \n\
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n\
┃      _____ _____  _____   ___  __    ┃ \n\
┃     / ____|  __ \|  __ \ / _ \/_ |   ┃ \n\
┃    | |    | |__) | |__) | | | || |   ┃ \n\
┃    | |    |  ___/|  ___/| | | || |   ┃ \n\
┃    | |____| |    | |    | |_| || |   ┃ \n\
┃     \_____|_|    |_|     \___/ |_|   ┃ \n\
┃                                      ┃ \n\
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ \n\
:                EX 05                 : \n\


ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean re

all: $(NAME)

$(NAME):print $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"
	
fclean: clean
	@$(RM) $(OBJDIR)
	@printf "$(YELLOW)    - Objects removed.$(RESET)\n"

re: clean all

print:
	@echo "$(BLUE)$(BANNER)$(CLR_END)"