/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:47:17 by misoares          #+#    #+#             */
/*   Updated: 2025/11/03 15:03:29 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*s_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		return (NULL);
	return (ret);
}

static int	mutex_error_handler(int status, t_opcode opcode)
{
	if (status == 0)
		return (0);
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
	{
		error_return(RED"The value specified by mutex is invalid."RESET);
		return (status);
	}
	else if (status == EINVAL && opcode == INIT)
		return (error_return(RED"The value specified"
				" by attr is invalid."RESET));
	else if (status == EDEADLK)
		return (error_return(RED"Deadlock would occur if "
				"thread blocked waiting for mutex"RESET));
	else if (status == EPERM)
		return (error_return(RED"Current thread doesnt "
				"hold lock on mutex"RESET));
	else if (status == ENOMEM)
		return (error_return(RED"Process cant alloc memory to "
				"create another mutex"RESET));
	else if (status == EBUSY)
		return (error_return(RED"Mutex locked"RESET));
	return (status);
}

int	mutex_handler(t_mutex *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		return (mutex_error_handler(pthread_mutex_lock(mutex), opcode));
	else if (UNLOCK == opcode)
		return (mutex_error_handler(pthread_mutex_unlock(mutex), opcode));
	else if (INIT == opcode)
		return (mutex_error_handler(pthread_mutex_init(mutex, NULL), opcode));
	else if (DESTROY == opcode)
		return (mutex_error_handler(pthread_mutex_destroy(mutex), opcode));
	else
		return (error_return(RED"Wrong operation code for mutex_handler"RESET));
}
