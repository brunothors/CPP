# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 20:21:26 by bnespoli          #+#    #+#              #
#    Updated: 2025/06/17 20:22:22 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	replace

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