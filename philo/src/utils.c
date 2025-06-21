/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-15 13:52:43 by misoares          #+#    #+#             */
/*   Updated: 2025-06-15 13:52:43 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    error_exit(const char *error)
{
    printf(RED "%s\n" RESET, error);
    exit(EXIT_FAILURE);
}