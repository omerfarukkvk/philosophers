#include "philo.h"

int	ft_arg_check(int ac, char **av)
{
	int i;
	int j;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (!(av[i][j] >= '0' && av[i][j] <= '9'))
					return (0);
				if (av[1][0] == '0')
					return (0);
				j++;
			}
			i++;
		}
	}
	else
		exit(EXIT_FAILURE);
	return (1);
}

void	ft_arg_init(t_philo *philo, int ac, char **av)
{
	
}