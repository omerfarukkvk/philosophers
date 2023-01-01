/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <okavak@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:15:42 by okavak            #+#    #+#             */
/*   Updated: 2022/12/16 00:15:42 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eat(t_philo *philo)
{
	if (ft_check_death(philo))
		return ;
	pthread_mutex_lock(philo->left_fork);
	ft_philo_print(philo, "has taken a fork", 0);
	pthread_mutex_lock(philo->right_fork);
	ft_philo_print(philo, "has taken a fork ", 0);
	ft_philo_print(philo, "is eating", 0);
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	philo->last_meal = ft_get_time_of_ms();
	pthread_mutex_unlock(philo->death);
	ft_philo_wait(philo, philo->time2eat);
	if (ft_check_death(philo))
		return ;
}

void	ft_philo_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (ft_check_death(philo))
		return ;
	ft_philo_print(philo, "is sleeping", 0);
	ft_philo_wait(philo, philo->time2sleep);
}

void	ft_philo_think(t_philo *philo)
{
	if (ft_check_death(philo))
		return ;
	ft_philo_print(philo, "is thinking", 0);
}

void	ft_philo_print(t_philo *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->death);
	if (!*philo->check_dead)
	{
		printf ("%llu %d %s\n", (ft_get_time_of_ms() - philo->start_time), \
		philo->id + 1, status);
		if (kill)
			*philo->check_dead = 1;
	}
	pthread_mutex_unlock(philo->death);
	ft_check_death(philo);
}

int	ft_philo_wait(t_philo *philo, t_time wait_time)
{
	t_time	time;

	time = ft_get_time_of_ms();
	while (ft_get_time_of_ms() - time < wait_time)
	{
		if (ft_check_death(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
