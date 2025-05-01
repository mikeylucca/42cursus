/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:48 by misoares          #+#    #+#             */
/*   Updated: 2025/05/01 19:46:12 by misoares         ###   ########.fr       */
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

void	ft_send_terminator(int pid)
{
	static int	i = 0;

	if (i <= 8)
		if (kill(pid, SIGUSR1) == -1)
			ft_error_handler(0);
	i++;
}

void	ft_send_signal(int pid, char *str)
{
	static int	bit = 0;
	static char	*str_bis = 0;

	if (str)
		str_bis = str;
	if (*str_bis)
	{
		if ((((unsigned char)*str_bis >> bit) % 2) == 0)
			if (kill(pid, SIGUSR1) == -1)
				ft_error_handler(0);
		if ((((unsigned char)*str_bis >> bit) % 2) == 1)
			if (kill(pid, SIGUSR2) == -1)
				ft_error_handler(0);
		bit++;
		if (bit == 8)
		{
			str_bis++;
			bit = 0;
		}
	}
	if (!(*str_bis))
		ft_send_terminator(pid);
}

void	ft_receipt(int sig, siginfo_t *info, void *context)
{
	static int	id;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context ;
	if (sig == SIGUSR1)
		ft_send_signal(id, NULL);
	if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	struct sigaction	action;
	int pid;

	pid = ft_atoi(av[1]);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_receipt;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error_handler(1);
	 if (pid <= 0 || kill(pid, 0) == -1) // Validate PID
    {
        write(1, "Invalid PID\n", 12);
        return (1);
    }
	if (ac != 3)
	{
		ft_printf("Usage is PID + String");
		exit(EXIT_FAILURE);
	}
	ft_send_signal(pid, av[2]);
	while (1)
		pause();
	return (0);
}
