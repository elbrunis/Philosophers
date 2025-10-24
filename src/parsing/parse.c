/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:28 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/24 14:33:47 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_arg(char *arg)
{
	long	num;

	num = ft_atoul(arg);
	if (!num || num > INT_MAX)
		return (0);
	return (1);
}

int	parse_input(int argc, char **argv, t_table **table)
{
	int	i;

	i = 1;
	if (ft_atoul(argv[1]) == 1)
		return (0);
	while (i < argc)
	{
		if (!check_arg(argv[i]))
			return (0);
		i++;
	}
	if (!init_structs(argc, argv, table))
		return (0);
	return (1);
}
