#include "main.h"
#include <stdio.h>

/**
 * get_bit - value of a bit at a given index
 * @n: decimal parameter
 * @index: index
 * Return: val
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	bit = (n >> index);
	if (index > 50)
	return (-1);
	return (bit & 1);
}
