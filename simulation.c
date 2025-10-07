/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:45:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/07 11:36:34 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulate_action_time(t_table *table, int time_action)
{
	long	limit_time;

	limit_time = get_time_ms() + time_action;	
	while (get_time_ms() < limit_time)
	{
		if (!is_simulation_over) // aqui crear una fucion externa para verificar
			return (1); // debuelve 1 si la simulacion se termino
		usleep(100);//para que no se sobrecaliente la cpu
	}
	return (0);
}

void	lock_execute_unlock(pthread_mutex_t	*mutex, void (*f)(void *), void *arg)
{
	pthread_mutex_lock(mutex);
	f(arg);
	pthread_mutex_unlock(mutex);
}

void	eat_rutine(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_status("cogio tenedor derecho");
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status("cogio tenedor derecho");
	print_status("el filosofo esta comiento");
	simulate_action_time(table, table->time_to_eat);//esta funcion basicamente simula
	table->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
}

void	think_rutine(t_table *table, t_philo *philo)
{
	
}

void	sleep_rutine(t_table *table, t_philo *philo)
{
	print_status("sleep");
	simulate_action_time(table, table->time_to_sleep);
}

void	*rutine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	printf("hola soy el %d\n", philo->id);
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
	long	start_time;

	start_time = get_time_ms();
	printf("put_time: %ld\n", start_time);
	if (!start_time)
		return (0);
	if (!create_theards(table))
		return (0);
	return (1);
}