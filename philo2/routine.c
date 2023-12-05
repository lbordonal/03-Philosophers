/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:53 by lbordona          #+#    #+#             */
/*   Updated: 2023/12/05 19:29:24 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->n_thread;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo[i].num_of_times_ate
			&& main->philo_dead == 0)
			routine_execute(main, i);
	}
	else
	{
		while (main->philo_dead == 0)
		{
			if (routine_execute(main, i) == 0)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eating(main, i) == 0)
		return (0);
	if (main->input.num_of_times_eat != main->philo[i].num_of_times_ate)
	{
		if (philo_sleeping(main, i) == 0)
			return (0);
		if (philo_thinking(main, i) == 0)
			return (0);
	}
	return (1);
}

void	*checker(void *args)
{

}

int	print_philo(t_main *main, int id, char *color, char *status)
{

}
