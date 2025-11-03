/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:13:07 by misoares          #+#    #+#             */
/*   Updated: 2025/11/03 17:28:12 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	simulation_done(t_data *data)
{
	return (get_bool(&data->data_mutex, &data->end_simulation));
}

bool	simulation_done_unsafe(t_data *data)
{
	return (data->end_simulation);
}
