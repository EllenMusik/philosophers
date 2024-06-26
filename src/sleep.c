/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:27:47 by esteiner          #+#    #+#             */
/*   Updated: 2024/01/19 17:47:16 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* waits the "time to wait" in milliseconds */
void	ft_isleep(long time_to_wait)
{
	long long	wait_time;

	wait_time = get_curr_time() + time_to_wait;
	while (get_curr_time() <= wait_time)
		usleep(50);
}

/* returns the current time since 1970 in milliseconds (long) */
long long	get_curr_time(void)
{
	struct timeval	time;
	long long		seconds;
	long long		microseconds;
	long long		milliseconds;

	gettimeofday(&time, NULL);
	seconds = time.tv_sec;
	microseconds = time.tv_usec;
	milliseconds = (microseconds / 1000) + (seconds * 1000);
	return (milliseconds);
}
