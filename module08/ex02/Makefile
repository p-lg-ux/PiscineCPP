# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 19:14:53 by pgros             #+#    #+#              #
#    Updated: 2023/06/28 12:04:05 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = stl02

CPP_C = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp

INC =	MutantStack.hpp

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