/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:27:53 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/23 22:08:11 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

long int	get_time2(void)
{
	struct timeval	ftime;
	long int		time;

	time = 0;
	if (gettimeofday(&ftime, NULL))
		return (-1);
	time = (ftime.tv_sec * 1000) + (ftime.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int miliseconds)
{
	long int	start;

	start = 0;
	start = get_time2();
	while (get_time2() - start < miliseconds)
		usleep(miliseconds / 10);
}
