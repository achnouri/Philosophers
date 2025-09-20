/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:09:40 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 17:02:11 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	display_status(long start, char *status, t_philo *philo, long now)
{
	long	time;

	if (philo->reached_full)
		return ;
	time = now - start;
	pthread_mutex_lock(&philo->data->mutex_log);
	if (launch_simulation(philo->data))
		printf("%ld  %d  %s\n", time, philo->ph_id, status);
	pthread_mutex_unlock(&philo->data->mutex_log);
}

void	simulation(t_data *data)
{
	t_philo	*t;

	if (!data->meal_limit)
		return ;
	if (data->nb_philo == 1)
		return (one_philo(data));
	t = data->philo;
	while (t)
	{
		pthread_create(&t->thread, NULL, &p_routine, t);
		t = t->next;
	}
	pthread_create(&data->monitor_thread, NULL, &m_routine, data);
	data->start_time = get_time(MIL_SEC);
	set_flag(&data->mutex_table, &data->ready_to_start, true);
	t = data->philo;
	while (t)
	{
		pthread_join(t->thread, NULL);
		t = t->next;
	}
	set_flag(&data->mutex_table, &data->monitor, false);
	pthread_join(data->monitor_thread, NULL);
}
