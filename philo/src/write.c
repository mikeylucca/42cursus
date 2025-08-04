/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:41:27 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 15:42:35 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_status(t_status status, t_philo *philo, bool debug)
{
	long elapsed;

	elapsed = gettime(MILLISECOND) - philo->data->start_simulation;
	if (philo->full)
		return;
	mutex_handler(&philo->data->write_mutex, LOCK);
	if (debug)
		printf(CYAN"DEBUG MODE NOT IMPLEMENTED YET"RESET);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simulation_done(philo->data))
			printf(CYAN"%-6ld Philosopher %d has taken a fork\n"RESET, elapsed, philo->id);
		else if (status == EATING && !simulation_done(philo->data))
			printf(GREEN"%-6ld Philosopher %d is eating\n"RESET, elapsed, philo->id);
		else if (status == SLEEPING && !simulation_done(philo->data))
			printf(MAGENTA"%-6ld Philosopher %d is sleeping\n"RESET, elapsed, philo->id);
		else if (status == THINKING && !simulation_done(philo->data))
			printf(WHITE"%-6ld Philosopher %d is thinking\n"RESET, elapsed, philo->id);
		else if (status == DIED)
			printf(RED"%-6ld Philosopher %d died\n"RESET, elapsed, philo->id);
	}
	mutex_handler(&philo->data->write_mutex, UNLOCK);
}
