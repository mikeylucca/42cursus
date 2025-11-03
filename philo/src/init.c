/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:41 by misoares          #+#    #+#             */
/*   Updated: 2025/11/03 15:04:01 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
*EVEN/ODD solution for fork assignment - avoid deadlock
*/
static void	fork_assign(t_philo *philo, t_fork *forks, int pos)
{
	int		philo_nbr;
	t_fork	*temp;

	philo_nbr = philo->data->philo_nbr;
	philo->first_fork = &forks[pos];
	philo->second_fork = &forks[(pos + 1) % philo_nbr];
	if (philo->first_fork->fork_id > philo->second_fork->fork_id)
	{
		temp = philo->first_fork;
		philo->first_fork = philo->second_fork;
		philo->second_fork = temp;
	}
}

static int	init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->philo_nbr)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meal_counter = 0;
		philo->data = data;
		if (mutex_handler(&philo->philo_mutex, INIT) != 0)
			return (-1);
		fork_assign(philo, data->forks, i);
	}
	return (0);
}

int	init_data(t_data *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	data->threads_ready = false;
	data->threads_running_nbr = 0;
	data->philos = s_malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philos)
		return (-1);
	if (mutex_handler(&data->data_mutex, INIT) != 0)
		return (-1);
	if (mutex_handler(&data->write_mutex, INIT) != 0)
		return (-1);
	data->forks = s_malloc(sizeof(t_fork) * data->philo_nbr);
	if (!data->forks)
		return (-1);
	while (++i < data->philo_nbr)
	{
		if (mutex_handler(&data->forks[i].fork, INIT) != 0)
			return (-1);
		data->forks[i].fork_id = i;
	}
	if (init_philo(data) != 0)
		return (-1);
	return (0);
}
