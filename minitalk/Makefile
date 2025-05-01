# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 01:13:06 by misoares          #+#    #+#              #
#    Updated: 2025/05/01 22:05:42 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
OBJDIR = objs
FT_PRINTF_DIR = ft_printf

# Source and object files
SERVER_SRC = $(SRCDIR)/server.c
CLIENT_SRC = $(SRCDIR)/client.c
SERVER_OBJ = $(OBJDIR)/server.o
CLIENT_OBJ = $(OBJDIR)/client.o

# Targets
SERVER = server
CLIENT = client
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Default target
all: $(SERVER) $(CLIENT)

# Build server
$(SERVER): $(SERVER_OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFTPRINTF) -o $(SERVER)

# Build client
$(CLIENT): $(CLIENT_OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFTPRINTF) -o $(CLIENT)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libftprintf
$(LIBFTPRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files
clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean everything
fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all