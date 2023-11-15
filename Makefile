CFLAGS=-Wall -Werror -Wextra -Wno-format -pedantic -g -std=gnu89
all: printf

printf: *.c test/main.c
	gcc  $(CFLAGS) *.c test/main.c -o printf

