
all: printf

printf: *.c
	gcc -Wall -Werror -Wextra -Wno-format -pedantic -g -std=gnu89 *.c -o printf

