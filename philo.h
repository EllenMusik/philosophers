/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/12/09 17:39:45 by esteiner         ###   ########.fr       */
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
	long				start_time;
	long				philo_amount;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meal_amount;
	pthread_mutex_t		*forks;
	struct s_philo		*philo;
}				t_data;

typedef struct s_philo
{
	int					philo_id;
	int					next_philo_id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	bool				has_eaten;
	long				time_since_meal;
	t_data				*data;
}				t_philo;

int		main(int argc, char **argv);
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


#endif