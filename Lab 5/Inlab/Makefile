#Yash Kolli, ysk6dw, 3/23/21, Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2

OBJECTS = BinaryNode.o BSTPathTest.o BinarySearchTree.o

pizza: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out

.PHONY: clean
clean:
	-rm -f *.o *~a.out

BinaryNode.o: BinaryNode.cpp BinaryNode.h
	  $(CXX) -c BinaryNode.cpp

BSTPathTest.o: BSTPathTest.cpp
	     $(CXX) -c BSTPathTest.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	     $(CXX) -c BinarySearchTree.cpp
