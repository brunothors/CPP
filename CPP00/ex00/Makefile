# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 19:12:25 by bnespoli          #+#    #+#              #
#    Updated: 2025/06/14 20:06:12 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)

NAME: $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(NAME)

val: all
	@valgrind --quiet --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re run val