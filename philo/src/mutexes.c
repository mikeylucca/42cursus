/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:47:17 by misoares          #+#    #+#             */
/*   Updated: 2025/08/03 22:05:40 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*s_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit(RED"Malloc failed"RESET);
	return (ret);
}

static void	mutex_error_handler(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		error_exit(RED"The value specified by mutex is invalid."RESET);
	else if (status == EINVAL && opcode == INIT)
		error_exit(RED"The value specified by attr is invalid."RESET);
	else if (status == EDEADLK)
		error_exit(RED"Deadlock would occur if thread blocked waiting for mutex"RESET);
	else if (status == EPERM)
		error_exit(RED"Current thread doesnt hold lock on mutex"RESET);
	else if (status == ENOMEM)
		error_exit(RED"Process cant alloc enough memory to create another mutex"RESET);
	else if (status == EBUSY)
		error_exit(RED"Mutex locked"RESET);
}

void	mutex_handler(t_mutex *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		mutex_error_handler(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		mutex_error_handler(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		mutex_error_handler(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		mutex_error_handler(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit(RED"Wrong operation code for mutex_handler"RESET);
}
