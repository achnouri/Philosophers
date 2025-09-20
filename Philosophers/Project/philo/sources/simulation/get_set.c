/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:22:20 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/19 05:20:05 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	get_flag(pthread_mutex_t *mutex, bool *val)
{
	bool	r;

	pthread_mutex_lock(mutex);
	r = *val;
	pthread_mutex_unlock(mutex);
	return (r);
}

void	set_flag(pthread_mutex_t *mutex, bool *dst, bool val)
{
	pthread_mutex_lock(mutex);
	*dst = val;
	pthread_mutex_unlock(mutex);
}

long	get_lval(pthread_mutex_t *mutex, long *val)
{
	long	r;

	pthread_mutex_lock(mutex);
	r = *val;
	pthread_mutex_unlock(mutex);
	return (r);
}

void	set_lval(pthread_mutex_t *mutex, long *dst, long val)
{
	pthread_mutex_lock(mutex);
	*dst = val;
	pthread_mutex_unlock(mutex);
}

bool	launch_simulation(t_data *data)
{
	return (get_flag(&data->mutex_table, &data->monitor));
}
