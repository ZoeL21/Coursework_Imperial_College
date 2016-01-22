HEADERS = enigma.h errors.h
CPPFLAGS = g++ -Wall
OBJ = reflector.o plugboard.o rotor.o enigma.o encryption.o main.o
EXE = enigma

$(EXE): $(OBJ)
	$(CPPFLAGS) -g $(OBJ) -o $(EXE)

plugboard.o: plugboard.cpp $(HEADERS)
	$(CPPFLAGS) -c plugboard.cpp

reflector.o: reflector.cpp $(HEADERS)
	$(CPPFLAGS) -c reflector.cpp

rotor.o: rotor.cpp $(HEADERS)
	$(CPPFLAGS) -c rotor.cpp

enigma.o: enigma.cpp $(HEADERS)
	$(CPPFLAGS) -c enigma.cpp

encryption.o: encryption.cpp $(HEADERS)
	$(CPPFLAGS) -c encryption.cpp
main.o: main.cpp enigma.h
	g++ -Wall -c main.cpp
