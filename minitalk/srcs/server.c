/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:52 by misoares          #+#    #+#             */
/*   Updated: 2025/01/20 01:46:21 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// converts binary to ascii and prints it
static void	ft_convert(char *s)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	write(1, &c, 1);
}

// reads every bit and appends it to bits
// if its a 8 bit it prints the char to the console
static void	ft_confirm(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_appendC(bits, '0');
	else
		bits = ft_appendC(bits, '1');
	if (bitcount == 8)
	{
		ft_convert(bits);
		free(bits);
		bits = NULL;
	}
}

// prints the server PID
// waits endlessly for a signal to convert
int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	while (1 == 1)
	{
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (0);
}