/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:35:16 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/20 09:39:18 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_ouput(pthread_mutex_t	*mutex, long time, int id, char *status)
{
	pthread_mutex_lock(mutex);
	printf("in time: %ld philo %d %s\n", time, id, status);
	pthread_mutex_unlock(mutex);
}

void	print_status(t_table *table, int id, t_status status)
{
	pthread_mutex_t	*mutex;

	mutex = &table->output_mutex;
	if (status == DIED)
		write_ouput(mutex, since_start(table), id, "died");
	if (status == EATING)
		write_ouput(mutex, since_start(table), id, "is eating");
	if (status == THINKING)
		write_ouput(mutex, since_start(table), id, "is thinking");
	if (status == SLEEPING)
		write_ouput(mutex, since_start(table), id, "is sleeping");
	if (status == FORK_1)
		write_ouput(mutex, since_start(table), id, "has taken fork_1");
	if (status == FORK_2)
		write_ouput(mutex, since_start(table), id, "has taken a fork_2");
	if (status == DEBUG)
	{
		pthread_mutex_lock(&table->output_mutex);
		printf("hola, estoy aqui\n");
		pthread_mutex_unlock(&table->output_mutex);
	}
}
