/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:23:00 by misoares          #+#    #+#             */
/*   Updated: 2024/05/16 18:26:55 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* static int print_char(int c)
{
	return (write(1, &c, 1));
}

static int print_str(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
} */
int ft_print_hexup(long nbr, int base)
{
	int count;
	char *sym;

	count = 0;
	sym = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (print_digit(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (print_char(sym[nbr]));
	else
	{
		count = print_digit(nbr / base, base);
		return (count + print_char(nbr % base));
	}
}
