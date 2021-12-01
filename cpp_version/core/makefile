all: Node.o Tree.o
	g++ -std=c++17 Node.o Tree.o main.cpp

Node: Node.h Node.cpp
	g++ -std=c++17 Node.cpp -o Node.o

Tree: Tree.h Tree.cpp
	g++ -std=c++17 Tree.cpp -o Tree.o

clean:
	rm *.o a.out
