.PHONY: all clean rebuild buildDir run rebuild

FLAGS = -Wall -Werror=format-security -Wextra
CC = g++

all: buildDir list main menu
	$(CC) $(FLAGS) main.o list.o menu.o -o build/menu
buildDir:
	mkdir -p build
main: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp -o main.o
list: src/ListInArray.cpp
	$(CC) $(FLAGS) -c src/ListInArray.cpp -o list.o
menu: src/menu.cpp
	$(CC) $(FLAGS) -c src/menu.cpp -o menu.o
clean:
	rm -rf *.o *.a *.so *.out build/*
run: all
	./build/menu
rebuild:
	$(MAKE) clean
	$(MAKE) all