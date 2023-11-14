#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* printint - prints the given int num
* @num: the number to print
* Return: the number of printed characters
*/

int printint(int num)
{
	int n = 0;
	int i = 0;
	char sign;
	char buffer[20];

	if (num < 0)
	{
		sign = '-';
		write(1, &sign, 1);
		n++;
		num = -num;
	}
	if (num == 0)
	{
		buffer[i++] = '0';
	}
	while (num > 0)
	{
		buffer[i++] = '0' + (num % 10);
		num /= 10;
	}
	while (i--)
	{
		write(1, &buffer[i], 1);
		n++;
	}

	return (n);
}

/**
* printstr - prints the given string
* @str: the string to print
* Return: the number of printed characters
*/
int printstr(const char *str)
{
	int n = 0;

	while (*str)
	{
		write(1, str++, 1);
		n++;
	}

	return (n);
}

/**
* parsef - parses the format directives
* @format: the format string
* @args: the arguments
* Return: the number of printed characters
*/
int parsef(const char *format, va_list args)
{
	int n = 0;
	char c;
	char *s;
	int num;

	switch (*format)
	{
		case '%':
			write(1, format, 1);
			n++;
		break;
		case 'c':
			c = va_arg(args, int);
			write(1, &c, 1);
			n++;
		break;
		case 's':
			s = va_arg(args, char*);
			n += printstr(s);
		break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			n += printint(num);
		break;
		default:
			write(1, format, 1);
			n++;
		break;
	}

	return (n);
}

/**
* _printf - print a formated string
* @format: the format string
* @...: the variadic arguments
* Return: the number of printed characters
*/
int _printf(const char *format, ...)
{
	int n = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			n++;
			format++;
			continue;
		}
		format++;
		n += parsef(format, args);

		format++;
	}

	va_end(args);

	return (n);
}
