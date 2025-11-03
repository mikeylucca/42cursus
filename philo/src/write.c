/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:41:27 by misoares          #+#    #+#             */
/*   Updated: 2025/10/30 17:51:50 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_status(t_status status, t_philo *philo)
{
	long	elapsed;
	bool	sim_done;

	elapsed = gettime(MILLISECOND) - get_long(&philo->data->data_mutex,
			&philo->data->start_simulation);
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handler(&philo->data->write_mutex, LOCK);
	sim_done = simulation_done(philo->data);
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !sim_done)
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !sim_done)
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !sim_done)
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !sim_done)
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%-6ld %d died\n", elapsed, philo->id);
	mutex_handler(&philo->data->write_mutex, UNLOCK);
}
