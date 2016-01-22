IntegerArray_exe: IntegerArray.o main.o
	g++ -Wall -g IntegerArray.o main.o -o IntegerArray_exe

IntegerArray.o: IntegerArray.cpp IntegerArray.h
	g++ -Wall -c IntegerArray.cpp 

main.o: main.o IntegerArray.h
	g++ -Wall -c main.cpp  
