/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:57:27 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/09 15:26:11 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* 1. arg: Number of philos,
 * 2. arg: time philos have until they die,
 * 3. arg: time they need to eat,
 * 4. arg: time they need to sleep,
 * 5. arg: (optional) how many meals each eats until simulation stops; */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (printf("wrong argument amount\n"), 1);
	if (!check_input(argv))
		return (1);
	data = malloc(sizeof(t_data));
	initalise_arguments(argv, data);
	print_data(data);
	//test_wait(data);
	create_forks(data);
	start_philo_threads(data);
	free_at_end(data);
	return (0);
}

void	test_wait(t_data *data)
{
	long	start;

	start = get_curr_time();
	ft_isleep(data->time_to_die);
	printf("time passed: %ld\n", get_curr_time() - start);
}

void	free_at_end(t_data *data)
{
	int	i;

	i = 0;
	printf("test\n");
	while (i < data->philo_amount)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			printf("mutex destroy error\n");
		i++;
	}
	pthread_mutex_destroy(&data->alive_mutex);
	free (data);
}
