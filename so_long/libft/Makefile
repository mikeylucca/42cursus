# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 10:35:01 by acloos            #+#    #+#              #
#    Updated: 2025/05/14 15:56:26 by misoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libft.a

CC					=	@gcc

CFLAGS				=	-Wall -Wextra -Werror -g

AR					=	ar
ARFLAGS				=	rcs

RM					=	@rm -rf

SRCBAZ				=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
	ft_isdigit ft_isprint ft_itoa ft_lstadd_back ft_lstadd_front ft_lstclear \
	ft_lstdelone ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize ft_memchr \
	ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
	ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat \
	ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strtrim ft_strrchr \
	ft_substr ft_tolower ft_toupper get_next_line\

SRC					=	$(addsuffix .c, $(addprefix sources/, $(SRCBAZ)))

SRCBAZPF			=	ft_printf check_spec check_precision flags print_char \
	print_str print_str_util print_hexa print_hexa_util print_unsigned \
	print_ptr print_signed print_signed_util \

SRCPF				=	$(addsuffix _bonus.c, $(addprefix ft_printf/bonus/, $(SRCBAZPF)))

OBJ_DIR				=	obj
OBJ					=	$(SRC:sources/%.c=$(OBJ_DIR)/%.o)

PRINTF_PATH			=	ft_printf/
PRINTF				=	$(PRINTF_PATH)/libftprintf.a

OBJPF_DIR			=	objpf
OBJPF				=	$(SRCPF:ft_printf/bonus/%.c=$(OBJPF_DIR)/%.o)

all:					$(NAME)

$(OBJ_DIR)/%.o:			sources/%.c 
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJPF_DIR)/%.o:		ft_printf/bonus/%.c
						$(CC) $(CFLAGS) -c $< -o $@

$(NAME):				$(OBJ_DIR) $(OBJ) $(OBJPF_DIR) $(OBJPF)
						$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJPF)


$(OBJ_DIR):
						mkdir -p $(OBJ_DIR)

$(OBJPF_DIR):
						mkdir -p $(OBJPF_DIR)

clean:
						$(RM) $(OBJ_DIR) $(OBJPF_DIR)

fclean:					clean
						$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re



