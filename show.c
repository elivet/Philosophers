
#include "philo.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

void	draw(int l, int w, t_sticks *copy, int i)
{
	t_tools		t;

	t.lmax = (75 + l) + (50 * copy->life[i] / MAX_LIFE) - 10;
	t.lmin = 25 + l;
	t.wmax = (250 + w) + (25 * copy->life[i] / MAX_LIFE) - 10;
	t.wmin = 200 + w;
	t.y = t.lmin;
	while (t.y < t.lmax)
	{
		t.x = t.wmin;
		while (t.x < t.wmax)
		{
			mlx_pixel_put(copy->mlx, copy->win, t.x, t.y, copy->act_co);
			t.x++;
		}
		t.y++;
	}
	draw_sticks(l, w, copy, i);
}

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}

void	get_colour(t_sticks *copy, int i)
{
	copy->sti_co = 0xC2BDC2;
	if (copy->action[i] == 1)
	{
		copy->act_co = 0x5EB6DD;
		copy->sti_co = 0x99FF33;
	}
	else if (copy->action[i] == 2)
	{
		copy->act_co = 0xc6357e;
		copy->sti_co = 0x99FF33;
	}
	else if (copy->action[i] == 3)
	{
		copy->act_co = 0x5EB6DD;
		if (copy->action[(i - 1) % 7] == 2)
			copy->sti_co = 0x99FF33;
	}
	else
	{
		copy->act_co = 0xFDD131;
		if (copy->action[(i - 1) % 7] == 2 || copy->action[(i - 1) % 7] == 3)
			copy->sti_co = 0x99FF33;
		else
			copy->sti_co = 0xC2BDC2;
	}
}

int		expose_hook(t_sticks *copy)
{
	if (copy)
		return (0);
	return (0);
}

int		expose(t_sticks *c)
{
	char	*lives;

	lives = ft_itoa(c->life[0]);
	mlx_clear_window(c->mlx, c->win);
	get_colour(c, 0);
	draw(0, 0, c, 0);
	mlx_string_put(c->mlx, c->win, 240, 20, c->act_co, lives);
	free(lives);
	display_one(c);
	display_two(c);
	display_three(c);
	display_four(c);
	display_five(c);
	lives = ft_itoa(c->life[6]);
	get_colour(c, 6);
	draw(65, 135, c, 6);
	mlx_string_put(c->mlx, c->win, 460, 135, c->act_co, lives);
	free(lives);
	return (0);
}
