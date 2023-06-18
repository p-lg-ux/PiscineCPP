# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 15:35:28 by pgros             #+#    #+#              #
#    Updated: 2023/06/18 16:03:53 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CPP_C = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp \
		Serializer.cpp

INC =	Serializer.hpp \
		Data.hpp

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
