#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to text in a file
 * @letters: number of letters
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file, fread, fwrite;
    char *buffer;

    // Allocate memory for the buffer
    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    if (filename == NULL)
    {
        free(buffer);
        return (0);
    }

    // Open the file
    file = open(filename, O_RDONLY);
    if (file == -1)
    {
        free(buffer);
        return (0);
    }

    // Read from the file
    fread = read(file, buffer, letters);
    if (fread == -1)
    {
        free(buffer);
        close(file);
        return (0);
    }

    // Write to the standard output
    fwrite = write(STDOUT_FILENO, buffer, fread);
    if (fwrite == -1)
    {
        free(buffer);
        close(file);
        return (0);
    }

    // Clean up and return the number of bytes written
    free(buffer);
    close(file);
    return (fwrite);
}
