/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:11:18 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 17:08:39 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long	get_time(t_time type)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (type == SEC)
		return (now.tv_sec);
	else if (type == MIL_SEC)
		return (now.tv_sec * 1000 + now.tv_usec / 1000);
	else if (type == MIC_SEC)
		return (now.tv_sec * 1000000 + now.tv_usec);
	return (0);
}

void	philos_synchronize(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		if (philo->ph_id % 2 == 0)
			my_usleep(philo->data, 30);
	}
	else
	{
		if (philo->ph_id % 2)
			thinking(philo, false);
	}
}

void	my_usleep(t_data *data, long time)
{
	long	now;

	now = get_time(MIL_SEC);
	while (get_time(MIL_SEC) - now < time
		&& !get_flag(&data->mutex_dead, &data->is_dead))
	{
		usleep(100);
	}
}
