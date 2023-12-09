/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:27:47 by esteiner          #+#    #+#             */
/*   Updated: 2023/12/09 21:07:38 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_isleep(long time_to_wait)
{
	long	start_time;
	long	waited_time;

	waited_time = 0;
	start_time = get_curr_time();
	while (waited_time < time_to_wait)
	{
		usleep(500);
		waited_time = get_curr_time() - start_time;
		//printf("waited: %ld\n", waited_time);
	}
	printf("waited %ld milliseconds. should have waited %ld milliseconds\n", waited_time, time_to_wait);
}

long	get_curr_time(void)
{
	struct timeval	time;
	long			seconds;
	long			microseconds;
	long			milliseconds;

	gettimeofday(&time, NULL);
	seconds = time.tv_sec;
	microseconds = time.tv_usec;
	//printf("seconds: %ld, micro: %ld\n", seconds, microseconds);
	milliseconds = microseconds / 1000 + seconds * 1000;
	//printf("milliseconds time: %ld\n", milliseconds);
	return (milliseconds);
}
