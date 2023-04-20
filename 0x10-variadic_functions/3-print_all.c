#include <stdio.h>
#include <stdarg.h>

void print_all(const char * const format, ...)
{
    va_list args;
    char c;
    int i;
    float f;
    char *s;

    va_start(args, format);

    while (*format)
    {
        switch (*format)
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
                f = va_arg(args, double);  // we need to promote float to double
                printf("%f", f);
                break;
            case 's':
                s = va_arg(args, char *);
                if (s == NULL)
                    printf("(nil)");
                else
                    printf("%s", s);
                break;
        }

        format++;

        if (*format)  // if there are more arguments to come
        {
            if (*format == 'c' || *format == 'i' || *format == 'f' || *format == 's')
                printf(", ");
        }
    }

    printf("\n");

    va_end(args);
}
