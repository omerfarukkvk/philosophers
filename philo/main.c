/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <okavak@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:36:47 by okavak            #+#    #+#             */
/*   Updated: 2022/12/14 20:06:29 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (!ft_arg_check(ac, av))
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atol(av[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(av[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo || !forks || !death)
		return (0);
	ft_arg_init(philo, ac, av);
	ft_mutex_init(philo, forks, death);
}
