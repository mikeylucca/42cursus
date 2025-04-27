/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:48 by misoares          #+#    #+#             */
/*   Updated: 2025/04/27 14:45:40 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// ADD FUNC TO CHECK PID, se tiver qualquer coisa que n seja numero retorna erro

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
		usleep(100);
	}
	i = 0;
    while (i < 8)
    {
        kill(pid, SIGUSR2); // Send '0' as SIGUSR2
        usleep(100);
        i++;
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
	while (i > 0)
	{
		c = s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[(ft_strlen(s) * 8) - j - 1] = '1';
			else
				ret[(ft_strlen(s) * 8) - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}


int	is_numeric(const char *str)
{
    int	i;

    i = 0;
    if (!str || str[0] == '\0') // Check for empty string
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i])) // Check if each character is a digit
            return (0);
        i++;
    }
    return (1);
}

int	validate_pid(const char *pid_str)
{
    if (!is_numeric(pid_str))
    {
        ft_printf("Invalid PID: must contain only digits\n");
        return (0);
    }
    int pid = ft_atoi(pid_str);
    if (pid <= 0 || kill(pid, 0) == -1)
    {
        ft_printf("Invalid PID\n");
        return (0);
    }
    return (pid);
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
		ft_printf("Usage is PID + message\n");
		return (0);
	}
	if (!(pid = validate_pid(argv[1])))
        return (0);
	bits = ft_to_bit(argv[2], 0, 0);
    if (pid <= 0 || kill(pid, 0) == -1)
    {
        ft_printf("Invalid PID\n");
        free(bits);
        return (0);
    }
	if (bits == NULL)
	{
		ft_printf("U goofed the alloc\n");
		return (0);
	}
	ft_send_msg(pid, bits);
	ft_printf("\n");
	free(bits);
}
