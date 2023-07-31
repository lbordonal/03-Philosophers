/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:33:54 by lbordona          #+#    #+#             */
/*   Updated: 2023/07/27 20:13:52 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_input
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_eat;
}		t_input;

typedef struct s_fork
{
	int	left;
	int	right;
}		t_fork;

typedef struct s_philo
{
	int			id;
	int			num_of_times_ate;
	long long	time_to_die;
	t_fork		fork;
	pthread_t	thread;
}				t_philo;

typedef struct s_main
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_input			input;
	t_philo			*philo;
	pthread_t		orchestrator;
	pthread_mutex_t	*forks;
	phtread_mutex_t	write;
}					t_main;

/* philo.c: */

/* libft_functions.c: */
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_is_all_digits(int ac, char **av);
int		ft_isdigitorsignal(char c);

#endif
