
#include <unistd.h>
#include <mlx.h>
#include "philo.h"

int		check_alive(t_data philo, int *i)
{
	if (philo.sticks->life[philo.name] == 0)
	{
		*i = -1;
		return (0);
	}
	return (1);
}

void	*end_meet(void *param)
{
	int		current_time;
	t_data	*philo;
	int		i;

	current_time = time(NULL);
	philo = param;
	while (time(NULL) < current_time + TIMEOUT)
	{
		i = -1;
		while (++i < 7)
		{
			if (philo[i].sticks->action[i] != 2)
				philo[i].sticks->life[i]--;
			if (!check_alive(philo[i], &i))
				break ;
		}
		expose(philo[0].sticks);
		usleep(1000000);
		if (i == -1)
			break ;
	}
	if (i == -1)
		return (NULL);
	ft_putendl("Now, it is time... To DAAAAAAAANCE !!!");
	return (NULL);
}

void	chronos(t_data *philo)
{
	pthread_t		timer;
	int				i;

	i = 0;
	if (pthread_create(&timer, NULL, end_meet, philo) != 0)
		error();
	if (pthread_join(timer, NULL) != 0)
		error();
	while (i < 7)
	{
		pthread_mutex_destroy(&(philo[0].sticks->chopstick[i]));
		i++;
	}
}

int		left_availability(t_data *p)
{
	if (p->sticks->used[p->l_st] == 2)
		return (0);
	else
		return (1);
}

int		right_availability(t_data *p)
{
	if (p->sticks->used[p->name] == 2)
		return (0);
	else
		return (1);
}
