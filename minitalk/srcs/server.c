/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:52 by misoares          #+#    #+#             */
/*   Updated: 2025/04/24 14:45:28 by misoares         ###   ########.fr       */
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

/* // reads every bit and appends it to bits
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
} */

static void	ft_confirm(int sig)
{
    static char		bits[9] = {0}; // Fixed-size buffer for 8 bits + null terminator
    static int		bitcount;


	bitcount = 0;

    if (sig == SIGUSR1)
        bits[bitcount] = '1'; // Append '1' for SIGUSR1
    else
        bits[bitcount] = '0'; // Append '0' for SIGUSR2

    bitcount++;

    if (bitcount == 8) // If 8 bits are collected
    {
        bits[8] = '\0';   // Reset the buffer
        ft_convert(bits); // Convert and print the character
        bitcount = 0;     // Reset bit count
    }
}

//quando receber nulo printa quebra de linha

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