/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:52 by misoares          #+#    #+#             */
/*   Updated: 2025/05/01 22:10:13 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error_handler(int i)
{
	if (i == 0)
	{
		write(1, "Error KILL\n", 12);
		exit(1);
	}
	if (i == 1)
	{
		write(1, "Error SIGACTION\n", 17);
		exit(1);
	}
}

void	ft_process_character(unsigned char val, int id)
{
    if (val == 0)
    {
        write(1, "\n", 1);
        if (kill(id, SIGUSR2) == -1)
            ft_error_handler(0);
    }
    else
        write(1, &val, 1);
}

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
    static unsigned char	val = 0;
    static int				bit = 1;
    static int				id = 0;

    if (info->si_pid != 0)
        id = info->si_pid;
    (void)context;
    if (sig == SIGUSR1)
        val += 0;
    if (sig == SIGUSR2)
        val += bit;
    bit <<= 1;
    if (bit == 256)
    {
        bit = 1;
        ft_process_character(val, id); // Process the received character
        val = 0;
    }
    if (kill(id, SIGUSR1) == -1)
        ft_error_handler(0);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_signal_handler;
	pid = getpid();
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_error_handler(1);
		return (1);
	}
	write(1, "Server PID = ", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
