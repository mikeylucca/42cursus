/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:53 by misoares          #+#    #+#             */
/*   Updated: 2025/10/24 13:16:34 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	thread_error_handler(int status, t_opcode opcode)
{
	if (status == 0)
		return (0);
	if (status == EAGAIN)
		return (error_return(RED"No resources to create thread"RESET));
	else if (status == EPERM)
		return (error_return(RED"Caller does not have permission"RESET));
	else if (status == EINVAL && opcode == CREATE)
		return (error_return(RED"Value spec by attr is invalid"RESET));
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		return (error_return(RED"Value spec by thread isnt joinable"RESET));
	else if (status == ESRCH)
		return (error_return(RED"No thread found corresponding to that spec by"
				"thread specified by thread ID."RESET));
	else if (status == EDEADLK)
	{
		error_return(RED"Deadlock detected || "
			"value of thread spec the calling thread"RESET);
		return (status);
	}
	return (status);
}

int	thread_handler(pthread_t *thread, void *(*foo)(void *),
					void *data, t_opcode opcode)
{
	if (opcode == CREATE)
	{
		return (thread_error_handler(pthread_create(thread, NULL, foo, data),
				opcode));
	}
	else if (opcode == JOIN)
		return (thread_error_handler(pthread_join(*thread, NULL), opcode));
	else if (opcode == DETACH)
		return (thread_error_handler(pthread_detach(*thread), opcode));
	else
		return (error_return(RED"Wrong opcode for thread_handler"RESET));
}