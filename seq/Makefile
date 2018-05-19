CXX = g++
CXXFLAGS = -g

TARGETS = main

all: $(TARGETS)

main: main.c
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
	-rm $(TARGETS)

.PHONY: all clean
