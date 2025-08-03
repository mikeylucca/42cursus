NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread
LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRCS:.c=.o)

MAKEFLAGS += --no-print-directory
TOTAL_FILES := $(words $(SRCS))
COMPILED := 0

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@printf "Linking $(NAME)...\n"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "✅ Build successful: $(NAME)\n"

$(LIBFT):
	@printf "Building libft...\n"
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1
	@printf "✅ libft built successfully\n"

%.o: %.c
	@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	@$(eval PERCENT=$(shell echo $$(($(COMPILED) * 100 / $(TOTAL_FILES)))))
	@$(eval BARS=$(shell echo $$(($(COMPILED) * 30 / $(TOTAL_FILES)))))
	@$(eval SPACES=$(shell echo $$((30 - $(BARS)))))
	@printf "\rCompiling [%3d%%] [%.*s%*s] [%d/%d] %s" \
		$(PERCENT) \
		$(BARS) "==============================" \
		$(SPACES) "" \
		$(COMPILED) $(TOTAL_FILES) \
		"$<"
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ $(COMPILED) -eq $(TOTAL_FILES) ]; then \
		printf "\r✅ Compilation complete! [100%%] [==============================] [%d/%d]%20s\n" $(COMPILED) $(TOTAL_FILES) " "; \
	fi

clean:
	@printf "🧹 Cleaning object files...\n"
	@$(RM) $(OBJ) 2>/dev/null || true
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@printf "✅ Clean complete.\n"

fclean: clean
	@printf "🗑️  Removing $(NAME)...\n"
	@$(RM) $(NAME) 2>/dev/null || true
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	@printf "✅ Full clean complete.\n"

re: fclean all

.PHONY: all clean fclean re