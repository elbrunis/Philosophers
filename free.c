/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:39:35 by biniesta          #+#    #+#             */
/*   Updated: 2025/09/25 18:46:15 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_structs(t_table **table)
{
	int	i;

	i = 0;
	if ((*table)->philos)
	{
		while ((*table)->philos[i])
		{
			free((*table)->philos[i]);
			i++;
		}
		free((*table)->philos);
	}
	if (table && *table)
	{
		free(*table);
		*table = NULL;
	}
	return(1);
}