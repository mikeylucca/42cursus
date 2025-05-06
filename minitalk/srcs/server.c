/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:52 by misoares          #+#    #+#             */
/*   Updated: 2025/05/06 18:04:09 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	get_len(int *bit, char **str, int *len_rcvd, int signal)
{
	static int	len = 0;

	if (signal == SIGUSR2)
		len += ft_rec_power(2, *bit);
	if (*bit == 31)
	{
		*len_rcvd = 1;
		*str = ft_calloc(len + 1, sizeof(char));
		*bit = 0;
		len = 0;
		return ;
	}
	(*bit)++;
}

static void	reset_vars(int *len_rcvd, char **str, int *idx, int pid)
{
	*len_rcvd = 0;
	if (*str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = NULL;
	}
	*idx = 0;
	kill(pid, SIGUSR1);
}

static void	ft_sig_handle(int signal, siginfo_t *info, void *context)
{
	static int		char_val = 0, bit = 0, len_rcvd = 0;
	static int		idx = 0;
	static char		*str = NULL;
	static pid_t	pid;

	(void)context;
	pid = info->si_pid;
	if (!len_rcvd)
		get_len(&bit, &str, &len_rcvd, signal);
	else
	{
		if (signal == SIGUSR2)
			char_val += ft_rec_power(2, bit);
		if (bit == 7)
		{
			str[idx++] = char_val;
			if (char_val == '\0')
				reset_vars(&len_rcvd, &str, &idx, pid);
			char_val = 0;
			bit = 0;
		}
		else
			bit++;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = (int)getpid();
	ft_printf("PID: %i\n", pid);
	ft_printf("-----------------------------------\n");
	ft_printf("Messages start here:\n");
	ft_printf("\n");
	sa.sa_sigaction = ft_sig_handle;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
