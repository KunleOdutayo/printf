#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"


/**
* printchar - prints the given character
* @chr: the string to print
* @n: the count of characters printed
* Return: error code
*/
int printchar(const char chr, int *n)
{
	write(STDOUT_FILENO, &chr, 1);
	(*n)++;
	return (0);
}

/**
* printstr - prints the given string
* @str: the string to print
* @n: the count of characters printed
* Return: error code
*/
int printstr(const char *str, int *n)
{
	if (str == NULL)
	{
		write(STDOUT_FILENO, &"(null)", 6);
		*n += 6;
		return (0);
	}

	while (*str)
	{
		write(STDOUT_FILENO, str++, 1);
		(*n)++;
	}

	return (0);
}

/**
* printnum - prints the given num
* @format: the format string
* @args: the arguments
* @n: the count of characters printed
* Return: error code
*/
int printnum(const char *format, va_list args, int *n)
{
	int num;
	unsigned int ui;

	switch (*format)
	{
		case 'd': case 'i':
			num = va_arg(args, int);
			printint(num, n);
		break;
		case 'b':
			ui = va_arg(args, unsigned int);
			printbin(ui, n);
		break;
		case 'u':
			ui = va_arg(args, unsigned int);
			printuint(ui, n);
		break;
		case 'o':
			ui = va_arg(args, unsigned int);
			printoct(ui, n);
		break;
		case 'x':
			ui = va_arg(args, unsigned int);
			printhex(ui, false, n);
		break;
		case 'X':
			ui = va_arg(args, unsigned int);
			printhex(ui, true, n);
		break;
		default:
			write(STDOUT_FILENO, format - 1, 2);
			*n += 2;
	}
	return (0);
}

/**
* parsef - parses the format directives
* @format: the format string
* @args: the arguments
* @n: the count of characters printed
* Return: error code
*/
int parsef(const char *format, va_list args, int *n)
{
	char *s, c;

	switch (*format)
	{
		case '%':
			printchar('%', n);
		break;
		case 'c':
			c = va_arg(args, int);
			printchar(c, n);
		break;
		case 's':
			s = va_arg(args, char*);
			printstr(s, n);
		break;
		case '\0': return (-1);
		break;
		default:
			printnum(format, args, n);
	}
	return (0);
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

	if (format == NULL)
		return (-1);

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
		r = parsef(format, args, &n);
		if (r < 0)
			return (r);

		format++;
	}

	va_end(args);

	return (n);
}
