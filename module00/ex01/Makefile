# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgros <pgros@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:16:22 by pgros             #+#    #+#              #
#    Updated: 2023/03/08 15:22:05 by pgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CPP_C = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp \
		Contact.cpp \
		PhoneBook.cpp

INC =	Contact.hpp \
		PhoneBook.hpp

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