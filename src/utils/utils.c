/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:56:09 by biniesta          #+#    #+#             */
/*   Updated: 2025/10/24 14:37:56 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	since_start(t_table *table)
{
	return (get_time_ms() - table->start_time);
}

long	get_time_ms(void)
{
	struct timeval	t;
	long			result;

	if (gettimeofday(&t, NULL) != 0)
		return (0);
	result = (t.tv_sec * 1000L) + (t.tv_usec / 1000L);
	return (result);
}

int	ft_error(char *err_msg)
{
	printf("Error: %s\n", err_msg);
	return (EXIT_FAILURE);
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoul(char *str)
{
	int		i;
	int		len;
	long	num;

	if (!str)
		return (0);
	while (*str != '\0' && *str == ' ')
		str++;
	len = 0;
	while (is_num(str[len]))
		len++;
	if (len > 18)
		return (0);
	i = -1;
	num = 0;
	while (is_num(str[++i]))
		num = num * 10 + (str[i] - '0');
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (0);
	return (num);
}
