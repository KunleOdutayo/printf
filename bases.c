#include "main.h"
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>

/**
* printbin - print the binary representation of num
* @num: the unsigned int to print
* @n: the count of characters printed
* Return: error code
*/
int printbin(unsigned int num, int *n)
{
	char bit[] = {'0', '1'};

	if (num > 1)
	{
		printbin(num / 2, n);
	}
	write(STDOUT_FILENO, &bit[num % 2], 1);
	(*n)++;

	return (0);
}

/**
* printint - prints the given int num
* @num: the number to print
* @n: the count of characters printed
* Return: error code
*/

int printint(int num, int *n)
{
	unsigned int ui = num;
	int sign;

	if (num < 0)
	{
		write(STDOUT_FILENO, &"-", 1);
		(*n)++;
		sign = num >> (sizeof(int) * CHAR_BIT - 1);
		ui = (num ^ sign) - sign;
	}
	printuint(ui, n);

	return (0);

}

/**
* printuint - prints the given usigned int
* @num: the number to print
* @n: the count of characters printed
* Return: error code
*/

int printuint(unsigned int num, int *n)
{
	int i = 20;
	char buffer[20];

	if (num == 0)
	{
		buffer[--i] = '0';
	}
	while (num > 0)
	{
		buffer[--i] = '0' + (num % 10);
		num /= 10;
	}
	write(STDOUT_FILENO, &buffer[i], 20 - i);
	*n += 20 - i;

	return (0);
}

/**
* printoct - prints the octal representation of the given usigned int
* @num: the number to print
* @n: the count of characters printed
* Return: error code
*/

int printoct(unsigned int num, int *n)
{
	char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7' };

	if (num > 7)
	{
		printoct(num / 8, n);
	}
	write(STDOUT_FILENO, &digit[num % 8], 1);
	(*n)++;

	return (0);
}

/**
* printhex - prints the hexadecimal representation of the given usigned int
* @num: the number to print
* @cap: wheter to use captial letters
* @n: the count of characters printed
* Return: error code
*/

int printhex(unsigned int num, bool cap, int *n)
{
	char digit[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char base = (cap) ? 'A' : 'a';
	char x;

	if (num > 15)
	{
		printhex(num / 16, cap, n);
	}
	if (num % 16 > 9)
	{
		x = base + num % 16 - 10;
		write(STDOUT_FILENO, &x, 1);
	}
	else
		write(STDOUT_FILENO, &digit[num % 16], 1);
	(*n)++;

	return (0);
}
