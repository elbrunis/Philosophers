/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:45:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/24 14:27:34 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	eat_rutine(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(table, philo->id, FORK_1);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_status(table, philo->id, FORK_2);
	print_status(table, philo->id, EATING);
	if (!simulate_action_time(table, philo, table->time_to_eat))
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return (false);
	}
	philo->last_meal_time = since_start(table);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return (true);
}

bool	sleep_rutine(t_table *table, t_philo *philo)
{
	print_status(table, philo->id, SLEEPING);
	if (!simulate_action_time(table, philo, table->time_to_sleep))
		return (false);
	return (true);
}

void	*rutine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	while (get_time_ms() < table->start_time)
		usleep(500);
	if (philo->id % 2)
		sleep_rutine(table, philo);
	while (!is_simulation_over(table, philo))
	{
		if (!eat_rutine(table, philo))
			return (NULL);
		if (!sleep_rutine(table, philo))
			return (NULL);
	}
	return (NULL);
}

static int	create_theards(t_table *table)
{
	t_philo	**philo;
	int		i;
	int		j;
		
	i = 0;
	philo = table->philos;
	table->start_time = get_time_ms() + 300;
	while (i < table->num_of_philo)
	{
		if (pthread_create(&philo[i]->theard, NULL, rutine, philo[i]))
			return (0);
		i++;
	}
	j = 0;
	while (j < table->num_of_philo)
	{
		if (pthread_join(philo[j]->theard, NULL))
			return (0);
		j++;
	}
	return (1);
}

int	start_simulation(t_table *table)
{
	if (!create_theards(table))
		return (0);
	return (1);
}
