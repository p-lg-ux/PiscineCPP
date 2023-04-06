# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 13:18:44 by pgros             #+#    #+#              #
#    Updated: 2023/04/06 18:03:49 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_04

CPP_C = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp \
		Replace.cpp

INC =	Replace.hpp

OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp ${INC}
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