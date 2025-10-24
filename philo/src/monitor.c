/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:42:59 by misoares          #+#    #+#             */
/*   Updated: 2025/10/24 13:06:55 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;
	bool	is_full;
	long	last_meal;

	mutex_handler(&philo->philo_mutex, LOCK);
	is_full = philo->full;
	last_meal = philo->last_mealtime;
	mutex_handler(&philo->philo_mutex, UNLOCK);
	if (is_full)
		return (false);
	elapsed = gettime(MILLISECOND) - last_meal;
	t_to_die = philo->data->time_to_die / 1000;
	if (elapsed > t_to_die)
		return (true);
	else
		return (false);
}

static bool	check_all_philos(t_data *p_data)
{
	int	i;

	i = -1;
	while (++i < p_data->philo_nbr)
	{
		if (philo_died(p_data->philos + i))
		{
			set_bool(&p_data->data_mutex, &p_data->end_simulation, true);
			write_status(DIED, p_data->philos + i, false);
			return (true);
		}
	}
	return (false);
}

void	*monitor_dinner(void *data)
{
	t_data	*p_data;
	long	sleep_time;

	p_data = (t_data *)data;
	while (!all_threads_running(&p_data->data_mutex,
			&p_data->threads_running_nbr, p_data->philo_nbr))
		usleep(THREAD_SYNC_POLL_INTERVAL);
	usleep(MONITOR_STARTUP_DELAY);
	sleep_time = p_data->time_to_die / 10;
	if (sleep_time < 100)
		sleep_time = 100;
	if (sleep_time > 1000)
		sleep_time = 1000;
	while (true)
	{
		if (simulation_done(p_data))
			break ;
		if (check_all_philos(p_data))
			return (NULL);
		usleep(sleep_time);
	}
	return (NULL);
}
