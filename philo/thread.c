/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <okavak@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:22:57 by okavak            #+#    #+#             */
/*   Updated: 2022/12/15 14:22:57 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		pthread_create(&philo[i].thread, NULL, &ft_philo_loop, &philo[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	while ((*philo).check_dead == 0)
	{
		ft_check_death(philo);
	}
}

void	*ft_philo_loop(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->num_of_philo == 1 && !ft_check_death(philo))
	{
		if (pthread_mutex_lock(philo->left_fork))
			return (NULL);
		ft_philo_print(philo, " has taken a fork", 0);
		while (!ft_check_death(philo))
		{	
		}
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		while (1)
		{
			if (ft_check_death(philo))
				break ;
			ft_philo_eat(philo);
			ft_philo_sleep(philo);
			ft_philo_think(philo);
		}
	}
	return (NULL);
}

int	ft_check_death(t_philo *philo)
{
	if (philo->total_eaten == philo->must_eat)
		return (1);
	pthread_mutex_lock(philo->death);
	if (*philo->check_dead)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	if (ft_get_time_of_ms() - philo->last_meal > \
		philo->time2die)
	{
		ft_philo_print(philo, "died", 1);
		return (1);
	}
	return (0);
}
