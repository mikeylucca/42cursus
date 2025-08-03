/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:19:09 by misoares          #+#    #+#             */
/*   Updated: 2025/08/03 22:03:39 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static inline bool is_digit(char c)
{
	return(c >= '0' && c <= '9');
}

static inline bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static const char *input_validate(const char *str)
{
	int len;
	const char *number;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit(RED"Only Positive values allowed"RESET);
	if (!is_digit(*str))
		error_exit(RED"Only digits (0-9) allowed"RESET);
	number = str;
	while (is_digit(*str++))
		len++;
	while (len > 10)
		error_exit(RED"Value too big, limit is INT_MAX"RESET);
	return (number);
}


static long philo_atol(const char *str)
{
	long num;

	num = 0;
	str = input_validate(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - OFFSET);
	if (num > INT_MAX)
		error_exit(RED"Value too big, limit is INT_MAX"RESET);
	return (num);
}


/*
*./philo 5 800 200 200 [5]

!check if they are:
!	- actual numbers
!	- not over int_max
!	- timestamp > 60
*/

void	input_parse(t_data *data, char **av)
{
	data->philo_nbr = philo_atol(av[1]);
	data->time_to_die = philo_atol(av[2]) * 1e3; //* 1e3 = 1000
	data->time_to_eat = philo_atol(av[3]) * 1e3;
	data->time_to_sleep = philo_atol(av[4]) * 1e3;
	if (data->time_to_die < 1e4 || data->time_to_eat < 1e4
		|| data->time_to_sleep < 1e4)
	{
		error_exit(RED"Timestamp lower than 10ms"RESET);
	}
	if (data->philo_nbr > MAX_PHILOS)
	{
		error_exit(RED"Maximum amount of Philos is 250"RESET);
	}
	if (av[5])
	{
		data->max_meals = philo_atol(av[5]);
	}
}
