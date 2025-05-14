# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 14:12:30 by misoares          #+#    #+#              #
#    Updated: 2025/05/14 15:30:44 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	libftprintf.a
CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -g3
AR						=	ar
ARFLAGS 				=	rcs
RM						=	rm -rf

SRCBAZ					=	ft_printf check_spec print_char print_str print_hexa print_ptr print_signed print_unsigned 
SRC						=	$(addsuffix .c, $(addprefix sources/, $(SRCBAZ)))

SRCADD					=	$(SRCBAZ) flags check_precision print_signed_util print_hexa_util print_str_util
SRCBONUS				=	$(addsuffix _bonus.c, $(addprefix bonus/, $(SRCADD)))

OBJ_DIR					=	obj
OBJ						=	$(SRC:sources/%.c=$(OBJ_DIR)/%.o)

OBJ_BONUS_DIR			=	objbonus
OBJ_BONUS				=	$(SRCBONUS:bonus/%.c=$(OBJ_BONUS_DIR)/%.o)

LIBFT_PATH				=	../sources
LIBFT					=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:			sources/%.c
						$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_BONUS_DIR)/%.o:	bonus/%.c
						$(CC) $(CFLAGS) -c $< -o $@

all:					$(NAME)

$(NAME):				$(LIBFT) $(OBJ_DIR) $(OBJ)
						cp	$(LIBFT) $(NAME)
						$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(LIBFT):
						$(MAKE) -C $(LIBFT_PATH) all

$(OBJ_DIR):
						mkdir -p $(OBJ_DIR)


$(OBJ_BONUS_DIR):
						mkdir -p $(OBJ_BONUS_DIR)

# bonus:					$(LIBFT) $(OBJ_BONUS_DIR) $(OBJ_BONUS)
# 						cp	$(LIBFT) $(NAME)
# 						$(AR) $(ARFLAGS) $(NAME) $(OBJ_BONUS)

clean:
						$(MAKE) -C $(LIBFT_PATH) clean
						$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean:					clean
						$(MAKE) -C $(LIBFT_PATH) fclean
						$(RM) $(NAME)

re:						fclean all

.PHONY:	all clean fclean re bonus libft
