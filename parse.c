/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:44:28 by biniesta          #+#    #+#             */
/*   Updated: 2025/09/25 18:51:21 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*LO QUE TENGO LISTO*/
// pueden haber espacios
// que no sea negativo
// que no haya letras ni simbolos
// que no haya argumentos vacios
// que no se pase de el INT_MAX= 2.147.483.647 
/*LOS EJEMPLO QUE NO RESISTE MI ATOL 
	- numero demasiado grande*/

int	check_arg(char *arg)
{
	long	num;

	num = ft_atoul(arg);
	if (!num || num > INT_MAX)
		return(0);
	return (1);
}

int	parse_input(int argc, char **argv, t_table **table)
{
 	int	i;

	i = 1;
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