CPPFLAGS = g++ -Wall -g
EXE = isprime

$(EXE): main.o isprime.o
	$(CPPFLAGS) isprime.o main.o -o $(EXE)

isprime.o: isprime.cpp isprime.h
	$(CPPFLAGS) -c isprime.cpp

main.o: main.cpp isprime.h
	$(CPPFLAGS) -c main.cpp
