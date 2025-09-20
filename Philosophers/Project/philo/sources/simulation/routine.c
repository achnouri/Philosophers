/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:19:45 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 17:07:29 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	wait_philosophers(t_data *data)
{
	while (!get_flag(&data->mutex_table, &data->ready_to_start))
		;
}

void	sleeping(t_philo *philo)
{
	display_status(philo->data->start_time,
		"is sleeping", philo, get_time(MIL_SEC));
	my_usleep(philo->data, philo->data->sleep_time);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	display_status(philo->data->start_time,
		"has taken a fork", philo, get_time(MIL_SEC));
	pthread_mutex_lock(philo->right_fork);
	display_status(philo->data->start_time,
		"has taken a fork", philo, get_time(MIL_SEC));
	set_lval(&philo->philo_mutex,
		&philo->last_meal, get_time(MIL_SEC));
	display_status(philo->data->start_time,
		"is eating", philo, get_time(MIL_SEC));
	philo->meals_nb++;
	my_usleep(philo->data, philo->data->eat_time);
	if (philo->data->meal_limit >= 0
		&& philo->meals_nb >= philo->data->meal_limit)
		set_flag(&philo->philo_mutex, &philo->reached_full, true);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	thinking(t_philo *philo, bool p)
{
	long	eat_t;
	long	sleep_t;
	long	think_t;

	think_t = 0;
	if (p)
		display_status(philo->data->start_time,
			"is thinking", philo, get_time(MIL_SEC));
	if (philo->data->nb_philo % 2 == 0)
		return ;
	eat_t = philo->data->eat_time;
	sleep_t = philo->data->sleep_time;
	if (sleep_t > eat_t)
		think_t = 0;
	else if (sleep_t <= eat_t)
		think_t = (eat_t * 2) - sleep_t;
	my_usleep(philo->data, think_t / 2);
}

void	*p_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_philosophers(philo->data);
	set_lval(&philo->philo_mutex,
		&philo->last_meal, get_time(MIL_SEC));
	philos_synchronize(philo);
	while (launch_simulation(philo->data))
	{
		if (philo->reached_full)
			break ;
		eating(philo);
		sleeping(philo);
		thinking(philo, true);
	}
	return (NULL);
}
