/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:40 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/20 09:49:22 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc < 5 || argc > 6)
		return (ft_error("invlaid_input"));
	if (!parse_input(argc, argv, &table))
		return (ft_error("invlaid_input"));
	if (!start_simulation(table))
		return (ft_error("simulation_failed"));
	free_structs(table);
	return (0);
}
