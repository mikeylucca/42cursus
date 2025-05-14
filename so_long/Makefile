# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 08:09:05 by misoares          #+#    #+#              #
#    Updated: 2025/05/14 15:54:41 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME					=	so_long

CC					=	@gcc
CFLAGS					=	-Wall -Wextra -Werror -g3
RM						=	@rm -rf

SRCS					=	main error struct_init struct_tiles_init \
						parsing map_init check_map flood_fill elem_pos \
						start_game ft_xpm events_hook tiles move mlx_closing game_end \
               
SRC					=	$(addsuffix .c, $(addprefix sources/, $(SRCS)))

OBJ_DIR					=	obj
OBJ						=	$(SRC:sources/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH				=	./libft
LIBFT					=	$(LIBFT_PATH)/libft.a
LIBINCL					=	-L libft/ -lft

MLX_PATH				=	./mlx
MLX						=	$(MLX_PATH)/libmlx_Linux.a
MLXFLAGS					=	-L mlx/ -lmlx -lXext -lX11

#DEPS					=	$(OBJ:%.o=%.d)

$(OBJ_DIR)/%.o:			sources/%.c
						$(CC) $(CFLAGS) -I libft/sources -I mlx -I sources  -c $< -o $@ $(INCLS)

all:					$(NAME) 


$(NAME):				$(LIBFT) $(OBJ_DIR) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBINCL) $(MLXFLAGS)
						@echo "\033[32m[so_long created]\033[0m"
						

$(LIBFT):
						$(MAKE) -C $(LIBFT_PATH) all -s
						@echo "\033[32m[Libft created]\033[0m"

$(OBJ_DIR):
						@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
						@mkdir -p $(OBJ_BONUS_DIR)

#-include $(DEPS)

clean:
						@$(MAKE) -C $(LIBFT_PATH) clean
						@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
						@echo "\033[33m[Cleaned up]\033[0m"

fclean:					clean
						$(MAKE) -C $(LIBFT_PATH) fclean
						$(RM) $(NAME) $(NAME_BONUS)
						@echo "\033[33m[Fully cleaned up]\033[0m"

re:						fclean 