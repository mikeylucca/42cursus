# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:13:55 by misoares          #+#    #+#              #
#    Updated: 2024/05/17 18:26:09 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		@ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
		
fclean:	clean
		rm -f $(NAME)

re:		fclean all