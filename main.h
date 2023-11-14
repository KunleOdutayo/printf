#ifndef MAIN__PRINTF
#define MAIN__PRINTF

#include <stdarg.h>


int _printf(const char *format, ...);
int parsef(const char *format, va_list args);
int printstr(const char *str);
int printint(const int num);



#endif
