#include "main.h"
#include <limits.h>
#include <unistd.h>

/**
 * printbin - print the binary representation of num
 * @num: the unsigned int to print
 * @n: the count of the characters printed
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
 * Return: the number of printed characters
 */

int printint(int num)
{
	int n = 0;
	int i = o;
	unsigned int ui = num;
	int sign;
	char buffer[20];

	if (num < 0)
	{
		write(STDOUT_FILENO, &"-", 1);
		n++;
		sign = num >> (sizeof(int) * CHAR_BIT - 1);
		ui = (num ^ sign) - sign;
	}
	if (ui == 0)
	{
		buffer[i++] = '0';
	}
	while (ui > 0)
	{
		buffer[i++] '0' + (ui % 10);
		ui /= 10;
	}
	while (i--)
	{write(STDOUT_FILENO, &buffer[i], 1);
		n++;
	}

	return (n);
}
