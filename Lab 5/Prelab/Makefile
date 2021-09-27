#Yash Kolli, ysk6dw, 3/22/21, Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2

OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o

pizza: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out

.PHONY: clean
clean:
	-rm -f *.o *~a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h
	  $(CXX) -c TreeCalc.cpp

TreeCalcTest.o: TreeCalcTest.cpp
	     $(CXX) -c TreeCalcTest.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	     $(CXX) -c TreeNode.cpp
