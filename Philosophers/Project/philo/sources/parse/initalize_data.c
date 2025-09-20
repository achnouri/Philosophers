/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:09:02 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/19 19:54:39 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	assign_forks(t_data *data, t_philo *t, int i)
{
	t->left_fork = &data->forks_mutexes[(i + 1) % data->nb_philo];
	t->right_fork = &data->forks_mutexes[i];
	if (t->ph_id % 2 == 0)
	{
		t->left_fork = &data->forks_mutexes[i];
		t->right_fork = &data->forks_mutexes[(i + 1) % data->nb_philo];
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks_mutexes[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex_table, NULL);
	pthread_mutex_init(&data->mutex_dead, NULL);
	pthread_mutex_init(&data->mutex_log, NULL);
}

bool	init_philo(t_data *data)
{
	int		i;
	t_philo	*t;

	i = 0;
	data->is_dead = 0;
	while (i < data->nb_philo)
	{
		t = malloc(sizeof(t_philo));
		if (!t)
			return (false);
		t->ph_id = i + 1;
		t->meals_nb = 0;
		t->last_meal = -1;
		assign_forks(data, t, i);
		add_philo_back(&data->philo, t);
		t->next = NULL;
		t->data = data;
		t->reached_full = false;
		pthread_mutex_init(&t->philo_mutex, NULL);
		i++;
	}
	return (true);
}

bool	initialize_data(int ac, char **av, t_data *data)
{
	if (ac == 6)
		data->meal_limit = str_to_long(av[5]);
	else
		data->meal_limit = -1;
	data->nb_philo = str_to_long(av[1]);
	data->die_time = str_to_long(av[2]);
	data->eat_time = str_to_long(av[3]);
	data->sleep_time = str_to_long(av[4]);
	data->philo = NULL;
	data->monitor = true;
	data->ready_to_start = false;
	data->forks_mutexes = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks_mutexes)
		return (display_details_msg(MEM_ERR), false);
	if (!init_philo(data))
	{
		free(data->forks_mutexes);
		clear_philos(data->philo);
		return (display_details_msg(MEM_ERR), false);
	}
	init_mutex(data);
	return (true);
}
