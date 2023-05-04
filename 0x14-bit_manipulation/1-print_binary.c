#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int i;

	for (i = sizeof(n) * 8 - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
			putchar('1');
		else
			putchar('0');
	}
}
