NAME = fillit
SRC = main.c check.c clear.c fullsq.c lstpos.c sq.c checkgnl.c
OBJ = $(SRC:.c=.o)
LIB_DIR = libft
INC_DIR = . libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c $(addprefix -I, $(INC_DIR))
LIBFLAGS = -L $(LIB_DIR) -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LIBFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	make -C $(LIB_DIR) clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -f $(NAME)

re: fclean all
