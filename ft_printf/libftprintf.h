#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int ft_print_char(int c);
int ft_print_str(char *str);
int ft_print_digit(long nbr, int base);
int ft_print_hexup(long nbr, int base);
int ft_print_pointer(unsigned long value, int asc);

#endif