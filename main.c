
#include <mlx.h>
#include "philo.h"

void	*transcript(void *param)
{
	t_data		*philo;

	philo = param;
	choice(philo);
	return (NULL);
}

void	init_mutex(t_sticks *sticks)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		sticks->action[i] = 0;
		sticks->life[i] = MAX_LIFE;
		sticks->used[i] = 0;
		if (pthread_mutex_init(&sticks->chopstick[i], NULL) != 0)
			error();
		i++;
	}
}

void	init_data(void)
{
	int				i;
	pthread_t		philo_th[7];
	t_data			philo[7];
	t_sticks		chopsticks;

	i = 0;
	init_mutex(&chopsticks);
	chopsticks.mlx = mlx_init();
	chopsticks.win = mlx_new_window(chopsticks.mlx, 500, 500, "philosouf");
	mlx_expose_hook(chopsticks.win, expose_hook, &chopsticks);
	while (i < 7)
	{
		philo[i].l_st = i + 1;
		if (i == 6)
			philo[i].l_st = 0;
		philo[i].name = i;
		philo[i].sticks = &chopsticks;
		if (pthread_create(&philo_th[i], NULL, transcript, &philo[i]) != 0)
			error();
		i++;
	}
	chronos(philo);
	mlx_key_hook(chopsticks.win, key_hook, &chopsticks);
	mlx_loop(chopsticks.mlx);
}

int		main(void)
{
	init_data();
	return (0);
}
