#include <stdio.h>
#include <stdarg.h>

void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_string(va_list args);

/**
 * print_all - prints any combination of char, int, float or string arguments
 *
 * @format: a list of types of arguments passed to the function
 *           c: char
 *           i: integer
 *           f: float
 *           s: char * (if the string is NULL, print (nil) instead)
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	while (*(format + len) != '\0')
	{
		switch (*(format + len))
		{
			case 'c':
				print_char(args);
				break;
			case 'i':
				print_int(args);
				break;
			case 'f':
				print_float(args);
				break;
			case 's':
				print_string(args);
				break;
			default:
				len++;
				continue;
		}

		len++;

		if (*(format + len) != '\0' &&
		    (*(format + len) == 'c'
		     || *(format + len) == 'i'
		     || *(format + len) == 'f'
		     || *(format + len) == 's'))
			printf(", ");
	}

	printf("\n");

	va_end(args);
}

/**
 * print_char - prints a character argument
 *
 * @args: a va_list of arguments
 *
 * Return: void
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);

	printf("%c", c);
	printf("\n");
}

/**
 * print_int - prints an integer argument
 *
 * @args: a va_list of arguments
 *
 * Return: void
 */
void print_int(va_list args)
{
	int i = va_arg(args, int);

	printf("%d", i);
	printf("\n");
}

/**
 * print_float - prints a float argument
 *
 * @args: a va_list of arguments
 *
 * Return: void
 */
void print_float(va_list args)
{
	double f = va_arg(args, double);

	printf("%f", f);
	printf("\n");
}

/**
 * print_string - prints a string argument
 *
 * @args: a va_list of arguments
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
		printf("(nil)");
	else
		printf("%s", s);

	printf("\n");
}
