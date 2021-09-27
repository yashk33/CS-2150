#Yash Kolli, ysk6dw, 3/24/21, Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2

OBJECTS = AVLNode.o AVLPathTest.o AVLTree.o

avl: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out

.PHONY: clean
clean:
	-rm -f *.o *~a.out

AVLNode.o: AVLNode.cpp AVLNode.h
	  $(CXX) -c AVLNode.cpp

AVLPathTest.o: AVLPathTest.cpp
	     $(CXX) -c AVLPathTest.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	     $(CXX) -c AVLTree.cpp
