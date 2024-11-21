#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Open the test file
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // First call to get_next_line
    line = get_next_line(fd);
    if (line)
    {
        printf("First call result: \"%s\"\n", line);
        free(line); // Free the memory allocated by get_next_line
    }
    else
    {
        printf("First call result: NULL\n");
    }

    // Second call to get_next_line
    line = get_next_line(fd);
    if (line)
    {
        printf("Second call result: \"%s\"\n", line);
        free(line); // Free the memory allocated by get_next_line
    }
    else
    {
        printf("Second call result: NULL\n");
    }

    // Close the file
    close(fd);
    return (0);
}