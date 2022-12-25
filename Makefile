
CC = gcc

CFLAGS = -Wall -Wextra -Werror


CLIENT = client.o

SERVER = server.o

all: client server

client: $(CLIENT)
		$(CC) client.o $(CFLAGS) -o client

server: $(SERVER)
		$(CC) client.o $(CFLAGS) -o server
clean:
	rm -rf $(CLIENT) $(SERVER)

fclean: clean
		rm -rf client server

re: fclean all