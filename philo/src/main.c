/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:46 by misoares          #+#    #+#             */
/*   Updated: 2025/08/06 21:35:29 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac == 5 || ac == 6)
	{
		//* check errors and fills the data table.
		if (input_parse(&data, av) != 0)
			return (1);
		//*creates everything
		if (init_data(&data) != 0)
		{
			cleaner(&data);
			return (1);
		}
		//*starts simulation
		start_simulation(&data);
		//*stops simulation when philos are full or 1 philo dies
		cleaner(&data);
	}
	else
	{
		error_return("Incorrect Input.\n"
		GREEN BOLD"Correct usage is: ./philo 5 800 200 200 [5]\n"RESET);
		return (1);
	}
	return 0;
}
