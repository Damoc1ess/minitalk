
NAME = lib_minitalk.a

CC = cc

CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC_C = src/server.c\
			src/client.c\
			utils/utils_1.c\
			utils/utils_2.c\


OBJS =  server.o\
			client.o\
			utils_1.o\
			utils_2.o\

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) -c
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) src/server.c $(NAME) -o server
	@$(CC) $(CFLAGS) src/client.c $(NAME) -o client

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf server
	@rm -rf client
	@rm -rf $(NAME)

re : fclean all
	@rm -rf $(OBJS)