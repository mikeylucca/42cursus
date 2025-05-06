/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:48 by misoares          #+#    #+#             */
/*   Updated: 2025/05/06 18:20:56 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	validate_syntax(int ac, char **av)
{
	int		idx;
	char	*str;

	idx = -1;
	if (ac != 3)
		return (error_print(3));
	str = av[1];
	while (str[++idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (error_print(2));
	}
	return (0);
}

static void	send_char(unsigned char ch, int pid)
{
	int	idx;

	idx = -1;
	while (++idx < 8)
	{
		if (ch & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		ch = ch >> 1;
		usleep(WAIT_TIME);
	}
}

static void	send_len(int msg_len, int pid)
{
	int	idx;

	idx = -1;
	while (++idx < 32)
	{
		if (msg_len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		msg_len = msg_len >> 1;
		usleep(WAIT_TIME);
	}
}

static void	ft_sig_send(int signal)
{
	static int	bits;
	static int	bytes;

	if (signal == SIGUSR2)
	{
		bits++;
		if (bits == 8)
		{
			bytes++;
			bits = 0;
		}
	}
	else if (signal == SIGUSR1)
	{
		ft_printf("Message Sent\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		idx;

	if (validate_syntax(ac, av) != 0)
		return (1);
	if (av[2][0] == '\0')
		return (error_print(2));
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1 || pid <= 0)
		return (error_print(2));
	signal(SIGUSR1, ft_sig_send);
	signal(SIGUSR2, ft_sig_send);
	idx = -1;
	send_len(ft_strlen(av[2]), pid);
	while (av[2][++idx])
		send_char(av[2][idx], pid);
	send_char(av[2][idx], pid);
	while (1)
		pause();
	return (0);
}
