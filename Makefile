# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 16:56:39 by tappourc          #+#    #+#              #
#    Updated: 2024/03/30 17:18:12 by tappourc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I
RM = rm -f
NAME = philo

SRC = \
	${SRC_PATH}main.c

OBJ	= ${SRC:.c=.o}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}


clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re bonus
