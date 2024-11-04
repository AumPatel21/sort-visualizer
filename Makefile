# Author: Aum Patel

CC = g++
CFLAGS = -g --std=c++17 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = visualizer.hpp visualizer.cpp main.cpp

.PHONY: all visualizer clean

all: visualizer

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

visualizer: visualizer.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o visualizer

lint:
	*.cpp *.hpp