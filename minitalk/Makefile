# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 01:13:06 by misoares          #+#    #+#              #
#    Updated: 2025/05/06 19:42:01 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

# Directories
SRCDIR = srcs
OBJDIR = objs
FT_PRINTF_DIR = ft_printf

# Source and object files
SERVER_SRC = $(SRCDIR)/server.c
CLIENT_SRC = $(SRCDIR)/client.c
UTIL_SRC   = $(SRCDIR)/error_print.c
SERVER_OBJ = $(OBJDIR)/server.o
CLIENT_OBJ = $(OBJDIR)/client.o
UTIL_OBJ   = $(OBJDIR)/error_print.o

# Targets
SERVER = server
CLIENT = client
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Default target
all: $(SERVER) $(CLIENT)

# Build server
$(SERVER): $(SERVER_OBJ) $(UTIL_OBJ) $(LIBFTPRINTF)
	@echo "🔨 Building server..."
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTIL_OBJ) $(LIBFTPRINTF) -o $(SERVER)
	@echo "🤖 Server compilation done."


# Build client
$(CLIENT): $(CLIENT_OBJ) $(UTIL_OBJ) $(LIBFTPRINTF)
	@echo "🔨 Building client..."
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTIL_OBJ) $(LIBFTPRINTF) -o $(CLIENT)
	@echo "🤖 Client compilation done."

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "📄 Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libftprintf
$(LIBFTPRINTF):
	@echo "📦 Building libftprintf..."
	@$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files
clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean everything
fclean: clean
	@echo "🧹 Cleaning all files..."
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all