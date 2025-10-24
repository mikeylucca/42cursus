/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:35:32 by misoares          #+#    #+#             */
/*   Updated: 2025/10/24 13:14:54 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *philo, bool pre_sim)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_sim)
		write_status(THINKING, philo, false);
	if (philo->data->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	if (t_think > 0)
		precise_usleep(t_think, philo->data);
}

void	*single_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, false);
	while (!simulation_done(philo->data))
		usleep(SINGLE_PHILO_SLEEP_US);
	return (NULL);
}

static	void	eat(t_philo *philo)
{
	mutex_handler(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, false);
	mutex_handler(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, false);
	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	increase_long(&philo->philo_mutex, &philo->meal_counter);
	write_status(EATING, philo, false);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->max_meals > 0
		&& get_meal_counter(philo) == philo->data->max_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
	mutex_handler(&philo->first_fork->fork, UNLOCK);
}

void	*dinner_sim(void *data)
{
	t_philo	*philo;
	bool	sim_done;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->threads_running_nbr);
	desync_philos(philo);
	sim_done = false;
	while (!sim_done)
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_status(SLEEPING, philo, false);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo, false);
		sim_done = simulation_done(philo->data);
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int		i;
	long	start_time;

	i = -1;
	if (data->max_meals == 0)
		return ;
	else if (data->philo_nbr == 1)
	{
		if (thread_handler(&data->philos[0].thread_id,
				single_philo, &data->philos[0], CREATE) != 0)
			return ;
	}
	else
		while (data->philo_nbr > ++i)
			if (thread_handler(&data->philos[i].thread_id,
					dinner_sim, &data->philos[i], CREATE) != 0)
				return ;
	if (thread_handler(&data->monitor, monitor_dinner, data, CREATE) != 0)
		return ;
	start_time = gettime(MILLISECOND);
	if (start_time == -1)
		return ;
	set_long(&data->data_mutex, &data->start_simulation, start_time);
	set_bool(&data->data_mutex, &data->threads_ready, true);
	i = -1;
	while (++i < data->philo_nbr)
		thread_handler(&data->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&data->data_mutex, &data->end_simulation, true);
	thread_handler(&data->monitor, NULL, NULL, JOIN);
}
