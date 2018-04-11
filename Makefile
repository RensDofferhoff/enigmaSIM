# Rens Dofferhoff
PROGNAME = engimaSIM
SRC = ./
INCLUDE = ./include
FLAGS = -Wall -std=c++14 -g
SOURCES =  Plugboard.cpp RotorComplex.cpp Rotor.cpp Mapping.cpp EnigmaMachine.cpp

_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
OBJECTS = $(addprefix $(SRC)/, $(_OBJECTS))

all:	main

main:	$(OBJECTS)
		g++ $(FLAGS) enigmaSIM.cpp -o $(PROGNAME) -I $(INCLUDE) $^

%.o:	%.cpp
		g++ $(FLAGS) -I $(INCLUDE)  -o $@  -c $<

.PHONY:	clean

clean:
	rm -f $(SRC)/*.o ./$(PROGNAME)
