# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 07:29:15 by bnespoli          #+#    #+#              #
#    Updated: 2025/06/19 22:01:12 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	fragtrap

CC:=	c++

INCLUDES	:=	$(addprefix -I , includes/)

CPP_FLAGS	:=	$(INCLUDES) -Wall -Werror -Wextra -std=c++98

SRC_FILES	+=	$(addprefix ./srcs/, \
				main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp )
				
OBJS_DIR	:=	./objs/
OBJS		:=	$(patsubst ./srcs/%.cpp, $(OBJS_DIR)%.o, $(SRC_FILES))

all: $(NAME)
	
$(OBJS_DIR)%.o: ./srcs/%.cpp
	mkdir -p $(OBJS_DIR)
	@echo "Compiling $< -> $@"
	$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Linking $(NAME)"
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re