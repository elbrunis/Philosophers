/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:30:09 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/29 12:58:53 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	is_simulation_alive(t_table *table, t_philo *philo)
{
	bool	result;
	long	time_since_last_meal;

	result = true;
	time_since_last_meal = since_start(table) - philo->last_meal_time;
	if (time_since_last_meal > table->time_to_die)
	{
		print_status(table, philo->id, DIED);
		result = false;
	}
	if (table->meals_limit > 0 && philo->meals_counter >= table->meals_limit)
		philo->died = 1;
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
