/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:41 by misoares          #+#    #+#             */
/*   Updated: 2025/08/03 19:47:45 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
*EVEN/ODD solution for fork assignment - avoid deadlock
*/
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

static void	init_philo(t_data *data)
{
	int i;
	t_philo *philo;

	i = -1;
	while (++i < data->philo_nbr)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meal_counter = 0;
		philo->data = data;
		mutex_handler(&philo->philo_mutex, INIT);

		fork_assign(philo, data->forks, i);
	}
	
}

void    init_data(t_data *data)
{
	int i;

	i = -1;
    data->end_simulation = false;
	data->threads_ready = false;
    data->philos = s_malloc(sizeof(t_philo) * data->philo_nbr);
	mutex_handler(&data->data_mutex, INIT);
	mutex_handler(&data->write_mutex, INIT);
	data->forks = s_malloc(sizeof(t_fork) * data->philo_nbr);
	while (++i < data->philo_nbr)
	{
		mutex_handler(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
	init_philo(data);
}
