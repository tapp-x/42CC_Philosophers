# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 16:56:39 by tappourc          #+#    #+#              #
#    Updated: 2024/04/03 15:18:08 by tappourc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
INCLUDE = includes
CFLAGS = -Wall -Werror -Wextra -g -I $(INCLUDE)
RM = rm -f

SRC = \
		main.c \
		./src/ft_atoi.c \
		./src/init_data.c \
		./src/sleep.c \

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
