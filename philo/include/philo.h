/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misoares <misoares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:54:15 by misoares          #+#    #+#             */
/*   Updated: 2025/08/06 21:35:29 by misoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <threads.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include "../libraries/libft/libft.h"

#define OFFSET 48
#define MAX_PHILOS 200
#define MIN_TIME 6e4
#define THINKING_PERCENTAGE 0.42
#define SINGLE_PHILO_SLEEP_US 200
#define CONVERSION_RATE_TO_MS 1000
#define MONITOR_DELAY 1000


/*
*USAGE:
* printf(GREEN "Philosopher %d is eating" RESET "\n", philo_id);
! printf(RED BOLD "Philosopher %d died" RESET "\n")
*/

// ANSI Color Codes
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define DIM			"\033[2m"
#define UNDERLINE	"\033[4m"

// Text Colors
#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"

// Bright Colors
#define BRIGHT_BLACK	"\033[90m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_YELLOW	"\033[93m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"
#define BRIGHT_WHITE	"\033[97m"

// Background Colors
#define BG_BLACK	"\033[40m"
#define BG_RED		"\033[41m"
#define BG_GREEN	"\033[42m"
#define BG_YELLOW	"\033[43m"
#define BG_BLUE		"\033[44m"
#define BG_MAGENTA	"\033[45m"
#define BG_CYAN		"\033[46m"
#define BG_WHITE	"\033[47m"


typedef enum e_opcode
{
	LOCK,	//0
	UNLOCK,	//1
	INIT,	//2
	DESTROY,//3
	CREATE,	//4
	JOIN,	//5
	DETACH,	//6
}			t_opcode;

/* PPHILO STATES */
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}			t_status;

typedef enum e_timecode
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_timecode;

typedef pthread_mutex_t t_mutex;

// for compiling
typedef	struct s_data t_data;

// FORK INFO
typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}	t_fork;

// PHILO STRUCT
typedef struct s_philo
{
	int		id;
	long	meal_counter;
	bool	full;
	long	last_mealtime; // time from last meal in microseconds
	t_fork 	*first_fork;
	t_fork	*second_fork;
	pthread_t thread_id; // philo == thread
	t_mutex	philo_mutex; // for races with monitor
	t_data	*data;
}  t_philo;


/*
	Struct with all the data present
	./philo 5 800 200 200 [5]
*/
struct s_data
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals; // [5] || flag if -1
	long	start_simulation;
	bool	end_simulation; // triggers when philo full or dies
	t_mutex	data_mutex; // avoid race while reading from data
	t_mutex	write_mutex;
	t_fork	*forks; // all forks
	t_philo *philos; // all philosofers
	bool	threads_ready; // sync philos
	pthread_t monitor;
	long	threads_running_nbr;
};

//ERROR
int		error_return(const char *error);

//PARSER
int		input_parse(t_data *data, char **av);

//SAFE FUNCTIONS - Embedded checks
void	*s_malloc(size_t bytes);
int		thread_handler(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);
int		mutex_handler(t_mutex *mutex, t_opcode opcode);

// INIT
//INIT
int		init_data(t_data *data);

//SIMULATION
void	start_simulation(t_data *data);
void	*monitor_dinner(void *data);
void	thinking(t_philo *philo, bool pre_sim);

// SETTERS & GETTERS
void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
void	set_long(t_mutex *mutex, long *dest, long value);
long	get_long(t_mutex *mutex, long *value);
bool	simulation_done(t_data *data);
bool	simulation_done_unsafe(t_data *data);
long	get_meal_counter(t_philo *philo);

// SYNC Utils
void	wait_threads(t_data *data);
void	increase_long(t_mutex *mutex, long *value);
bool	all_threads_running(t_mutex *mutex, long *threads, long philo_nbr);
void	desync_philos(t_philo *philo);

//Normal UTILS
long	gettime(t_timecode timecode);
void	precise_usleep(long usec, t_data *data);
void	write_status(t_status status, t_philo *philo, bool debug);
void	cleaner(t_data *data);


#endif