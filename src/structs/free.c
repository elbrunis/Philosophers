/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:39:35 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/24 13:18:07 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	free_forks(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->num_of_philo)
		{
			pthread_mutex_destroy(&table->forks[i].mutex);
			i++;
		}
		free(table->forks);
	}
}

static void	free_philos(t_table *table)
{
	int	i;

	if (table->philos)
	{
		i = 0;
		while (i < table->num_of_philo)
		{
			free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
}

int	free_structs(t_table *table)
{
	pthread_mutex_destroy(&table->output_mutex);
	pthread_mutex_destroy(&table->die_mutex);
	free_forks(table);
	free_philos(table);
	if (table)
		free(table);
	return (1);
}
