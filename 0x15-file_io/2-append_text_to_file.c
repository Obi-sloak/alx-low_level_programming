#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * _strlen - Calculates the length of a string.
 * @str: Pointer to the string.
 *
 * Return: The length of the string.
 */
size_t _strlen(char *str)
{
    size_t length = 0;

    while (str[length])
        length++;

    return length;
}

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: Null-terminated string to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t len = 0;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
        len = write(fd, text_content, _strlen(text_content));

    close(fd);

    if (len == -1)
        return (-1);

    return (1);
}
