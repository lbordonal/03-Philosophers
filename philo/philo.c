/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:09:33 by lbordona          #+#    #+#             */
/*   Updated: 2023/10/08 20:27:52 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_philos(int ac, char **av, t_main *main)
{
	if (ac == 5 || ac == 6)
	{
		main->input.num_philo = ft_atoi(av[1]);
		main->input.time_to_die = ft_atoi(av[2]);
		main->input.time_to_eat = ft_atoi(av[3]);
		main->input.time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			main->input.num_of_times_eat = ft_atoi(av[5]);
		else
			main->input.num_of_times_eat = -1;
		return (0);
	}
	return (1);
}

int	create_philos(t_main *main)
{
	int	i;
	int	j;

	main->philo = malloc(sizeof(t_philo) * (main->input.num_philo + 1));
	if (main->philo == NULL)
		return (0);
	i = 0;
	j = 1;
	while (j < main->input.num_philo)
	{
		start_philo(main, i, j);
		i++;
		j++;
	}
	j = 0;
	start_philo(main, i, j);
	return (1);
}

void	start_philo(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].num_of_times_ate = 0;
	main->philo[i].time_to_die = 0;
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = j;
}
