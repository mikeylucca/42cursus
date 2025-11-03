/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:52:43 by misoares          #+#    #+#             */
/*   Updated: 2025/11/03 15:04:17 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	cleaner(t_data *data)
{
	t_philo	*philo;
	int		i;

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
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		error_return("Gettimeofday failed");
		return (-1);
	}
	if (SECOND == timecode)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == timecode)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == timecode)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		return (-1);
}

// Precise usleep cause the normal one can give more than what is asked

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	remain;
	long	check_counter;

	check_counter = 0;
	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < usec)
	{
		elapsed = gettime(MICROSECOND) - start;
		remain = usec - elapsed;
		if (remain > 1e3)
			usleep(remain / 2);
		else
		{
			while (gettime(MICROSECOND) - start < usec)
			{
				check_counter++;
				if (check_counter % 50000 == 0 && simulation_done_unsafe(data))
					break ;
			}
		}
	}
}

int	error_return(const char *error)
{
	printf(RED "%s\n" RESET, error);
	return (-1);
}
