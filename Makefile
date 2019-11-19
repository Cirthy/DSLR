# ansi chars
LOG = 	\033[2K
BLUE = 	\033[1;34m
YELLOW =\033[1;33m
GREEN =	\033[1;32m
RED =	\033[1;31m
CLEAR =	\033[0m
BOLD =	\033[1m
UNDERL =\033[4m
SHI =	\xF0\x9F\x9B\xA1
TRA =	\xF0\x9F\x97\x91
LIG =	\xE2\x9A\xA1
BR_V =	\xe2\x95\x91
BR_H =	\xe2\x95\x90
CR_UR =	\xe2\x95\x97
CR_UL =	\xe2\x95\x94
CR_DR =	\xe2\x95\x9d
CR_DL =	\xe2\x95\x9a

# comp
CC =            g++
CFLAGS =        -Wall -Wextra -Werror

# binaries
NAME =          trainer

# directories
SRC_DIR =       sources

# sources
SRC_LIST =      main.cpp\
                trainer.cpp\
                managment.cpp\
                utils.cpp\
                calculus.cpp

# paths
SRCS =	$(addprefix $(SRC_DIR)/, $(SRC_LIST))

################################################################################

all : $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	 @echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(NAME) "$(CLEAR)$(LIG)"

fclean :
	rm -f $(NAME)

re : fclean all
