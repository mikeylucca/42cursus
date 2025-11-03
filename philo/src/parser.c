/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:19:09 by misoares          #+#    #+#             */
/*   Updated: 2025/10/30 17:14:46 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	validate_digit_length(const char *str)
{
	int	len;

	len = 0;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		return (error_return(RED"Value too big, limit is INT_MAX"RESET));
	return (0);
}

static const char	*input_validate(const char *str)
{
	const char	*number;

	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		error_return(RED"Only Positive values allowed"RESET);
		return (NULL);
	}
	if (!is_digit(*str))
	{
		error_return(RED"Only digits (0-9) allowed"RESET);
		return (NULL);
	}
	number = str;
	if (validate_digit_length(str) == -1)
		return (NULL);
	return (number);
}

static long	philo_atol(const char *str)
{
	long	num;

	num = 0;
	str = input_validate(str);
	if (!str)
		return (-1);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - OFFSET);
	if (num > INT_MAX)
	{
		error_return(RED"Value too big, limit is INT_MAX"RESET);
		return (-1);
	}
	return (num);
}

static int	parse_and_convert(long *dest, char *arg, int convert)
{
	*dest = philo_atol(arg);
	if (*dest == -1)
		return (-1);
	if (convert)
		*dest *= CONVERSION_RATE_TO_MS;
	return (0);
}

/*
*./philo 5 800 200 200 [5]

!check if they are:
!	- actual numbers
!	- not over int_max
!	- timestamp > 60
*/

int	input_parse(t_data *data, char **av)
{
	if (parse_and_convert(&data->philo_nbr, av[1], 0) == -1)
		return (-1);
	if (parse_and_convert(&data->time_to_die, av[2], 1) == -1)
		return (-1);
	if (parse_and_convert(&data->time_to_eat, av[3], 1) == -1)
		return (-1);
	if (parse_and_convert(&data->time_to_sleep, av[4], 1) == -1)
		return (-1);
	if (data->time_to_die < MIN_TIME || data->time_to_eat < MIN_TIME
		|| data->time_to_sleep < MIN_TIME)
		return (error_return(RED"Timestamp lower than 60ms"RESET));
	if (data->philo_nbr > MAX_PHILOS)
		return (error_return(RED"Maximum amount of Philos is 200"RESET));
	if (av[5])
	{
		if (parse_and_convert(&data->max_meals, av[5], 0) == -1)
			return (-1);
	}
	else
		data->max_meals = -1;
	return (0);
}
