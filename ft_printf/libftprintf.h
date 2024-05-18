#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_digit(int n);
int	ft_print_hex(unsigned int value, int asc);
int	ft_print_pointer(unsigned long value);
int	ft_printunsigned(unsigned int nb);

#endif