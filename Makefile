# -*- Makefile -*-

PROJ	= abstractvm

SRC		= Main.cpp Exceptions.cpp OperandCreator.cpp Utils.cpp VMStack.cpp

OBJ		= $(SRC:.cpp=.o)

CXX	= clang++ -Wall -Werror -Wextra -std=c++17

RM		= rm -f

all:		$(PROJ)

$(PROJ):	$(OBJ)
	$(CXX) -o $(PROJ) $(OBJ) -g

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(PROJ)

re:	fclean all