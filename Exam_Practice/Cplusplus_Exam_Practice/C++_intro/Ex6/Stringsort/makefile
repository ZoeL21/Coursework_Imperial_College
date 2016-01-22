FLAGS= g++ -Wall -g -v
EXE= stringsort

$(EXE): main.o stringsort.o
	$(FLAGS) main.o stringsort.o -o $(EXE)

main.o: main.cpp stringsort.h
	$(FLAGS) -c main.cpp

stringsort.o: stringsort.cpp stringsort.h
	$(FLAGS) -c stringsort.cpp
