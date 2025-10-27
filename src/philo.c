/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:40 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/27 19:23:53 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	int		test;

	table = NULL;
	if (argc < 5 || argc > 6)
		return (ft_error("invlaid_input"));
	test = parse_input(argc, argv, &table);
	if (test == 0)
		return (ft_error("invlaid_input"));
	else if (test == 2)
	{
		printf("in time: 0 philo 1 is died\n");
		return (0);
	}
	if (!start_simulation(table))
		return (ft_error("simulation_failed"));
	free_structs(table);
	return (0);
}
