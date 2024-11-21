#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Assuming BUFFER_SIZE is defined
#define BUFFER_SIZE 42

// Declaration of get_next_line function
char *get_next_line(int fd);

int main(void)
{
    int fd;
    char *line;
    char c;

    // Open the file "files/42_with_nl" in read-write mode
    fd = open("files/43_with_nl", O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Scenario 1: Read the first line using get_next_line
    line = get_next_line(fd);
    if (line == NULL)
    {
        printf("get_next_line returned NULL\n");
        close(fd);
        return 1;
    }
    else
    {
        printf("First line read: %s\n", line);
        free(line); // Free the allocated memory if necessary
    }

    // Scenario 2: If BUFFER_SIZE is 42, read one character and check if it's '1'
    if (BUFFER_SIZE == 42)
    {
        c = 0;
        ssize_t bytes_read = read(fd, &c, 1);
        if (bytes_read == -1)
        {
            perror("Error reading from file descriptor");
            close(fd);
            return 1;
        }
        else if (bytes_read == 0)
        {
            printf("Reached end of file unexpectedly\n");
            close(fd);
            return 1;
        }

        // Check if the character read is '1'
        if (c == '3')
        {
            printf("Character read is '3' as expected.\n");
        }
        else
        {
            printf("Character read is '%c', expected '3'.\n", c);
        }
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
