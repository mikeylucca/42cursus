/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:57:41 by misoares          #+#    #+#             */
/*   Updated: 2025/05/14 16:00:18 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../../sources/libft.h"

typedef struct s_printf
{
	va_list	ap;
	int		width;
	int		widlen;
	int		pound;
	int		zero_p;
	int		dash;
	int		plus;
	int		dot;
	int		prec;
	int		dotlen;
	int		hexlen;
	int		is_space;
	int		len;
	int		forspec;
	char	*conv;
}	t_printf;

//printf.c
int			ft_printf(char const *format, ...);
t_printf	*struct_init(t_printf *printed);

//check_spec.c
void		convert_print(t_printf *printed, int i);
void		check_spec(t_printf *printed, char const *format, int get_spec);

//various print_* for conversion
void		print_str(t_printf *printed);
void		print_char(t_printf *printed);
void		print_signed(t_printf *printed);
void		print_unsigned(t_printf *printed);
void		print_ptr(t_printf *printed);

//flag specific
void		print_hexa_l(t_printf *printed);
void		print_hexa_u(t_printf *printed);
int			flaglen(unsigned long long n);
int			hexlen(t_printf *printed, unsigned int nb);
void		ft_putnbr_unsigned_int(unsigned int nbr);
void		update_flag(t_printf *printed, int spec);
void		flag_conflicts(t_printf *printed, int spec);
void		get_precision(t_printf *printed, char const *format, int get_spec);
int			signed_len(long long nbr);
void		ft_putnbr_long(long long int nb, int fd);
int			get_len(t_printf *printed, long long nbr);
void		signed_dash(t_printf *printed, char *sign, int len, long long nbr);
void		sig_nodash(t_printf *printed, char *sign, int len, long long nbr);
void		signprint(t_printf *printed, int len, long long nbr);
void		pzero(t_printf *printed, char *sign, int len);
void		nodash_base(t_printf *printed, int len);
void		l_dash(t_printf *printed, int len, unsigned int nbr);
void		lx_hex(t_printf *printed, unsigned long long n);
void		l_print(t_printf *printed, int len, unsigned int nbr);
void		u_dash(t_printf *printed, int len, unsigned int nbr);
void		ux_hex(t_printf *printed, unsigned long long n);
void		u_print(t_printf *printed, int len, unsigned int nbr);
void		str_no_dash(t_printf *printed, int len);
void		str_dash(t_printf *printed, int len);
void		ft_putnbr_long(long long int nb, int fd);
char		*plus_sign(t_printf *printed, char *sign);
void		signprint(t_printf *printed, int len, long long nbr);

#endif
