CXX = g++
CXXFLAGS = -g -fopenmp

TARGETS = main

all: $(TARGETS)

main: main.c
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
	-rm $(TARGETS)

.PHONY: all clean
