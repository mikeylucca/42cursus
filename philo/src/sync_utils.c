/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:12:46 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 14:54:23 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    wait_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->threads_ready))
		; // SPINLOCK to sync
	
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