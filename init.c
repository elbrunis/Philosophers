/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:56:26 by biniesta          #+#    #+#             */
/*   Updated: 2025/09/25 18:54:09 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(int argc, char **argv, t_table **table)
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
	return (1);
}

int	init_structs(int argc, char **argv, t_table **table)
{
	int		i;
	t_philo **philos;

	i = 0;
	if (!init_table(argc, argv, table))
		return (0);
	philos = (*table)->philos;
	while(i < (*table)->num_of_philo)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			return (0);
		philos[i]->id = i + 1;
		philos[i]->meals_counter = 0;
		philos[i]->last_meal_time = 0;
		philos[i]->left_fork = NULL;
		philos[i]->right_fork = NULL;
		i++;
	}
	philos[i] = NULL;
	
	return (1);
}