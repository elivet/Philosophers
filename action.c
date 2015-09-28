
#include <unistd.h>
#include "philo.h"

void	sleep_time(t_data *philo)
{
	philo->sticks->action[philo->name] = 0;
	usleep(REST_T * 1000000);
	choice(philo);
}

void	left_stick(t_data *philo)
{
	if (right_availability(philo))
	{
		philo->sticks->used[philo->name] = 2;
		pthread_mutex_lock(&(philo->sticks->chopstick[philo->name]));
		philo->sticks->used[philo->l_st] = 2;
		pthread_mutex_lock(&(philo->sticks->chopstick[philo->l_st]));
		philo->sticks->action[philo->name] = 2;
		usleep(EAT_T * 1000000);
		philo->sticks->life[philo->name] = MAX_LIFE;
		pthread_mutex_unlock(&(philo->sticks->chopstick[philo->name]));
		philo->sticks->used[philo->name] = 0;
		pthread_mutex_unlock(&(philo->sticks->chopstick[philo->l_st]));
		philo->sticks->used[philo->l_st] = 0;
		sleep_time(philo);
	}
	else
	{
		philo->sticks->used[philo->l_st] = 1;
		philo->sticks->action[philo->name] = 1;
		usleep(THINK_T * 1000000);
		philo->sticks->used[philo->l_st] = 0;
	}
}

void	right_stick(t_data *philo)
{
	philo->sticks->used[philo->name] = 3;
	philo->sticks->action[philo->name] = 3;
	usleep(THINK_T * 1000000);
	philo->sticks->used[philo->name] = 0;
}

void	choice(t_data *philo)
{
	if (left_availability(philo))
		left_stick(philo);
	else if (right_availability(philo))
		right_stick(philo);
	else
		sleep_time(philo);
	choice(philo);
}
