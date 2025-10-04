/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:40 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/01 13:54:14 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// argv= ./philo "num_of_philo"  "time_to_die"  "time_to_eat" "time_to_sleep" "[num_of_times_each_philo_must_eat]

int main(int argc, char **argv)
{
	t_table *table;

	table = NULL;
	if (argc < 5|| argc > 6)
		return(ft_error("invlaid_input"));
	if (!parse_input(argc, argv, &table))
		return(ft_error("invlaid_input"));
	if (!start_simulation(table))
		return(ft_error("simulation_failed"));
	// end_program
	free_structs(&table);
	return (0);
}