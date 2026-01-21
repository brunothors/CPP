# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 12:20:21 by bnespoli          #+#    #+#              #
#    Updated: 2026/01/21 17:04:39 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	Intern

CC:=	c++ -std=c++98

INCLUDES	:=	$(addprefix -I , includes/)

CPP_FLAGS	:=	$(INCLUDES) -Wall -Werror -Wextra

SRC_FILES	+=	$(addprefix ./srcs/, \
				main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp)
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

run: re
	clear && valgrind --leak-check=full ./$(NAME) && make fclean

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re