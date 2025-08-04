/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:12:46 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 20:14:37 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    wait_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->threads_ready))
		usleep(500);
	
}

/* Monitor waits till all threads are running */

bool	all_threads_running(t_mutex *mutex, long *threads, long philo_nbr)
{
	bool ret;

	ret = false;
	mutex_handler(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mutex *mutex, long *value)
{
	mutex_handler(mutex, LOCK);
	(*value)++;
	mutex_handler(mutex, UNLOCK);
}

/* Try to make the system fair to odd number */

void	desync_philos(t_philo *philo)
{
	if (philo->data->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(MIN_TIME, philo->data);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}

/* static	void	eat(t_philo *philo)
{

	mutex_handler(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, false);
	mutex_handler(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, false);
	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	increase_long(&philo->philo_mutex, &philo->meal_counter);
	write_status(EATING, philo, false);
	precise_usleep(philo->data->time_to_eat, philo->data);
	//set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	if (philo->data->max_meals > 0 && get_meal_counter(philo) == philo->data->max_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	
	mutex_handler(&philo->first_fork->fork, UNLOCK);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
} 
	
static void	fork_assign(t_philo *philo, t_fork *forks, int pos)
{
	int philo_nbr;

	philo_nbr = philo->data->philo_nbr;
	
	// Fix the logic - ensure proper odd/even assignment
	if (philo->id % 2 == 0) // Even philosophers
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % philo_nbr];
	}
	else // Odd philosophers - reverse order
	{
		philo->first_fork = &forks[(pos + 1) % philo_nbr];
		philo->second_fork = &forks[pos];
	}
}

*/

