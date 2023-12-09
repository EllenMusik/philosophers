/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/12/07 16:00:49 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	usleep(500000);
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
 		if (pthread_create(&test[i], NULL, &philosopher, any arg) != 0)
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
­// so we could communicate like this hihi. Uhh so it's just my brother telling me that I look bad D: 
// idk he cares that I look older now or something or my wrinkles under my eyes are bad >_> yeah tf
// wtf that bitch you look a,azying perfect xddd no thank you TT_TT :3 did u video call him?
// ye >_> bitch true
// also his beard looks bad xd did u tell him that ye of course good job
// ok back to work then !! o-o dont belive him ok? ok TT_TT All tho I guess under eye wrinkles are normal
// and aging is normal TT_TT YES !!!! I guess maybe definetely. . .
// I think people say a few years younger but I guess my brother cares that I used to look younger than
// that xdd But that is normal??? yes, time is moving bro idk if you noticed
// I'll tell him next time xd 
/*
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
 */