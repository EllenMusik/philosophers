/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:10:47 by esteiner          #+#    #+#             */
/*   Updated: 2023/12/09 22:02:52 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *philo_arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	data = philo->data;
	
	// while (1)
	// {
	// 	am_i_dead()
	// 	if (trying_to_eat(data, philo))
	// 		break;
	// }
	printf("in the treat\n");
	printf("philo number %d starts sleeping at %ldms\n", philo->philo_id, get_curr_time() - data->start_time);
	ft_isleep(data->time_to_sleep);
	printf("philo number %d stops sleeping at %ldms\n", philo->philo_id, get_curr_time() - data->start_time);
	printf("philo number %d is waiting to eat at %ldms\n", philo->philo_id, get_curr_time() - data->start_time);
	return (NULL);
}

// void	trying_to_eat()
// {
	
// }

// bool	am_i_dead()
// {

// }

