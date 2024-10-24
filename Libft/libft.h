/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:00:06 by azaemeki13        #+#    #+#             */
/*   Updated: 2024/10/21 15:38:32 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
typedef long unsigned int	size_t;
# define NULL ((void *)0)

int ft_atoi(const char *nptr);
void ft_bzero(void *s, size_t n);
void *ft_calloc (size_t elementCount, size_t elementSize);
static size_t ft_count_words(const char *s, char c);
int ft_isalnum(int argument1);
int ft_isalpha(int argument1);
int ft_isascii(int argument1);
int ft_isdigit(int argument1);
int ft_isprint(int argument1);
int	ft_isspace(int c);
int ft_findy(const void *s2, int c, size_t n);
void *ft_memccpy(void *s1, const void *s2, int c, size_t n);
void *ft_memchr(const void *str, int c, size_t n);
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void *ft_memcpy(void *destination, const void *source, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *ptr, int value, size_t num);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strchr (const char *s, int c);
char *ft_strdup (const char *src);
char *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t n);
size_t ft_strlen(const char *str);
int ft_strncmp (const char *str1, const char *str2, size_t num);
char *ft_strndup(const char *s, size_t n);
char *ft_strncpy( char * destination, const char * source, size_t num);
char *ft_strnstr(const char *s1, const char *s2, size_t len);
char *ft_strtrim( const char *s1, const char *set);
char *ft_strrchr (const char *s, int c);
int ft_tolower(int argument1);
int ft_toupper(int argument1);

int ft_atoi(const char *nptr)
{
    int i;
    int f;
    int current;
    int final;

    final = 0;
    i = 0;
    f = 1;
    while (nptr[i] != 0)
    {
        while(ft_isspace(nptr[i]))
            i++;
        while(nptr[i] == '+' || nptr[i] == '-')
        {
            if (nptr[i] == '-')
                f = - 1;
            i++;
        }
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
            current = nptr[i] -'0';
            final = final * 10 + current;
            i++;
        }
         while (nptr[i] < '0' ||nptr[i] > '9')
            return (final * f);
    }
    return (final * f);
}

void	ft_bzero(void *s, size_t n)
{
	char	*base;
	size_t	i;

	i = 0;
	base = (char *)s;
	while (i < n)
	{
		base[i] = '\0';
		i++;
	}
}

void *ft_calloc (size_t elementCount, size_t elementSize)
{
    void * final;
    size_t totalSize;

    totalSize = elementCount * elementSize;
    final = malloc(totalSize);
    if (final == NULL)
        return NULL;
    ft_memset(final, 0, totalSize);
    return final;
}

size_t count_words(const char *s, char c)
{
    size_t count;
    int in_word;

    count = 0;
    in_word = 0;

    while (*s)
    {
        if (*s != c && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

int ft_isalnum(int argument1)
{
    char convert;

    convert = (char)argument1;
    if ((convert < 48 || convert > 57) && (convert < 65 || convert > 90) && (convert < 97 || convert > 122))
        return 0;
    return 1;
}

int ft_isalpha(int argument1)
{
    char convert;
    convert = (char)argument1;
    if ((convert < 'A' || argument1 > 'Z') && (argument1 < 'a' || argument1 > 'z'))
        return 0;
    return 1;
}

int ft_isascii(int argument1)
{
    char convert;

    convert = (char) argument1;
    if (convert > 0 || convert < 127)
        return 0;
    return 1;
}

int ft_isdigit(int argument1)
{
    char compare;

    compare = (char)argument1;
    if ((compare < '0' || compare > '9'))
        return 0;
    return 1;
}

int ft_isprint(int argument1)
{
    char convert;

    convert = (char)argument1;

    if ((convert < 33 || convert > 126))
        return 0;
    return 1;
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int ft_findy(const void *s2, int c, size_t n)
{
    unsigned const char *s_two;
    unsigned char baite;
    size_t i;

    i = 0;
    baite = (unsigned char)c;
    s_two = (unsigned const char *)s2;
    while (n != 0)
    {
        if (s_two[i] == c)
            return 1;
        i++;
        n--;
    }
    return 0;
}

void *ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
    unsigned char baite;
    unsigned char *s_one;
    unsigned const char *s_two;

    int i;

    i = 0;
    s_one = (unsigned char *)s1;
    s_two = (unsigned const char *)s2;
    baite = (unsigned char)c;
    if (!ft_findy(s2, c, n))
        return s_one = NULL;

    while (s_two[i] != baite && n > 0)
    {
        *s_one = s_two[i];
        s_one++;
        i++;
        n--;
    }
    *s_one = 0; // idk if i need to remove that one or not.
    return s_one + 1;
}

void *ft_memchr(const void *str, int c, size_t n)
{
    const unsigned char *string;
    size_t i;

    string = (char *)str;
    i = 0;
    while (i < n)
    {
        if (string[i] == (unsigned char)c)
            return ((void *)(string + i));
        i++;
    }
    return (0);
}

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*pointer1;
	const unsigned char	*pointer2;
	size_t				i;

	pointer1 = (const unsigned char *)ptr1;
	pointer2 = (const unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (pointer1[i] != pointer2[i])
			return (pointer1[i] - pointer2[i]);
		i++;
	}
	return (0);
}

void *ft_memcpy(void *destination, const void *source, size_t num)
{
    size_t i;
    unsigned char *dest;
    const unsigned char *src;

    dest = (unsigned char *)destination;
    src = (const unsigned char *)source;
    i = 0;
    while (i < num)
    {
        dest[i] = src[i];
        i++;
    }
    return destination;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*convert;
	const char	*convert1;
	char		temp[n+1];

	convert = (char *)dest;
	convert1 = (const char *)src;
	i = 0;
	while (i != n)
	{
		temp[i] = convert1[i];
		i++;
	}
	i = 0;
	while (i != n)
	{
		convert[i] = temp[i];
        i++;
	}
	convert[i + 1] = 0; // same here
	return (convert);
}

void *ft_memset(void *ptr, int value, size_t num)
{
  char *base;
  int i;

  i = 0;
  base = (char *)ptr;
  while (i < num)
  {
    base[i] = (char)value;
    i++;
  }
  return ptr;
}

char *ft_strchr (const char *s, int c)
{
    char *result;

    result = (char*) s;
    while (*result != '\0')
    {
        if(*result == (char)c)
            return (char *)result;
        result++;
    }
    if (c == '\0')
        return ((char *)s);
}

char *ft_strdup (const char *src)
{
    char * dest;
    int i;

    dest = malloc(sizeof(src));
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t total_size;
    unsigned int i;
    unsigned int j;
    char * final;

    i = 0; 
    j = 0;
    total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
    final = malloc(total_size * sizeof(char));
    while (s1[i] != 0)
    {
        final[j] = s1[i];
        j++;
        i++;
    }
    i = 0;
    while (s2[i] != 0)
    {
        final[j] = s2[i];
        j++;
        i++;
    }
    final[j] = '\0';
    return (final);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int		i;
	size_t	dst_len;
	size_t	src_len;
	size_t	remaining;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (n <= (dst_len))
		return (src_len + n);
	remaining = (n - dst_len - 1);
	while (i < remaining && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

size_t ft_strlcpy(char *dst, const char *src, size_t n)
{
    size_t i;
    size_t a;

    i = 0;
    a = ft_strlen(src);
    if (a == 0)
        return a;
    if (n == 0)
        return a;
    while (i != n-1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i+1] = '\0';
    return (a);
}

size_t	ft_strlen(const char *str)
{
	char	*nav;
	size_t	i;

	i = 0;
	nav = (char *)str;
	while (nav[i] != 0)
	{
		i++;
	}
	return (i);
}

char * ft_strncpy ( char * destination, const char * source, size_t num)
{
    size_t i;

    i = 0;
    if (destination == NULL)
        return NULL;
    while ( i != num && source[i] != 0)
    {
        destination[i] = source[i];
        i++;
    }
    while (i != num)
    {
        destination[i] = 0;
        i++;
    }
    return (destination);
}

int ft_strncmp (const char *str1, const char *str2, size_t num)
{
    size_t i;
    int result;

    i = 0;
    while (i < num && str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return str1[i]- str2[i];
        i++;
    }
    if (i < num && str1[i] == 0 ||str2[i] == 0)
        return (str1[i] - str2[i]);
    return 0;
}

char *ft_strndup(const char *s, size_t n)
{
    char *dup;

    dup = (char*)malloc(n + 1);
    if (!dup)
        return NULL;
    ft_strncpy(dup,s,n);
    dup[n] = '\0';
    return (dup);
}

char * ft_strnstr(const char *s1, const char *s2, size_t len)
{
    size_t i;
    size_t j;
    size_t s2_len;

    i = 0;
    s2_len = ft_strlen(s2);
    if (*s2 == 0)
        return ((char*) s1);
    while (s1[i] != 0 && (i + s2_len) <= len)
    {
        j = 0;
        while (s1[i+j] == s2[j] && s2[j] != 0)
            j++;
        if (j == s2_len)
            return ((char *) s1 + i);
        i++;
    }
    return NULL;
}

char *ft_strrchr (const char *s, int c)
{
    char *result;
    

    result = (char*) s;
    while (*s != '\0')
    {
        if (*s == (char) c)
            result = (char*)s;
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return result;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char * substring;
    size_t i;

    i = 0;
    substring = calloc(len, sizeof(const char));
    if (substring == NULL)
        return NULL;
    while (start != len )
    {
        substring[i] = s[start];
        i++;
        start++;
    }
    return substring;
}

int ft_tolower(int argument1)
{
    char convert;

    convert = (char)argument1;
    if (convert > 'A' || convert < 'Z')
        return convert += 32;
    return 0;
}

int ft_toupper(int argument1)
{
    char convert;

    convert = (char)argument1;
    if (convert > 'a' || convert < 'z')
        return convert -= 32;
    return 0;
}

#endif