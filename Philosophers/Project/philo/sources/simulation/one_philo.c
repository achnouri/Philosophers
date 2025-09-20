/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:55:41 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 17:07:01 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	one_philo(t_data *data)
{
	data->start_time = get_time(MIL_SEC);
	display_status(data->start_time, "has taken a fork",
		data->philo, get_time(MIL_SEC));
	my_usleep(data, data->die_time);
	pthread_mutex_lock(&data->mutex_log);
	printf("%ld  %d  %s\n",
		get_time(MIL_SEC) - data->start_time, data->philo->ph_id, "is dead");
	pthread_mutex_unlock(&data->mutex_log);
}
