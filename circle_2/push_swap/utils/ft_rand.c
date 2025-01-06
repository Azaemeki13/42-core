/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ituriel <ituriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:49:42 by ituriel           #+#    #+#             */
/*   Updated: 2025/01/06 16:20:38 by ituriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

unsigned long long not_so_random(unsigned long long *seed, unsigned long long a, unsigned long long c, unsigned long long m,unsigned long long r)
{
    (*seed) = (( a * (*seed) + c ) % ((m* r)));
}

int ft_rand (unsigned long long r)
{
    unsigned long long seed;
    unsigned long long a;
    unsigned long long c;
    unsigned long long m;
    unsigned long long result;

    seed = 9171536436;
    a = 6274956735;
    c = 5028841971;
    m = 4428810975;
    result = not_so_random(&seed, a, c, m, r);
}

int main (int argc, char **argv)
{
    unsigned long long r;
    unsigned long long result;

    r = ft_atoi(argv[2]);
    result = ft_rand(r);
    if (argc < 2)
    {
        return (ft_printf ("Please try again with good forking arguments :)"));
    }
    else
    {
        ft_printf("The random number is : %d", result);
    }
}

void list_generator (t_rand_list **head, int max_number)
{
    t_rand_list *new_node = NULL;
    t_rand_list *current_node = NULL;

    new_node = malloc(sizeof (t_list));
    new_node->number = rand() % (max_number + 1);
    new_node->next = NULL;
    if (*head == NULL) 
    {
        *head = new_node;
    }
    else 
    {
        current_node = (*head);
        while (current_node->next != NULL)
            current_node = current_node-> next;
        current_node->next = new_node;
    }
} 

t_rand_list *rand_list(int number_a)
{
    t_rand_list *result = NULL;
    int i;

    i = 0;
    while (i < number_a)
    {
        list_generator(&result, INT_MAX);
        i++;
    }
    return (result);
}

/*
int main()
{
    t_rand_list *result = NULL;
    t_rand_list *current = NULL;
    t_rand_list *temp = NULL;

    result = rand_list(50);
    current = result;
    while (current)
    {
        printf("Value : %d\n", current->number);
        current = current->next;
    }
    while (result)
    {
        temp = result;
        result = result->next;
        free(temp);
    }
    return 0;
}*/