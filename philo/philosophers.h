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

/* philo.c: */

/* libft_functions.c: */
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_is_all_digits(int ac, char **av);
int		ft_isdigitorsignal(char c);

#endif
