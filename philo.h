/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:49:21 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/20 09:32:05 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

// argv= ./philo "num_of_philo"  "time_to_die"  "time_to_eat" "time_to_sleep"
// "[num_of_times_each_philo_must_eat]
typedef struct s_table	t_table;

typedef enum e_status
{
	DIED,
	EATING,
	THINKING,
	SLEEPING,
	FORK_1,
	FORK_2,
	DEBUG,//TEMPORAL
}			t_status;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct t_philo
{
	int			id;
	long		meals_counter;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_table		*table;
	pthread_t	theard;
}				t_philo;

typedef struct s_table
{
	int				num_of_philo;
	bool			is_finished;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_limit;
	pthread_mutex_t	output_mutex;
	pthread_mutex_t	die_mutex;
	t_fork			*forks;
	t_philo			**philos;
}			t_table;

// parse
int		parse_input(int argc, char **argv, t_table **table);
int		check_arg(char *arg);
// utils
int		ft_error(char *err_msg);
int		is_num(char c);
long	ft_atoul(char *str);
long	get_time_ms(void);
long	since_start(t_table *table);
// init
int		init_structs(int argc, char **argv, t_table **table);
// free
int		free_structs(t_table *table);
// simulation
int		start_simulation(t_table *table);
// mutex
void	print_status(t_table *table, int id, t_status status);
// simulate action
void	is_simulation_alive(t_table *table, t_philo *philo);
bool	is_simulation_over(t_table *table, t_philo *philo);
bool	simulate_action_time(t_table *table, t_philo *philo, int time_action);

#endif
