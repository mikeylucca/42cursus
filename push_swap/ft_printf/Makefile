# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:13:55 by misoares          #+#    #+#              #
#    Updated: 2024/05/22 17:51:07 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

SRCS =	ft_printf.c ft_print_char.c ft_print_str.c \
		ft_print_hex.c ft_print_pointer.c ft_print_digit.c \
		ft_printunsigned.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
		make -C $(LIBFTDIR)
		cp $(LIBFTDIR)/$(LIBFTNAME) .
		mv $(LIBFTNAME) $(NAME)

$(NAME):	makelibft $(OBJS)
		@ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
		cd $(LIBFTDIR) && make clean
		
fclean:	clean
		rm -f $(NAME)
		cd $(LIBFTDIR) && make fclean

re:		fclean all