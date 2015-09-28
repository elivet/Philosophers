
#include "philo.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

t_tools		draw_horizontal(int l, int w, t_tools t, int i)
{
	if (i == 5 || i == 6)
	{
		t.lmax = 10 + l + 115;
		t.lmin = 15 + l + 115;
	}
	else
	{
		t.lmax = 10 + l;
		t.lmin = 15 + l;
	}
	t.wmax = 400 + w - 135;
	t.wmin = 200 + w;
	t.y = t.lmin - 10;
	return (t);
}

t_tools		draw_first(int l, int w, t_tools t)
{
	t.lmax = 100 + l;
	t.lmin = 50 + l;
	t.wmax = 250 + w + 56;
	t.wmin = 200 + w + 100;
	t.y = t.lmin - 10;
	return (t);
}

void		draw_sticks(int l, int w, t_sticks *copy, int i)
{
	t_tools		t;

	if (i != 0 && i != 3 && i != 4)
		t = draw_horizontal(l, w, t, i);
	else if (i == 0)
		t = draw_first(l, w, t);
	else
	{
		t.lmax = 100 + l;
		t.lmin = 50 + l;
		t.wmax = 250 + w - 65;
		t.wmin = 200 + w - 20;
		t.y = t.lmin - 10;
	}
	while (t.y < t.lmax)
	{
		t.x = t.wmin;
		while (t.x < t.wmax)
		{
			mlx_pixel_put(copy->mlx, copy->win, t.x, t.y, copy->sti_co);
			t.x++;
		}
		t.y++;
	}
}
