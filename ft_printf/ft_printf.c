/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:16:35 by misoares          #+#    #+#             */
/*   Updated: 2024/05/18 18:23:17 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

 int	ft_print_stuff(char specifier, va_list ap)
{
	int counter;

	counter = 0;
	if (specifier == 'c')
		counter += ft_print_char(va_arg(ap, int)); // calls for int instead of char due to type promotion.
	else if (specifier == 's')
		counter += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		counter += ft_print_pointer((unsigned long)va_arg(ap, unsigned long));
	else if (specifier == 'i' || specifier == 'd')
		counter += ft_print_digit(va_arg(ap, int));
	else if (specifier == 'u')
		counter += ft_printunsigned((unsigned int)va_arg(ap, unsigned int));
	else if (specifier == 'x')
		counter += ft_print_hex((long)va_arg(ap, unsigned int), 87);
	else if (specifier == 'X')
		counter += ft_print_hex((long)va_arg(ap, unsigned int), 55);
	else if (specifier == '%')
		counter += ft_print_char('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int count;
	va_list ap; // argument pointer, points to the next argument since it knows the last known arg.
	
	va_start(ap, format);
	count = 0;
	while (*format) // iterates through the string until it reaches the % sign.
	{
		if (*format == '%')
		{
			count += ft_print_stuff(*(++format), ap);
		}
		else
			count += write(1, format, 1); // write returns an int so we capture it in order to return it as well.
		format++;
	}
	va_end(ap); // destroys ap in order to not have memory leaks
	return (count); // returns the amount of characters printed.
}
