NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I.
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(SRC_DIR)/simulation/simulation.c $(SRC_DIR)/simulation/simulate_action.c \
       $(SRC_DIR)/parsing/parse.c $(SRC_DIR)/structs/init.c $(SRC_DIR)/structs/free.c \
       $(SRC_DIR)/utils/mutex.c $(SRC_DIR)/utils/utils.c $(SRC_DIR)/philo.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re