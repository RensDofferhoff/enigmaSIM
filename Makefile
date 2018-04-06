# Rens Dofferhoff
PROGNAME = engimaSIM
SRC = ./
INCLUDE = ./include
FLAGS = -Wall -std=c++14 -g
SOURCES =  Plugboard.cc RotorComplex.cc Rotor.cc Mapping.cc EnigmaMachine.cc

_OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))
OBJECTS = $(addprefix $(SRC)/, $(_OBJECTS))

all:	main

main:	$(OBJECTS)
		g++ $(FLAGS) enigmaSIM.cpp -o $(PROGNAME) -I $(INCLUDE) $^

%.o:	%.cc
		g++ $(FLAGS) -I $(INCLUDE) -o $@  -c $<

.PHONY:	clean

clean:
	rm -f $(SRC)/*.o ./$(PROGNAME)
