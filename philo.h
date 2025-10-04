/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:45 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/03 12:20:16 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_h
# define PHILO_h

#include <stdio.h>       // printf
#include <stdlib.h>      // malloc, free
#include <string.h>      // memset
#include <unistd.h>      // write, usleep
#include <sys/time.h>    // gettimeofday
#include <pthread.h>     // pthread_* functions
#include <limits.h>		 // INT_MAX

// argv= ./philo "num_of_philo"  "time_to_die"  "time_to_eat" "time_to_sleep" "[num_of_times_each_philo_must_eat]

typedef struct s_table t_table;

typedef struct	s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct	t_philo
{
	int			id;
	long		meals_counter;
	long 		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_table		*table;
	pthread_t	theard;
}				t_philo;

typedef struct s_table
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		meals_limit; //optional
	t_fork	*forks;
	t_philo	**philos;
}			t_table;

// parse
int		parse_input(int argc, char **argv, t_table **table);
int		check_arg(char *arg);
// utils
int		ft_error(char *err_msg);
int		is_num(char c);
long	ft_atoul(char *str);
// init
int		init_structs(int argc, char **argv, t_table **table);
// free
int		free_structs(t_table **table);
// simulation
int		start_simulation(t_table *table);




#endif