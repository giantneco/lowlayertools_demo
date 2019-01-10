.PHONY: clean all

all: main

main: main.c
	gcc -o $@ -pg -Wall --std=c99 $<

clean:
	@rm -rf *.o main
