/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:45:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/07 13:35:55 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
void	think_rutine(t_table *table, t_philo *philo)
{
	
}

void	lock_execute_unlock(pthread_mutex_t	*mutex, void (*f)(void *), void *arg)
{
	pthread_mutex_lock(mutex);
	f(arg);
	pthread_mutex_unlock(mutex);
}
*/

bool	is_simulation_over(t_table *table)
{
	bool	result;

	retult = false;
	pthread_mutex_lock(&table->die_mutex);
	if (is_finished == true)
		result = true;
	pthread_mutex_unlock(&table->die_mutex);
	return (result);
}

bool	simulate_action_time(t_table *table, int time_action)
{
	long	limit_time;

	limit_time = get_time_ms() + time_action;	
	while (get_time_ms() < limit_time)
	{
		if (is_simulation_over(table))
			return (false);
		usleep(100);
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
	if(!simulate_action_time(table, table->time_to_eat))
		return (false);
	table->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return (true);
}

bool	sleep_rutine(t_table *table, t_philo *philo)
{
	print_status(table, philo->id, SLEEPING);
	if(!simulate_action_time(table, table->time_to_sleep))
		return (false);
	return (true);
}

void	*rutine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	table->start_time = get_time_ms() + 200;
	while (get_time_ms() < table->start_time)
		usleep(100);
	if (philo->id % 2)
		sleep_rutine(table, philo);
	while (is_simulation_over(table)) // aqui crear una fucion externa para verificar
	{
		eat_rutine(table, philo);
		sleep_rutine(table, philo);
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
	while (i < table->num_of_philo)
	{
		if (pthread_create(&philo[i]->theard, NULL, rutine, philo[i])) // se puede hacer tambien asi &table->philo[i]->theard
			return(0);
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
	if (!start_time)
		return (0);
	if (!create_theards(table))
		return (0);
	return (1);
}   