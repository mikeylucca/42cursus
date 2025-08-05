# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 21:41:05 by misoares          #+#    #+#              #
#    Updated: 2025/08/06 00:05:53 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= cub3d

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
LIBFT_DIR	= libraries/libft
MLX_DIR		= libraries/mlx/minilibx-linux

# Source files (automatically includes all .c files in src and subdirectories)
SRCS		= $(shell find $(SRC_DIR) -name "*.c" -type f | sed 's|$(SRC_DIR)/||')

# Object files (preserving directory structure in obj/)
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# MLX linking flags (Linux specific)
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Colors for output
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[0;31m
NC			= \033[0m # No Color

# Default target
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Created object directory$(NC)"

# Compile object files (with subdirectory support)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(NC)"

# Build libft
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)libft built successfully$(NC)"

# Build MLX
$(MLX):
	@echo "$(YELLOW)Building MLX...$(NC)"
	@if [ ! -f $(MLX_DIR)/libmlx.a ]; then \
		cd $(MLX_DIR) && \
		(./configure > /dev/null 2>&1 || \
		(echo "$(RED)MLX configure failed, trying manual build...$(NC)" && \
		make -f Makefile.gen > /dev/null 2>&1)) && \
		echo "$(GREEN)MLX built successfully$(NC)"; \
	else \
		echo "$(GREEN)MLX already built$(NC)"; \
	fi
	@if [ ! -f $(MLX_DIR)/libmlx.a ]; then \
		echo "$(RED)MLX build failed$(NC)"; \
		exit 1; \
	fi

# Link the final executable
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(NC)"

# Clean object files
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -f $(MLX_DIR)/configure ]; then \
		cd $(MLX_DIR) && (./configure clean > /dev/null 2>&1 || make clean > /dev/null 2>&1 || echo "MLX clean not available"); \
	fi
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files cleaned$(NC)"

# Clean everything
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(RED)Full clean completed$(NC)"

# Rebuild everything
re: fclean all

# Run the program
run: $(NAME)
	@./$(NAME)

# Debug mode
debug: CFLAGS += -fsanitize=address -g3
debug: re

# Check for norm errors (if you use norminette)
norm:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -v "OK" || echo "$(GREEN)Norm: OK$(NC)"

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the project"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove object files and executable"
	@echo "  re      - Rebuild everything"
	@echo "  run     - Build and run the program"
	@echo "  debug   - Build with debug flags"
	@echo "  norm    - Check norm compliance"
	@echo "  mlx     - Force rebuild MLX library"
	@echo "  help    - Show this help message"

# Force rebuild MLX
mlx:
	@echo "$(YELLOW)Force rebuilding MLX...$(NC)"
	@cd $(MLX_DIR) && make clean > /dev/null 2>&1 || true
	@rm -f $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a
	@$(MAKE) $(MLX)

.PHONY: all clean fclean re run debug norm help mlx

