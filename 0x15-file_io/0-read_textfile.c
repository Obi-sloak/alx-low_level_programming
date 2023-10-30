#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         Otherwise - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, fread, fwrite;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		free(buffer);
		return (0);
	}

	fread = read(file, buffer, letters);
	if (fread == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	fwrite = write(STDOUT_FILENO, buffer, fread);
	if (fwrite == -1 || fwrite != fread)
	{
		free(buffer);
		close(file);
		return (0);
	}

	free(buffer);
	close(file);

	return (fwrite);
}
