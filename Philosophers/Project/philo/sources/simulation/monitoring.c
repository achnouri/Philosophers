/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:21:48 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 17:02:25 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	check_if_dead(t_philo *philo)
{
	long	elapsed_t;
	long	die_t;

	if (get_flag(&philo->philo_mutex, &philo->reached_full))
		return (false);
	elapsed_t = get_time(MIL_SEC) - get_lval(&philo->philo_mutex,
			&philo->last_meal);
	die_t = philo->data->die_time;
	if (elapsed_t >= die_t)
		return (true);
	return (false);
}

bool	allphs_ready(t_data *data)
{
	t_philo	*t;

	t = data->philo;
	while (t)
	{
		if (get_lval(&t->philo_mutex, &t->last_meal) == -1)
			return (false);
		t = t->next;
	}
	return (true);
}

bool	allphs_reached_max(t_data *data)
{
	t_philo	*t;

	t = data->philo;
	while (t)
	{
		if (!get_flag(&t->philo_mutex, &t->reached_full))
			return (false);
		t = t->next;
	}
	return (true);
}

void	wait_phs_ready(t_data *data)
{
	while (!allphs_ready(data))
		;
}

void	*m_routine(void *arg)
{
	t_data	*data;
	t_philo	*t;

	data = (void *)arg;
	wait_phs_ready(data);
	while (launch_simulation(data))
	{
		t = data->philo;
		while (t && launch_simulation(data))
		{
			if (check_if_dead(t))
			{
				set_flag(&data->mutex_table, &data->monitor, false);
				set_flag(&data->mutex_dead, &data->is_dead, 1);
				pthread_mutex_lock(&data->mutex_log);
				printf("%ld  %d  %s\n",
					get_time(MIL_SEC) - data->start_time, t->ph_id, "is dead");
				pthread_mutex_unlock(&data->mutex_log);
			}
			if (data->meal_limit != -1 && allphs_reached_max(data))
				set_flag(&data->mutex_table, &data->monitor, false);
			t = t->next;
		}
	}
	return (NULL);
}
