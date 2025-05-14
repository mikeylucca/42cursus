/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:57:41 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 15:58:20 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../../sources/libft.h"

typedef struct s_printf
{
	va_list	ap;
	int		width;
	int		pound;
	int		zero_p;
	int		dash;
	int		plus;
	int		sign;
	int		zero_digit;
	int		is_space;
	int		len;
	int		percent;
	char	*conv;
}	t_printf;

//printf.c
int			ft_printf(char const *format, ...);

//check_spec.c
void		convert_print(t_printf *printed, int i);
void		check_spec(t_printf *printed, char const *format, int get_spec);

//various print_* for conversion
int			print_str(t_printf *printed);
void		print_char(t_printf *printed);
void		print_signed(t_printf *printed);
void		print_unsigned(t_printf *printed);
void		print_hexa(t_printf *printed, int hex);
void		print_ptr(t_printf *printed);

#endif
