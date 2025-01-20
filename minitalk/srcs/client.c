/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:48 by misoares          #+#    #+#             */
/*   Updated: 2025/01/20 01:16:30 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// sends the binary message to the server
// waits so the signals won't get ignored
static void	ft_send_msg(int pid, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

// converts the string to binary
// starts from the end of the string with conversion
// puts the binary number at the end of ret
static char	*ft_to_bit(char *s, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	ret = ft_calloc(i * 8 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(s) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}

// prints possible errors
// takes the first argument and converts it to the server PID
// coverts the string to binary
// sends the binary chars to the server
int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_to_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("allocation went wrong\n");
		return (0);
	}
	ft_send_msg(pid, bits);
	free(bits);
}