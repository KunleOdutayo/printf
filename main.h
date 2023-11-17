#ifndef MAIN__PRINTF
#define MAIN__PRINTF

#include <stdarg.h>


int _printf(const char *format, ...);
int parsef(const char *format, va_list args, int *n);
int printstr(const char *str, int *n);
int printint(const int num, int *n);
int printbin(unsigned int num, int *n);
int printuint(unsigned int num, int *n);
int printoct(unsigned int num, int *n);


#endif
