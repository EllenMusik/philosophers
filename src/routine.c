/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:10:47 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/09 18:50:25 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *philo_arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	data = philo->data;
	philo->alive = true;
	philo->has_eaten = false;
	//philo->fork_is_taken = false;
	philo->time_last_meal = get_curr_time();
	// while (1)
	// {
	// 	am_i_dead()
	// 	if (trying_to_eat(data, philo))
	// 		break;
	// }
	printf("in the treat\n");
	while (are_all_alive(data) == true)
	{
		printf("\033[1;32mphilo number %d is waiting to eat ('thinking') at %ldms\033[1;0m\n", philo->philo_id + 1, get_curr_time() - data->philo[philo->philo_id].start_time);
		trying_to_eat(philo, data);
		if (are_all_alive(data) == false)
			return (NULL);
		printf("\033[1;34mphilo number %d starts sleeping at %ldms\033[1;0m\n", philo->philo_id + 1, get_curr_time() - data->philo[philo->philo_id].start_time);
		ft_isleep(data->time_to_sleep);
		if (are_all_alive(data) == false)
			return (NULL);
		//printf("philo number %d stops sleeping at %ldms\n", philo->philo_id + 1, get_curr_time() - data->start_time);
		philo->has_eaten = false;
	}
	return (NULL);
}

bool	are_all_alive(t_data *data)
{
	pthread_mutex_lock(&data->alive_mutex);
	if (data->all_alive == false)
	{
		pthread_mutex_unlock(&data->alive_mutex);
		return (false);
	}
	pthread_mutex_unlock(&data->alive_mutex);
	return (true);
}
// void	*doc_routine(void *data_arg)
// {
// 	t_data	*data;
// 	int		i;

// 	data = (t_data *)data_arg;
// 	i = 0;
// 	while (1)
// 	{
// 		while (i < data->philo_amount)
// 		{
// 			if (vitals_check(data->philo[i]->alive) == false)
// 				data->all_alive = false;
// 			i++;
// 		}
// 		if (data->all_alive == false) // or meal amount is hit for everyone
// 			break ;
// 		ft_isleep(10);
// 	}
// 	return (NULL);
// }

// bool	vitals_check(t_philo *philo)
// {
// 	if ()
// }

void	trying_to_eat(t_philo *philo, t_data *data)
{
	while (philo->has_eaten == false && are_all_alive(data) == true)
	{
		philo->my_fork = grab_my_fork(philo, data);
		philo->next_fork = grab_next_fork(philo, data);
		//printf("philo number %d is trying to eat\n", philo->philo_id + 1);
		if (philo->my_fork && philo->next_fork)
		{
			philo->has_eaten = true;
			//usleep(1);
			if (are_all_alive(data) == false)
				return ;
			printf("\033[1;33mphilo number %d is eating at %ldms\033[1;0m\n", philo->philo_id + 1, get_curr_time() - data->philo[philo->philo_id].start_time);
			philo->time_last_meal = get_curr_time();
			ft_isleep(data->time_to_eat);
			drop_forks(philo, data);
			return ;
		}
		if (are_all_alive(data) == false)
			return ;
		if (philo->my_fork == true)
			drop_my_fork(philo, data);
		if (philo->next_fork == true)
			drop_next_philo_fork(philo, data);
		if (are_all_alive(data) == false)
			return ;
		if (get_curr_time() - philo->time_last_meal >= data->time_to_die)
		{
			pthread_mutex_lock(&data->alive_mutex);
			philo->alive = false;
			data->all_alive = false;
			printf("\033[1;31mphilo number %d starved at %ldms\033[1;0m\n", philo->philo_id + 1, get_curr_time() - data->philo[philo->philo_id].start_time);
			pthread_mutex_unlock(&data->alive_mutex);
			return ;
		}
		//ft_isleep(10);
	}
	return ;
}

bool	grab_my_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->philo_id]);
	if (philo->fork_is_taken == false)
	{
		philo->fork_is_taken = true;
		pthread_mutex_unlock(&data->forks[philo->philo_id]);
		return (true);
	}
	pthread_mutex_unlock(&data->forks[philo->philo_id]);
	return (false);
}

bool	grab_next_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->next_philo_id]);
	if (data->philo[philo->next_philo_id].fork_is_taken == false)
	{
		data->philo[philo->next_philo_id].fork_is_taken = true;
		pthread_mutex_unlock(&data->forks[philo->next_philo_id]);
		return (true);
	}
	pthread_mutex_unlock(&data->forks[philo->next_philo_id]);
	return (false);
}

void	drop_forks(t_philo *philo, t_data *data)
{
	if (are_all_alive(data) == false)
		return ;
	drop_my_fork(philo, data);
	drop_next_philo_fork(philo, data);
	return ;
}

void	drop_my_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->philo_id]);
	if (philo->fork_is_taken == true)
		philo->fork_is_taken = false;
	pthread_mutex_unlock(&data->forks[philo->philo_id]);
	return ;
}

void	drop_next_philo_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->next_philo_id]);
	if (data->philo[philo->next_philo_id].fork_is_taken == true)
		data->philo[philo->next_philo_id].fork_is_taken = false;
	pthread_mutex_unlock(&data->forks[philo->next_philo_id]);
	return ;
}