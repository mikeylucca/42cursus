/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:35:32 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 15:26:00 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static	void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, false);
}

void	*single_philo(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	wait_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, false);
	while (!simulation_done(philo->data))
		usleep(200);
	return (NULL);
}

static	void	eat(t_philo *philo)
{
	mutex_handler(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, false);
	mutex_handler(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, false);

	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	philo->meal_counter++;
	write_status(EATING, philo, false);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->max_meals > 0 && philo->meal_counter == philo->data->max_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	
	mutex_handler(&philo->first_fork->fork, UNLOCK);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_sim(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	wait_threads(philo->data);

	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND)); // set time last meal
	//sync with monitor
	increase_long(&philo->data->data_mutex, &philo->data->threads_running_nbr);

	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));

	//set last meal time
	while (!simulation_done(philo->data))
	{
		if (philo->full)
			break;
		eat(philo);

		//SLEEP
		write_status(SLEEPING, philo, false);
		precise_usleep(philo->data->time_to_sleep, philo->data);

		thinking(philo);
	}


	return (NULL);
}

void	start_simulation(t_data *data)
{
	int i;

	i = -1;
	if (data->max_meals == 0)
		return;
	else if (data->philo_nbr == 1)
		thread_handler(&data->philos[0].thread_id, single_philo, &data->philos[0], CREATE);
	else
	{
		while (data->philo_nbr > ++i)
		{
			thread_handler(&data->philos[i].thread_id, dinner_sim, &data->philos[i], CREATE);
		}
	}
	// Monitor thread
	thread_handler(&data->monitor, monitor_dinner, data, CREATE);
	// START of SIM
	data->start_simulation = gettime(MILLISECOND);
	// All threads made
	set_bool(&data->data_mutex, &data->threads_ready, true);
	
	// WAIT FOR ALL
	i = -1;
	while (++i < data->philo_nbr)
		thread_handler(&data->philos[i].thread_id, NULL, NULL, JOIN);
	// if reach this line, all philos == full
	set_bool(&data->data_mutex, &data->end_simulation, true);
	thread_handler(&data->monitor, NULL, NULL, JOIN);
}
