/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:44:39 by ituriel           #+#    #+#             */
/*   Updated: 2024/11/13 12:11:25 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    static int i = 0;
    static int initialized = 0;
    char *input_buffer;
    ssize_t bytes_read;
    int j = 0;

    // Initialize buffer on first call
    if (!initialized) {
        buffer = malloc(BUFFER_SIZE * sizeof(char));
        if (!buffer)
            return NULL;
        initialized = 1;
    }

    // Allocate input_buffer to hold up to BUFFER_SIZE characters + null terminator
    input_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!input_buffer)
        return NULL;

    while (1) {
        if (i == 0 || i >= BUFFER_SIZE) {
            // Read new data if buffer is empty or all data has been processed
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0) {
                free(input_buffer);
                free(buffer);
                buffer = NULL;
                initialized = 0;
                return NULL;  // End of file or error
            }
            i = 0;  // Reset `i` to start of buffer
        }

        // Copy data from buffer to input_buffer until newline or end of buffer
        while (i < bytes_read && buffer[i] != '\n' && j < BUFFER_SIZE) {
            input_buffer[j++] = buffer[i++];
        }

        // Stop if a newline is found or BUFFER_SIZE limit is reached
        if (i < bytes_read && buffer[i] == '\n' && j < BUFFER_SIZE) {
            input_buffer[j++] = buffer[i++];  // Add newline to input_buffer
            break;
        }
        
        if (j == BUFFER_SIZE)  // Stop once BUFFER_SIZE characters are read
            break;
    }

    input_buffer[j] = '\0';  // Null-terminate the input_buffer
    return input_buffer;
}



/*

int main() {
    int fd = open("test.txt", O_RDONLY); // Open the test file in read-only mode
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s", line);  // Print each line
        free(line);                // Free the line after printing
    }

    close(fd); // Close the file when done
    return 0;
}

*/