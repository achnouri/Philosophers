NAME    = philo
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS = sources/main_/philo_main.c \
	   sources/parse/check_if_valid.c \
	   sources/parse/initalize_data.c \
	   sources/simulation/simulation.c \
	   sources/simulation/get_set.c \
	   sources/simulation/routine.c \
	   sources/simulation/monitoring.c \
	   sources/simulation/one_philo.c \
	   sources/utils/display_msg.c \
	   sources/utils/parse_utils.c \
	   sources/utils/simulation_utils.c \
	   sources/utils/terminate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) include/philo.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
