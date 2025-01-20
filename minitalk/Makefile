# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 01:13:06 by misoares          #+#    #+#              #
#    Updated: 2025/01/20 01:16:37 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd ft_printf && make all
	@gcc -Wall -Wextra -Werror srcs/server.c ft_printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror srcs/client.c ft_printf/libftprintf.a -o client

clean:
	@cd ft_printf && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd ft_printf && make fclean

re: fclean all