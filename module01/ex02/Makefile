# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:53:52 by pgros             #+#    #+#              #
#    Updated: 2023/04/04 16:54:22 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_02

CPP_C = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp

OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp
	${CPP_C} ${CPP_FLAGS} $< -c -o $@

${NAME}: ${OBJ}
	${CPP_C} ${CPP_FLAGS} ${OBJ} -o $@

all: ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}
	
re:	fclean all

.PHONY: all clean fclean re