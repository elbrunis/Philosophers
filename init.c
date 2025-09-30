/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:56:26 by biniesta          #+#    #+#             */
/*   Updated: 2025/09/30 09:41:44 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*init_forks(int num_of_forks)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * num_of_forks);
	if(!forks)
		return (NULL);
	i = 0;
	while(i < num_of_forks)
	{
		forks[i].id = i;
		if(pthread_mutex_init(&forks[i].mutex, NULL) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

static int	init_table(int argc, char **argv, t_table **table)
{
	*table = (t_table *)malloc(sizeof(t_table));
	if(!*table)
		return (0);
	(*table)->num_of_philo = ft_atoul(argv[1]);
	(*table)->time_to_die = ft_atoul(argv[2]);
	(*table)->time_to_eat = ft_atoul(argv[3]);
	(*table)->time_to_sleep = ft_atoul(argv[4]);
	if (argc == 6)
		(*table)->meals_limit = ft_atoul(argv[5]);
	else
		(*table)->meals_limit = -1;
	(*table)->philos = (t_philo**)malloc(sizeof(t_philo*) * ((*table)->num_of_philo + 1));
	if (!(*table)->philos)
		return (0);
	(*table)->forks = init_forks((*table)->num_of_philo);
	if (!(*table)->forks)
		return (0);
	return (1);
}

static int	init_philos(int num_of_philo, t_philo **philos, t_fork *forks)
{
	int	i;

	i = 0;
	while(i < num_of_philo)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			return (0);
		philos[i]->id = i + 1;
		philos[i]->meals_counter = 0;
		philos[i]->last_meal_time = 0;
		philos[i]->left_fork = &forks[i];
		philos[i]->right_fork = &forks[(i + 1) % num_of_philo];
		i++;
	}
	philos[i] = NULL;
	return (1);
}

int	init_structs(int argc, char **argv, t_table **table)
{
	if (!init_table(argc, argv, table))
		return (0);
	if (!init_philos((*table)->num_of_philo, (*table)->philos, (*table)->forks))
		return (0);
	return (1);
}