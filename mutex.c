/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:35:16 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/10 08:07:35 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"//incluir este archivo en make y las funciones de dentro en philo.h

static void	write_ouput(pthread_mutex_t	*mutex, long time, int id, char *status)
{
	pthread_mutex_lock(mutex);
	printf("in time: %ld philo %d %s\n", time, id, status);	
	pthread_mutex_unlock(mutex);
}

void	print_status(t_table *table, int id, t_status status)
{
	long	start_time;

	start_time = table->start_time;
	if (status == DIED)
		write_ouput(&table->output_mutex, (get_time_ms() - start_time), id, "died");
	if (status == EATING)
		write_ouput(&table->output_mutex, (get_time_ms() - start_time), id, "is eating");
	if (status == THINKING)
		write_ouput(&table->output_mutex, (get_time_ms() - start_time), id, "is thinking");
	if (status == SLEEPING)
		write_ouput(&table->output_mutex, (get_time_ms() - start_time), id, "is sleeping");
	if (status == FORK_1)
		write_ouput(&table->output_mutex, (get_time_ms() - start_time), id, "has taken fork_1");
	if (status == FORK_2)
		write_ouput(&table->output_mutex, (get_time_ms() - start_time), id, "has taken a fork_2");
	
	if (status == DEBUG)//TEMPORAL
	{
		pthread_mutex_lock(&table->output_mutex);
		printf("hola, estoy aqui\n");	
		pthread_mutex_unlock(&table->output_mutex);
	}
}
