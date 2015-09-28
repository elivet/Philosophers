
#include <mlx.h>
#include <stdlib.h>
#include "philo.h"

void	display_one(t_sticks *c)
{
	char	*lives;

	lives = ft_itoa(c->life[1]);
	get_colour(c, 1);
	draw(65, -135, c, 1);
	mlx_string_put(c->mlx, c->win, 30, 135, c->act_co, lives);
	free(lives);
}

void	display_two(t_sticks *c)
{
	char	*lives;

	lives = ft_itoa(c->life[2]);
	get_colour(c, 2);
	draw(200, -145, c, 2);
	mlx_string_put(c->mlx, c->win, 25, 270, c->act_co, lives);
	free(lives);
}

void	display_three(t_sticks *c)
{
	char	*lives;

	lives = ft_itoa(c->life[3]);
	get_colour(c, 3);
	draw(325, -75, c, 3);
	mlx_string_put(c->mlx, c->win, 165, 470, c->act_co, lives);
	free(lives);
}

void	display_four(t_sticks *c)
{
	char	*lives;

	lives = ft_itoa(c->life[4]);
	get_colour(c, 4);
	draw(325, 75, c, 4);
	mlx_string_put(c->mlx, c->win, 320, 465, c->act_co, lives);
	free(lives);
}

void	display_five(t_sticks *c)
{
	char	*lives;

	lives = ft_itoa(c->life[5]);
	get_colour(c, 5);
	draw(200, 145, c, 5);
	mlx_string_put(c->mlx, c->win, 465, 270, c->act_co, lives);
	free(lives);
}
