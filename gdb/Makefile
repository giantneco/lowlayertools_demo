.PHONY: clean all

all: main

main: main.c
	gcc -o $@ -g -O0 -Wall --std=c99 $<

clean:
	@rm -rf *.o main
