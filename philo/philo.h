#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				num_of_philo;
	int				total_eaten;
	int				*check_dead;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	

}	t_philo;

int		ft_arg_check(int ac, char **av);
long	ft_atol(const char *str);
void	ft_arg_init(t_philo *philo, int ac, char **av);


#endif