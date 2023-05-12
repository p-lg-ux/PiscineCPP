# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:59:24 by pgros             #+#    #+#              #
#    Updated: 2023/05/12 17:19:19 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_03

CPP_C = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = 	main.cpp \
		AMateria.cpp \
		Cure.cpp \
		Ice.cpp \
		Character.cpp \
		MateriaSource.cpp

INC =	AMateria.hpp \
		Cure.hpp \
		Ice.hpp \
		Character.hpp \
		ICharacter.hpp \
		IMateriaSource.hpp \
		MateriaSource.hpp

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