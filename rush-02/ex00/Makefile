# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 02:00:27 by hgeffroy          #+#    #+#              #
#    Updated: 2022/07/24 21:57:21 by hgeffroy         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = check_error.c data_proc_h.c display.c ft_split.c ft_split2.c string_proc.c main.c parsing.c

OBJS = ${SRCS:.c=.o}

NAME = rush-02

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all :
	gcc ${CFLAGS } -o ${NAME} ${SRCS}

fclean :
	${RM} ${OBJS}
	${RM} ${NAME}

.PHONY : all fclean
