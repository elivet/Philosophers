
#include "philo.h"

void	ft_putstr(char const *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
}
