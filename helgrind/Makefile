.PHONY: clean all

all: main

main: main.c
	gcc -o $@ -g -Wall --std=c99 $< -lpthread

clean:
	@rm -rf *.o main
