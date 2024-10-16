/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:03:54 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 11:51:00 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void *ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
    unsigned char *destination;
    const unsigned char *source;
    size_t i;

    destination = (unsigned char *)dest_str;
    source = (const unsigned char *)src_str;
    if (dest_str == src_str || numBytes == 0)
        return dest_str;
    if (destination > source)
    {
        i = numBytes - 1;
        while (i >= 0)
        {
            destination[i] = source[numBytes];
            i--;
        }
    }
    else
    {
        i = 0;
        while (i < numBytes)
        {
            destination[i] = source[i];
            i++;
        }
    }

    return (dest_str);
}

int main(void)
{
    // Test 1: Basic Non-overlapping case (same as before)
    char src1[] = "Hello, World!";
    char dest1[20];

    printf("Test 1 - Source before ft_memmove: %s\n", src1);
    ft_memmove(dest1, src1, 13); // Move 13 bytes from src to dest
    dest1[13] = '\0';            // Manually null-terminate
    printf("Test 1 - Destination after ft_memmove: %s\n\n", dest1);

    // Test 2: Overlapping case (destination is after source, moving forwards)
    char overlapTest2[] = "1234567890";
    printf("Test 2 - Before ft_memmove (overlap forwards): %s\n", overlapTest2);
    ft_memmove(overlapTest2 + 4, overlapTest2, 6); // Move "123456" to position starting at index 4
    printf("Test 2 - After ft_memmove (overlap forwards): %s\n\n", overlapTest2);

    // Test 3: Overlapping case (destination is before source, moving backwards)
    char overlapTest3[] = "1234567890";
    printf("Test 3 - Before ft_memmove (overlap backwards): %s\n", overlapTest3);
    ft_memmove(overlapTest3, overlapTest3 + 4, 6); // Move "567890" to position starting at index 0
    printf("Test 3 - After ft_memmove (overlap backwards): %s\n\n", overlapTest3);

    // Test 4: Small move of 0 bytes
    char zeroMoveSrc[] = "ABCDE";
    char zeroMoveDest[10];

    printf("Test 4 - Source before ft_memmove: %s\n", zeroMoveSrc);
    ft_memmove(zeroMoveDest, zeroMoveSrc, 0); // Move 0 bytes
    printf("Test 4 - Destination after ft_memmove (0 bytes): %s\n\n", zeroMoveDest);

    // Test 5: Moving one byte only
    char oneByteSrc[] = "Test";
    char oneByteDest[10];

    printf("Test 5 - Source before ft_memmove: %s\n", oneByteSrc);
    ft_memmove(oneByteDest, oneByteSrc, 1); // Move 1 byte
    oneByteDest[1] = '\0';                  // Null terminate manually
    printf("Test 5 - Destination after ft_memmove (1 byte): %s\n\n", oneByteDest);

    // Test 6: Entire buffer copy
    char largeSrc[] = "This is a large test string!";
    char largeDest[50];

    printf("Test 6 - Source before ft_memmove: %s\n", largeSrc);
    ft_memmove(largeDest, largeSrc, sizeof(largeSrc)); // Move entire buffer including '\0'
    printf("Test 6 - Destination after ft_memmove: %s\n\n", largeDest);

    return 0;
}