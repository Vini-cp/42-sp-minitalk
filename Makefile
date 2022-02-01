NAME = minitalk

SRC_CLIENT = ft_client.c src/ft_atoi.c src/ft_strlen.c
OBJ_C = $(SRC_CLIENT:.c=.o)
CLIENT_NAME = client

SRC_SERVER = ft_server.c src/ft_strlen.c src/ft_concatenate.c src/ft_itoa.c src/ft_strdup.c
OBJ_S = $(SRC_SERVER:.c=.o)
SERVER_NAME = server

CFLAGS = -g3 -Wall -Werror -Wextra -I./

.PHONY: all clean fclean re

all:    $(NAME)

$(NAME): client server

client: $(OBJ_C)
	gcc $(CFLAGS) $(OBJ_C) -o $(CLIENT_NAME)

server:	$(OBJ_S)
	gcc $(CFLAGS) $(OBJ_S) -o $(SERVER_NAME)

clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -f server client

re:     fclean all
