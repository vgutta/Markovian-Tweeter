NAME    =   bananas2

G++ =   g++

CXXFLAGS  =   -W -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

SRC =   markovian.cpp main.cpp

OBJ =   $(SRC:.cpp=.o)

RM  =   rm -rf

all:    $(NAME)

$(NAME):    $(OBJ)
	$(G++) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBj)

fclean: clean
	$(RM) $(NAME)

re: fclean  all

