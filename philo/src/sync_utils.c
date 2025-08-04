/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:12:46 by misoares          #+#    #+#             */
/*   Updated: 2025/08/04 20:51:34 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    wait_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->threads_ready))
		usleep(500);
	
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

/* Try to make the system fair to odd number */

void	desync_philos(t_philo *philo)
{
	if (philo->data->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(MIN_TIME, philo->data);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}

/* static	void	eat(t_philo *philo)
{

	mutex_handler(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, false);
	mutex_handler(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, false);
	set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	increase_long(&philo->philo_mutex, &philo->meal_counter);
	write_status(EATING, philo, false);
	precise_usleep(philo->data->time_to_eat, philo->data);
	//set_long(&philo->philo_mutex, &philo->last_mealtime, gettime(MILLISECOND));
	if (philo->data->max_meals > 0 && get_meal_counter(philo) == philo->data->max_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	
	mutex_handler(&philo->first_fork->fork, UNLOCK);
	mutex_handler(&philo->second_fork->fork, UNLOCK);
} 
	
static void	fork_assign(t_philo *philo, t_fork *forks, int pos)
{
	int philo_nbr;

	philo_nbr = philo->data->philo_nbr;
	
	// Fix the logic - ensure proper odd/even assignment
	if (philo->id % 2 == 0) // Even philosophers
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % philo_nbr];
	}
	else // Odd philosophers - reverse order
	{
		philo->first_fork = &forks[(pos + 1) % philo_nbr];
		philo->second_fork = &forks[pos];
	}
}

*/

/* Summary of Fixes Applied:
The 42cursus philosophers implementation now runs properly with helgrind thanks to these key fixes:

1. Fixed precise_usleep() Function
Problem: Called simulation_done() in every iteration of tight loops, causing excessive mutex operations
Fix: Reduced frequency of simulation_done() checks and added a modulo condition to check only occasionally
2. Optimized Monitor Thread
Problem: Called simulation_done() multiple times in nested loops
Fix: Check simulation_done() once per outer loop iteration and store result in local variable
3. Improved Simulation Loop
Problem: Called simulation_done() at the start of every while loop iteration
Fix: Check once per complete eat-sleep-think cycle instead of at every loop entry
4. Optimized Write Status Function
Problem: Called simulation_done() multiple times for different status conditions
Fix: Call once and reuse the boolean result for all conditions
5. Added Strategic Sleep Calls
Problem: Some busy waiting loops were too aggressive
Fix: Added usleep(100) in monitor initialization to reduce CPU spinning
Key Principles Applied:
Minimize Mutex Operations: Reduced the frequency of getter/setter function calls that acquire/release mutexes
Cache Boolean Results: Store results of expensive mutex-protected checks and reuse them
Strategic Timing: Added small delays in busy-wait loops to reduce contention
Preserve Logic: All fixes maintain the original program logic and correctness
The program now runs with 0 race conditions detected by helgrind while maintaining full functionality for philosopher simulation, death detection, and meal counting. */