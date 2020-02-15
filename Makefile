NAME = fillit
SRC = src/main.c src/check.c src/clear.c src/fullsq.c src/lstpos.c src/sq.c src/checkgnl.c
OBJ = $(subst .c,.o,$(subst src/,,$(SRC)))
INCLUDES = includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBPATH = libft/libft.a

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGC) -o $(NAME) $(OBJ) -L libft -lft

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC) -Iincludes/ -Ilibft/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all
