/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:41:27 by misoares          #+#    #+#             */
/*   Updated: 2025/10/24 14:31:56 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_status(long elapsed, int id, t_status status, bool sim_done)
{
	if (status == DIED)
	{
		printf("%-6ld %d died\n", elapsed, id);
		return ;
	}
	if (sim_done)
		return ;
	if (TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		printf("%-6ld %d has taken a fork\n", elapsed, id);
	else if (status == EATING)
		printf("%-6ld %d is eating\n", elapsed, id);
	else if (status == SLEEPING)
		printf("%-6ld %d is sleeping\n", elapsed, id);
	else if (status == THINKING)
		printf("%-6ld %d is thinking\n", elapsed, id);
}

void	write_status(t_status status, t_philo *philo, bool debug)
{
	long	elapsed;
	bool	sim_done;

	elapsed = gettime(MILLISECOND) - get_long(&philo->data->data_mutex,
			&philo->data->start_simulation);
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handler(&philo->data->write_mutex, LOCK);
	if (debug)
		printf("DEBUG MODE NOT IMPLEMENTED YET");
	else
	{
		sim_done = simulation_done(philo->data);
		print_status(elapsed, philo->id, status, sim_done);
	}
	mutex_handler(&philo->data->write_mutex, UNLOCK);
}
