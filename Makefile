# Nom des exécutables
CLIENT = client
SERVER = server

# Dossiers
SRC_DIR = src
UTILS_DIR = utils
INCLUDE_DIR = utils

# Fichiers sources
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
UTILS_SRC = $(UTILS_DIR)/ft_printfdubled.c

# Options de compilation
CFLAGS = -Wall -Wextra -Werror
CC = gcc

# Cibles
all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(UTILS_SRC)
	$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT) $(UTILS_SRC)

$(SERVER): $(SERVER_SRC) $(UTILS_SRC)
	$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER) $(UTILS_SRC)

clean:
	rm - $(CLIENT) $(SERVER) $() *.o

fclean: clean

re: fclean all

.PHONY: all clean fclean re
