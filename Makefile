

NAME= philo

FLAGS= -Wall -Wextra -Werror

SRC= main.c error.c test.c ft_putendl.c ft_putstr.c ft_putchar.c \
		action.c show.c ft_itoa.c displays.c draw.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SRC) -g
		gcc -lpthread -o $(NAME) $(OBJ) -L/usr/X11/lib -lX11 -lmlx -lXext

%.o: %.c
		gcc $(FLAGS) -c $^ -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
