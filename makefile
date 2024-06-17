CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I.
GUIFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES_DEMO = tree.hpp node.hpp demo.cpp
SOURCES_TEST = tree.hpp node.hpp test.cpp testCounter.cpp

all: demo
	./demo

demo: demo.o tree.o node.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GUIFLAGS)

test: test.o testCounter.o tree.o node.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind: demo
	valgrind $(VALGRIND_FLAGS) ./demo
	

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test

.PHONY: all test clean valgrind
