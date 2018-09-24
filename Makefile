NAME    =   markov

G++ =   g++

CXXFLAGS  =   -W -Wall -Wextra -Werror -std=c++11

SRC =   main.cpp

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

