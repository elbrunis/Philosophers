/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:45:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/04 13:25:36 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	get_time_ms(void)
{
	struct timeval	t;
	long			result;

	if (gettimeofday(&t, NULL) != 0)
		return (0);
	result = (t.tv_sec * 1000L) + (t.tv_usec / 1000L);
	return (result);
}
void	*rutine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	while (get_time_ms() < table->start_time)
		usleep(200); //se pone usleep para que no consuma el 100% de la cpu
	printf("hola soy el %ld\n", ( get_time_ms() - table->start_time));
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
	table->start_time = get_time_ms() + 200;
	printf("put_time: %ld\n", table->start_time);
	if (!table->start_time)
		return (0);
	if (!create_theards(table))
		return (0);
	return (1);
}