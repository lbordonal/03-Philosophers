/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:18:28 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/23 21:37:29 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	join_threads(t_main *main)
{
	int	i;

	i = 0;
	if (pthread_join(main->checker, NULL))
		printf("%s\n", "Error joinning thread for checker");
	while (i < main->num_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL))
			printf("%s\n", "Error joinning thread for philo");
		i++;
	}
	i = 0;
	while (i < main->num_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		pthread_mutex_destroy(&main->philo[i].reaper);
		i++;
	}
	pthread_mutex_destroy(&main->print);
	pthread_mutex_destroy(&main->mutex);
}
