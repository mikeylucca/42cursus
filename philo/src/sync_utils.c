/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:12:46 by misoares          #+#    #+#             */
/*   Updated: 2025/08/03 18:19:32 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    wait_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->threads_ready))
		; // SPINLOCK to sync
	
}