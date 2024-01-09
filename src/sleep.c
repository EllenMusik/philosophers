/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:27:47 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/09 19:12:43 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* waits the "time to wait" in milliseconds */
void	ft_isleep(long time_to_wait)
{
	long	start_time;
	long	waited_time;

	waited_time = 0;
	start_time = get_curr_time();
	while (waited_time < time_to_wait)
	{
		usleep(10);
		waited_time = get_curr_time() - start_time;
	}
	//printf("waited %ld milliseconds. should have waited %ld milliseconds\n", waited_time, time_to_wait);
}

/* returns the current time since 1970 in milliseconds (long) */
long	get_curr_time(void)
{
	struct timeval	time;
	long			seconds;
	long			microseconds;
	long			milliseconds;

	gettimeofday(&time, NULL);
	seconds = time.tv_sec;
	microseconds = time.tv_usec;
	milliseconds = microseconds / 1000 + seconds * 1000;
	return (milliseconds);
}
