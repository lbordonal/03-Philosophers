/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:14:33 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/22 14:20:06 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1
		|| philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		print_philo_status(philo, "has taken a fork.");
		pthread_mutex_lock(philo->l_fork);
		print_philo_status(philo, "has taken a fork.");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_philo_status(philo, "has taken a fork.");
		pthread_mutex_lock(philo->r_fork);
		print_philo_status(philo, "has taken a fork.");
	}
	return (0);
}

int	is_eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->main->mutex);
	if (ph->main->dead >= 1 || ph->main->all_ate == ph->main->num_philo)
	{
		pthread_mutex_unlock(&ph->main->mutex);
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
		return (1);
	}
	pthread_mutex_unlock(&ph->main->mutex);
	pthread_mutex_lock(&ph->reaper);
	ph->last_meal = get_time();
	print_philo_status(ph, "is eating.");
	pthread_mutex_lock(&ph->main->mutex);
	ph->num_of_times_ate++;
	if (ph->main->num_of_times_eat != -1)
	{
		if (ph->main->num_of_times_eat == ph->num_of_times_ate)
			ph->main->all_ate++;
	}
	pthread_mutex_unlock(&ph->main->mutex);
	pthread_mutex_unlock(&ph->reaper);
	exec_action(ph->main->tte);
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
	return (0);
}

int	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1
		|| philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	print_philo_status(philo, "is sleeping.");
	exec_action(philo->main->tts);
	return (0);
}

int	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1
		|| philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	print_philo_status(philo, "is thinking.");
	return (0);
}
