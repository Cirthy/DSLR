NAME = trainer

CC = g++

CFLAGS = ##-Wall -Wextra -Werror

SRCS = trainer.cpp managment.cpp utils.cpp

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) main.cpp $(SRCS) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all


