/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:53 by misoares          #+#    #+#             */
/*   Updated: 2025/08/03 19:35:21 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	thread_error_handler(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit(RED"No resources to create thread"RESET);
	else if (status == EPERM)
		error_exit(RED"Caller does not have permission"RESET);
	else if (status == EINVAL && opcode == CREATE)
		error_exit(RED"Value spec by attr is invalid"RESET);
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit(RED"Value spec by thread isnt joinable"RESET);
	else if (status == ESRCH)
		error_exit(RED"No thread found corresponding to that spec by"
			"thread specified by thread ID."RESET);
	else if (status == EDEADLK)
		error_exit(RED"Deadlock detecter || value of thread spec the calling thread"RESET);
}

void	thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
	{
		thread_error_handler(pthread_create(thread, NULL, foo, data), opcode);
	}
	else if (opcode == JOIN)
		thread_error_handler(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		thread_error_handler(pthread_detach(*thread), opcode);
	else
		error_exit(RED"Wrong opcode for thread_handler"
			"use: <CREATE> <JOIN> <DETACH>"RESET);
}