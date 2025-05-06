# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:13:55 by misoares          #+#    #+#              #
#    Updated: 2025/05/06 19:16:42 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = @cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

SRCS =	ft_printf.c ft_print_char.c ft_print_str.c \
		ft_print_hex.c ft_print_pointer.c ft_print_digit.c \
		ft_printunsigned.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "✅ libftprintf.a successfully built!"

makelibft:
	@echo "📦 Building libft..."
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@echo "🔨 Creating $(NAME)..."
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@echo "📄 Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
		
fclean: clean
	@echo "🧹 Cleaning all files..."
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all