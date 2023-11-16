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
		write(STDOUT_FILENO, &sign, 1);
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
		write(STDOUT_FILENO, &buffer[i], 1);
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
		write(STDOUT_FILENO, str++, 1);
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
			write(STDOUT_FILENO, format, 1);
			n++;
		break;
		case 'c':
			c = va_arg(args, int);
			write(STDOUT_FILENO, &c, 1);
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
		/* TODO */
		case 'b':
		case 'u':
		case 'o':
		case 'x':
		case 'X':
		case '+':
		case ' ':
		case '#':
		case 'l':
		case 'h':
		default:
			return (-1);
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
	int n = 0, r = 0;
	va_list args;

	if (format == NULL) {
		return (-1);
	}

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(STDOUT_FILENO, format, 1);
			n++;
			format++;
			continue;
		}
		format++;
		r = parsef(format, args);
		if (r < 0) {
			return (r);
		}
		n += r;

		format++;
	}

	va_end(args);

	return (n);
}
