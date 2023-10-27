#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: parameter
 */
void print_binary(unsigned long int n)
{
	int i, num = 0;
	unsigned long int new;

	for (i = 63; i >= 0; i--)
	{
		new = n >> i;

		if (new & 1)
		{
			_putchar('1');
			new++;
		}
		else if (num)
			_putchar('0');
	}
	if (!num)
		_putchar('0');
}
