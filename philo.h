
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define MAX_LIFE 100
# define EAT_T 2
# define REST_T 2
# define THINK_T 1
# define TIMEOUT 100

typedef struct		s_tools
{
	int				x;
	int				y;
	int				lmax;
	int				lmin;
	int				wmax;
	int				wmin;
}					t_tools;

typedef struct		s_sticks
{
	pthread_mutex_t	chopstick[7];
	int				used[7];
	int				action[7];
	int				life[7];
	void			*mlx;
	void			*win;
	int				act_co;
	int				sti_co;
}					t_sticks;

typedef struct		s_data
{
	int				name;
	int				l_st;
	int				prev_action;
	t_sticks		*sticks;
}					t_data;

void				error(void);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				choice(t_data *philo);
int					right_availability(t_data *p);
int					left_availability(t_data *p);
void				chronos(t_data *philo);
void				draw(int l, int w, t_sticks *copy, int i);
int					expose_hook(t_sticks *copy);
int					expose(t_sticks *copy);
char				*ft_itoa(int n);
int					key_hook(int keycode);
void				display_one(t_sticks *c);
void				display_two(t_sticks *c);
void				display_three(t_sticks *c);
void				display_four(t_sticks *c);
void				display_five(t_sticks *c);
void				get_colour(t_sticks *copy, int i);
void				draw_sticks(int l, int w, t_sticks *copy, int i);
t_tools				draw_horizontal(int l, int w, t_tools t, int i);
t_tools				draw_first(int l, int w, t_tools t);

#endif
