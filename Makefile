CC=gcc
Include=-I./include/
CCFLAGS=-xc -Wall -Wextra -Werror --std=c99

./obj/aralloc.o: ./include/types.h ./include/aralloc.h ./src/aralloc.c
	$(CC) $(CCFLAGS) $(Include) ./src/aralloc.c -c -o $@

./obj/aralloc.so: ./include/types.h ./include/aralloc.h ./src/aralloc.c
	$(CC) $(CCFLAGS) $(Include) -fPIC -shared ./src/aralloc.c -o $@ 

.DEFAULT_GOAL := obj

.PHONY: obj dll so clean

obj: ./obj/aralloc.o 
so: ./obj/aralloc.so 
dll: ./obj/aralloc.so

clean: 
	rm -rf ./obj/*
