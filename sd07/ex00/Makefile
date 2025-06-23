NAME = library
SRC = library.c ../../utils/ft_strlen.c ../../utils/strcasestr_custom.c
OBJ = $(SRC:.c=.o)
CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all