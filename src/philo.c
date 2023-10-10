/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/10/07 12:34:50 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pthread.h>
#include "../philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	*philosopher(void *mutex)
{
	printf("thread start\n");
	if (mutex == NULL)
		printf("mist\n");
	pthread_mutex_lock(mutex);
	printf("test1\n");
	//usleep(500000);
	printf("test2\n");
	pthread_mutex_unlock(mutex);
	printf("coolcoolcool1\n");
	printf("coolcool2\n");
	printf("cool3\n");
	printf("4\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_t		test[4];
	pthread_mutex_t	mutex;
	struct timeval	time_test;
	long 			seconds;
	int 			milliseconds;

	i = 0;
	gettimeofday(&time_test, NULL);
	printf("time since 1979 %li \n and milliseconds %i\n", time_test.tv_sec, time_test.tv_usec);
	seconds = time_test.tv_sec;
	milliseconds = time_test.tv_usec;
	pthread_mutex_init(&mutex, NULL);
	if (argc != 1)
		return (ft_putstr_fd("test1\n", 2), 1);
	if (!argv)
		return (ft_putstr_fd("test2\n", 2), 1);
	while (i < 4)
	{
		if (pthread_create(&test[i], NULL, &philosopher, &mutex) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(test[i], NULL) != 0)
			return (1);
		i++;
	}
	gettimeofday(&time_test, NULL);
	printf("time since start %li \n and milliseconds %i\n", time_test.tv_sec - seconds, time_test.tv_usec - milliseconds);
	usleep(200);
	gettimeofday(&time_test, NULL);
	printf("time since start %li \n and milliseconds %i\n", time_test.tv_sec - seconds, time_test.tv_usec - milliseconds);
	usleep(200000);
	gettimeofday(&time_test, NULL);
	printf("time since start %li \n and milliseconds %i\n", time_test.tv_sec - seconds, time_test.tv_usec - milliseconds);
	pthread_mutex_destroy(&mutex);
	return (0);
}

/*
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
 */