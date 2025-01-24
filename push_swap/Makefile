# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 21:56:12 by misoares          #+#    #+#              #
#    Updated: 2025/01/24 19:00:47 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIRECTORY = libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)libft.h
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADER_LIST = push_swap.h
HEADER_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_LIST = algorithm.c ft_pushswap_split.c swap_movements.c main.c parser.c \
			push_movements.c push_swap_init.c reverse_rotate_movements.c rotate_movements.c \
			small_sort.c stack_init.c stack_utils.c

SRCS_DIRECTORY = srcs/
SRC = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECT_LIST = $(SRCS_LIST:.c=.o)
OBJECTS_DIRECTORY = objs/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))

CC = cc
CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

LIBS = -L$(LIBFT_DIRECTORY) -lft
INCLUDES = -I./includes -I./libft/


# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RESET   = \033[0m

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@if $(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) $(LIBS) -o $(NAME); \
	then \
		make norm -s; \
		echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) created!"; \
	else \
		echo "[" "$(RED)Error$(RESET)" "] | An error occurred while creating push_swap."; \
		make fclean; \
		echo "[" "$(RED)Error$(RESET)" "] | All objects Cleaned."; \
	fi

$(OBJECTS_DIRECTORY):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Creating objects..."
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Objects ready!"

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
	@make -sC $(LIBFT_DIRECTORY)  > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@make -sC $(LIBFT_DIRECTORY) clean > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIRECTORY) fclean > /dev/null 2>&1
	@rm -rf $(MLX)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

norm:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Norminetting...$(RESET)"
	@if norminette srcs/ libft/ > .norminette.log ; then \
	    if grep -q "Error!" .norminette.log; then \
	        echo "[" "$(RED)!!$(RESET)" "] | Norminette found errors.$(RESET)"; \
	        grep "Error!" .norminette.log | awk '{print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	    else \
	        echo "[" "$(GREEN)OK$(RESET)" "] | Norminette passed!"; \
	    fi; \
	else \
	    echo "[" "$(RED)XX$(RESET)" "] | Norminette Error!"; \
		norminette srcs/ libft/ | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	fi

re: fclean
	clear && make -s
