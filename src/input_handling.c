/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:10:49 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/09 18:49:21 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*checks input for anything besides digits and if the number is in the range between 0 and max long*/
bool	check_input(char **argv)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (argv[k])
	{
		while (argv[k][i])
		{
			if (!(argv[k][i] >= '0' && argv[k][i] <= '9'))
				return (printf("Params can only be digits. %i\n", argv[k][i]), false);
			i++;
		}
		if (ft_atol(argv[k]) <= 0)
			return (printf("Params has to between 0 and 100000000\n"), false);
		i = 0;
		k++;
	}
	return (true);
}

void	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_amount + 1);
	while (i < data->philo_amount)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->alive_mutex, NULL);
}

void	start_philo_threads(t_data *data)
{
	int			i;
	//p_threat	doctor;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->philo_amount + 1);
	while (i < data->philo_amount)
	{
		data->philo[i].fork_is_taken = false;
		i++;
	}
	i = 0;
	while (i < data->philo_amount)
	{
		data->philo[i].philo_id = i;
		if (i + 1 == data->philo_amount)
			data->philo[i].next_philo_id = 0;
		else
			data->philo[i].next_philo_id = i + 1;
		data->philo[i].data = data;
		data->philo[i].fork = data->forks[i];
		data->philo[i].start_time = get_curr_time();
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	//pthread_create(&doctor, NULL, &doc_routine, data;
	i = 0;
	while (i < data->philo_amount)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

/*puts the argv arguments into the main data struct*/
void	initalise_arguments(char **argv, t_data	*data)
{
	//data->start_time = get_curr_time();
	data->philo_amount = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->all_alive = true;
	if (argv[5])
		data->meal_amount = ft_atol(argv[5]);
	else
		data->meal_amount = -1;
	//printf("start time!: %ld\n", data->start_time);
}

void	print_data(t_data *data)
{
	printf("%ld, %ld, %ld, %ld, %ld\n", data->philo_amount, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->meal_amount);
}
