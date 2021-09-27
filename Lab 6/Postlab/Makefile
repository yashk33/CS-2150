#Yash Kolli, ysk6dw, 3/30/21, Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2

OBJECTS = hashTable.o wordPuzzle.o timer.o

hashtable: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out

.PHONY: clean
clean:
	-rm -f *.o *~a.out

hashTable.o: hashTable.cpp hashTable.h
	  $(CXX) -c hashTable.cpp

wordPuzzle.o: wordPuzzle.cpp
	     $(CXX) -c wordPuzzle.cpp

timer.o: timer.cpp timer.h
	     $(CXX) -c timer.cpp
