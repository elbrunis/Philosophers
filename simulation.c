/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:45:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/20 09:14:13 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// revusar mutex en meals_counter y en time since last meal
void	is_simulation_alive(t_table *table, t_philo *philo)
{
	bool	result;
	long	time_since_last_meal;

	result = true;
	time_since_last_meal = time_since_start(table) - philo->last_meal_time;
	if (time_since_last_meal > table->time_to_die)
	{
		print_status(table, philo->id, DIED);
		result = false;
	}
	if (table->meals_limit > 0 && philo->meals_counter >= table->meals_limit)
		result = false;
	if (result == false)
	{
		pthread_mutex_lock(&table->die_mutex);
		table->is_finished = true;
		pthread_mutex_unlock(&table->die_mutex);
	}
}

bool	is_simulation_over(t_table *table, t_philo *philo)
{
	bool	result;

	result = false;
	is_simulation_alive(table, philo);
	pthread_mutex_lock(&table->die_mutex);
	if (table->is_finished == true)
		result = true;
	pthread_mutex_unlock(&table->die_mutex);
	return (result);
}

bool	simulate_action_time(t_table *table, t_philo *philo, int time_action)
{
	long	limit_time;

	limit_time = get_time_ms() + time_action;
	while (get_time_ms() < limit_time)
	{
		if (is_simulation_over(table, philo))
			return (false);
		usleep(500);
	}
	return (true);
}

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
	philo->last_meal_time = time_since_start(table);
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
