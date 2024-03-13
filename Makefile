FUNC = truc.c

# CC = gcc -Wall -Wextra -Werror
CC = cc
NAME = fractol
OBJ = $(FUNC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Imlx $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(NAME):
# 	$(CC) -Imlx truc.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


$(OBJ): $(FUNC)
	$(CC) -Wall -Wextra -Werror -Imlx -c $(FUNC)


clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(OBJ_BNS)

re: fclean all

.PHONY :