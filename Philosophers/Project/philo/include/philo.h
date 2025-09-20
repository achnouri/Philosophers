/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:55:50 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 17:09:24 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H 
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define I_M_L     101 
# define O_NUM     201
# define O_P_NUM   301
# define N_V_NUM   401
# define MEM_ERR   501
# define MAX_P	   601
# define MAX_A	   701

typedef enum e_time
{
	SEC,
	MIL_SEC,
	MIC_SEC,
}						t_time;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					ph_id;
	long				meals_nb;
	long				last_meal;
	bool				reached_full;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		philo_mutex;
	t_data				*data;
	struct s_philo		*next;
}						t_philo;

struct					s_data
{
	long				nb_philo;
	long				die_time;
	long				eat_time;
	long				sleep_time;
	long				meal_limit;
	pthread_t			monitor_thread;
	bool				monitor;
	bool				ready_to_start;
	long				start_time;
	bool				is_dead;
	pthread_mutex_t		mutex_table;
	pthread_mutex_t		mutex_dead;
	pthread_mutex_t		mutex_log;
	pthread_mutex_t		*forks_mutexes;
	t_philo				*philo;
};

bool					check_n_args(int n);
bool					initialize_data(int ac, char **av, t_data *data);
bool					valid_input(int ac, char **av);
bool					get_flag(pthread_mutex_t *mutex, bool *val);
bool					launch_simulation(t_data *data);
long					get_lval(pthread_mutex_t *mutex, long *val);
long					str_to_long(const char *nptr);
long					get_time(t_time type);
void					simulation(t_data *data);
void					set_flag(pthread_mutex_t *mutex, bool *dst, bool val);
void					set_lval(pthread_mutex_t *mutex, long *dst,
							long val);
void					*p_routine(void *arg);
void					one_philo(t_data *data);
void					*m_routine(void *arg);
void					display_details_msg(int f);
void					display_usage_msg(void);
void					display_status(long start, char *status,
							t_philo *philo, long now);
void					philos_synchronize(t_philo *philo);
void					thinking(t_philo *philo, bool print);
void					my_usleep(t_data *data, long time);
void					clear_all(t_data *data);
void					clear_philos(t_philo *philo);
void					add_philo_back(t_philo **alst, t_philo *new);

#endif 