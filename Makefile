FUNC = main.c escape.c utils.c events.c

CC = gcc -Wall -Wextra -Werror -fsanitize=address
NAME = fractol
OBJ = $(FUNC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Imlx $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): $(FUNC)
	$(CC) -Wall -Wextra -Werror -Imlx -c $(FUNC)

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(OBJ_BNS)

re: fclean all

.PHONY :