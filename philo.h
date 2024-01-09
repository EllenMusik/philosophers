/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/09 18:46:00 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>

struct	s_philo;

typedef struct s_data
{
	long				philo_amount;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meal_amount;
	pthread_mutex_t		*forks;
	struct s_philo		*philo;
	pthread_mutex_t		alive_mutex;
	bool				all_alive;
}				t_data;

typedef struct s_philo
{
	long				start_time;
	int					philo_id;
	int					next_philo_id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	bool				fork_is_taken;
	bool				my_fork;
	bool				next_fork;
	bool				has_eaten;
	long				time_last_meal;
	t_data				*data;
	bool				alive;
}				t_philo;

void	free_at_end(t_data	*data);

bool	check_input(char **argv);
void	initalise_arguments(char **argv, t_data	*data);

long	ft_atol(const char *str);
long	number_convert(int x, long nbr, const char *str);

void	print_data(t_data *data);
void	test_wait(t_data *data);

void	ft_isleep(long time_to_wait);
long	get_curr_time(void);

void	*routine(void *philo_arg);
void	create_forks(t_data *data);
void	start_philo_threads(t_data *data);
void	trying_to_eat(t_philo *philo, t_data *data);

bool	grab_my_fork(t_philo *philo, t_data *data);
bool	grab_next_fork(t_philo *philo, t_data *data);
void	drop_forks(t_philo *philo, t_data *data);
void	drop_my_fork(t_philo *philo, t_data *data);
void	drop_next_philo_fork(t_philo *philo, t_data *data);

bool	are_all_alive(t_data *data);

#endif