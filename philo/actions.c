/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:50:53 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/02 15:50:53 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eating(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (0);
	if (print_philo(main, main->philo[i].id, B_BLUE, "has taken a fork") == 0)
		return (0);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (0);
	if (print_philo(main, main->philo[i].id, B_BLUE, "has taken a fork") == 0)
		return (0);
	if (print_philo(main, main->philo[i].id, G_CYAN, "is eating") == 0)
		return (0);
	main->philo[i].time_to_die = get_time();
	exec_action(main->input.time_to_eat);
	drop_forks(main, i);
	return (1);
}

int	philo_sleeping(t_main *main, int i)
{
	if (print_philo(main, main->philo[i].id, BLUE, "is sleeping") == 0)
		return (0);
	exec_action(main->input.time_to_sleep);
	return (1);
}

int	philo_thinking(t_main *main, int i)
{
	if (print_philo(main, main->philo[i].id, G_BLUE, "is thinking") == 0)
		return (0);
	return (1);
}

int	philo_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->input.time_to_die)
	{
		print_philo(main, main->philo[*i].id, PINK, "died");
		main->philo_dead = 1;
		return (1);
	}
	i++;
	return (0);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (0);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (0);
	main->philo[i].num_of_times_ate++;
	return (1);
}
