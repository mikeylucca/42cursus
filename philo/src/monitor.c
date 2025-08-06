/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:42:59 by misoares          #+#    #+#             */
/*   Updated: 2025/08/06 22:26:07 by misoares         ###   ########.fr       */
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

static bool	check_all_philos(t_data *pData)
{
	int	i;

	i = -1;
	while (++i < pData->philo_nbr)
	{
		if (philo_died(pData->philos + i))
		{
			set_bool(&pData->data_mutex, &pData->end_simulation, true);
			write_status(DIED, pData->philos + i, false);
			return (true);
		}
	}
	return (false);
}

void	*monitor_dinner(void *data)
{
	t_data	*pData;
	long	sleep_time;

	pData = (t_data *)data;
	while (!all_threads_running(&pData->data_mutex, &pData->threads_running_nbr, pData->philo_nbr))
		usleep(500);
	usleep(5000);
	sleep_time = pData->time_to_die / 10;
	if (sleep_time < 100)
		sleep_time = 100;
	if (sleep_time > 1000)
		sleep_time = 1000;
	while (true)
	{
		if (simulation_done(pData))
			break ;
		if (check_all_philos(pData))
			return (NULL);
		usleep(sleep_time);
	}
	return (NULL);
}
