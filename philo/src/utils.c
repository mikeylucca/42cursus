/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:52:43 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 15:37:25 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	cleaner(t_data *data)
{
	t_philo *philo;
	int i;

	i = -1;
	while (data->philo_nbr > ++i)
	{
		philo = data->philos + i;
		mutex_handler(&philo->philo_mutex, DESTROY);
	}
	mutex_handler(&data->write_mutex, DESTROY);
	mutex_handler(&data->data_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}

long	gettime(t_timecode timecode)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failed");
	if (SECOND == timecode)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == timecode)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == timecode)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("Wrong input to gettime");
	return (1337);
}

// Precise usleep cause the normal one can give more than what is asked

void	precise_usleep(long usec, t_data *data)
{
	long start;
	long elapsed;
	long remain;

	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < usec)
	{
		if (simulation_done(data))
			break;
		elapsed = gettime(MICROSECOND) - start;
		remain = usec - elapsed;
		if (remain > 1e3)
			usleep(remain / 2);
		else
		{
			while (gettime(MICROSECOND) - start < usec)
				;
		}
	}
}

void    error_exit(const char *error)
{
	printf(RED "%s\n" RESET, error);
	exit(EXIT_FAILURE);
}