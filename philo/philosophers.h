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

# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

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
	pthread_mutex_t	write;
}					t_main;

/* main.c: */


/* philo.c: */
void		input_philos(int ac, char **av, t_main *main);
int			create_philos(t_main *main);
void		start_philo(t_main *main, int i, int j);

/* threads.c: */
int			create_threads(t_main *main);
int			join_threads(t_main *main);
int			destroy_threads(t_main *main);

/* forks.c: */
int			create_forks(t_main *main);
void		unlock_forks(t_main *main);

/* time.c: */
long long	get_time(void);
long long	delta_time(long long time);
void		exec_action(long long time);

/* actions.c: */
int			philo_eating(t_main *main, int i);
int			philo_sleeping(t_main *main, int i);
int			philo_thinking(t_main *main, int i);
int			philo_dead(t_main *main, int *i);
int			drop_forks(t_main *main, int i);

/* routine.c: */
void		*routine(void *args);
int			routine_execute(t_main *main, int i);
void		*checker(void *args);
int			print_philo(t_main *main, int id, char *color, char *status);

/* libft_functions.c: */
long		ft_atol(const char *str);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
int			ft_is_all_digits(int ac, char **av);
int			ft_isdigitorsignal(char c);

#endif
