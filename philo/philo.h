/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <okavak@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:36:52 by okavak            #+#    #+#             */
/*   Updated: 2022/12/14 19:36:52 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				num_of_philo;
	int				total_eaten;
	int				*check_dead;
	t_time			time2die;
	t_time			time2eat;
	t_time			time2sleep;
	t_time			start_time;
	t_time			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		ft_arg_check(int ac, char **av);
long	ft_atol(const char *str);
void	ft_arg_init(t_philo *philo, int ac, char **av);
t_time	ft_get_time_of_ms(void);
void	ft_mutex_init(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);

#endif