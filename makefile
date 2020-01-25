# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 12:16:49 by apavel            #+#    #+#              #
#    Updated: 2020/01/22 16:23:52 by apavel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c
FLAGS = -Wall -Werror -Wextra
all: ${OBJS}
	gcc  ${SRCS} -o gnl -D BUFFER_SIZE=3
