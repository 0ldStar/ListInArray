.PHONY: all clean rebuild

FLAGS = -Wall -Werror=format-security -Wextra
CC = g++

all: list main
	$(CC) $(FLAGS) main.o list.o -o build/menu
main: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp -o main.o
list: src/ListInArray.cpp
	$(CC) $(FLAGS) -c src/ListInArray.cpp -o list.o
clean:
	rm -rf *.o *.a *.so *.out ../build/*
run:
	./build/menu
rebuild:
	$(MAKE) clean
	$(MAKE) all