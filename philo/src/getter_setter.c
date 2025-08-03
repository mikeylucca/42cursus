/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:57:09 by misoares          #+#    #+#             */
/*   Updated: 2025/08/03 18:11:32 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Safe LOCK UNLOCK operations */

//BOOL
void    set_bool(t_mutex *mutex, bool *dest, bool value)
{
	mutex_handler(mutex, LOCK);
	*dest = value;
	mutex_handler(mutex, UNLOCK);
}

bool    get_bool(t_mutex *mutex, bool *value)
{
	bool ret;
	
	mutex_handler(mutex, LOCK);
	ret = *value;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

// Long

void    set_long(t_mutex *mutex, long *dest, long value)
{
	mutex_handler(mutex, LOCK);
	*dest = value;
	mutex_handler(mutex, UNLOCK);
}

long    get_long(t_mutex *mutex, long *value)
{
	long ret;
	
	mutex_handler(mutex, LOCK);
	ret = *value;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

/* REDUNDANT */

bool	simulation_done(t_data *data)
{
	return (get_bool(&data->data_mutex, &data->end_simulation));
}
