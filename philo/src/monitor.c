/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:42:59 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 15:31:57 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);

	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_mealtime);
	t_to_die = philo->data->time_to_die / 1e3;

	if (elapsed > t_to_die)
		return (true);
	else
		return (false);
}

void	*monitor_dinner(void *data)
{
	int i;
	t_data *pData;

	pData = (t_data *)data;
	
	// check all philos running -- spinlock till all threads run
	while (!all_threads_running(&pData->data_mutex, &pData->threads_running_nbr, pData->philo_nbr))
		;
	while (!simulation_done(pData))
	{
		i = -1;
		while (++i < pData->philo_nbr && !simulation_done(pData))
		{
			if (philo_died(pData->philos + i))
			{
				set_bool(&pData->data_mutex, &pData->end_simulation, true);
				write_status(DIED, pData->philos + i, false);
			}
		}
	}
	return (NULL);
}