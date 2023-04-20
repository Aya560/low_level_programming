#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints any combination of char, int, float or string arguments
 *
 * @format: a list of types of arguments passed to the function
 *           c: char
 *           i: integer
 *           f: float
 *           s: char * (if the string is NULL, print (nil) instead)
 * Return: void
 */
void print_all(const char * const format, ...)
{
    va_list args;
    char c;
    int i;
    double f;
    char *s;
    int len = 0;

    va_start(args, format);

    while (*(format + len) != '\0')
    {
        switch (*(format + len))
        {
            case 'c':
                c = va_arg(args, int);
                printf("%c", c);
                break;
            case 'i':
                i = va_arg(args, int);
                printf("%d", i);
                break;
            case 'f':
                f = va_arg(args, double);
                printf("%f", f);
                break;
            case 's':
                s = va_arg(args, char *);
                if (s == NULL)
                    printf("(nil)");
                else
                    printf("%s", s);
                break;
            default:
                len++;
                continue;
        }

        len++;

        if (*(format + len) != '\0' &&
            (*(format + len) == 'c' || *(format + len) == 'i'
             || *(format + len) == 'f' || *(format + len) == 's'))
            printf(", ");
    }

    printf("\n");

    va_end(args);
}
