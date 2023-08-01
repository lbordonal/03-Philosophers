/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:32:59 by lbordona          #+#    #+#             */
/*   Updated: 2023/07/27 21:05:10 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ft_is_all_digits(ac, av) == 0)
		exit (0);
	if (ac < 5 || ac > 6)
		return (0);
	while (i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (input_check(ac,av) == 0 || )
	{
		printf("%s\n", "Please, verify the input → [Number of philosophers] [Time to die] [Time to eat] [Time to sleep] [Eat times]");
		return (0);
	}
	input_philos(ac, av, main);
	printf("%i\n", main->input.num_philo);
}

