# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 13:14:09 by kpuwar            #+#    #+#              #
#    Updated: 2023/10/28 23:50:44 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixedv2

CC = c++
CFLAGS = -Wextra -Wall -Werror -std=c++98

INCLUDES = Fixed.hpp
SRCS = main.cpp Fixed.cpp
OBJS = ${SRCS:.cpp=.o}

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
