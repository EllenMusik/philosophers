NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
#DEBUG = -fsanitize=address -g
HEADER = philo.h
RM = rm -rf

SRC_DIR	=	./src
OBJ_DIR	=	./obj

FILES	=	philo\


SRC		=	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJ		=	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DEBUG) -pthread $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -pthread -o $@ -c $<

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re