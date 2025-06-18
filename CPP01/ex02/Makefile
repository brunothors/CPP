# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 18:47:51 by bnespoli          #+#    #+#              #
#    Updated: 2025/06/17 19:16:10 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	brain

CC:=	c++

CPP_FLAGS	:=	$(INCLUDES) -Wall -Werror -Wextra -std=c++98

SRC_FILES	+=	main.cpp

all: $(NAME)

$(NAME):
	$(CC) main.cpp -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re