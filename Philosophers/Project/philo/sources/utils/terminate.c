/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:11:15 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/18 00:25:08 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	clear_philos(t_philo *philo)
{
	t_philo	*t;

	while (philo)
	{
		pthread_mutex_destroy(&philo->philo_mutex);
		t = philo->next;
		free(philo);
		philo = t;
	}
}

void	clear_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks_mutexes[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_table);
	pthread_mutex_destroy(&data->mutex_log);
	free(data->forks_mutexes);
	clear_philos(data->philo);
}
