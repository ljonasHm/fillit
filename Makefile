NAME = fillit
SRC = src/main.c src/fillit1.c
OBJ = main.o fillit1.o
INCLUDES = includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBPATH = libft/libft.a
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIBPATH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
