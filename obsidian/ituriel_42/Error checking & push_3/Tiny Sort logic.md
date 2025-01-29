## Case 1 : All is sorted (best case scenario)
![[Pasted image 20250129134052.png]]
Well nothing to do in this case we just return.

```c
int	is_sorted(t_list *head_a)
{
	long	data2;
	long	data3;

	data2 = head_a->next->data;
	if (!head_a->next->next)
	{
		if (head_a->data < data2)
			return (1);
		else
			return (0);
	}
	else
	{
		data3 = head_a->next->next->data;
		if (head_a->data < data2 && data2 < data3)
			return (1);
		else
			return (0);
	}
}
```

## Case 2 : Not sorted
![[Pasted image 20250129134313.png]]
No problemo ! We just need to bubble sort the list, we look if values are sorted at the top of the pile, swap if not, then just rotate to bring next number 😊

The goal of this thingy is to sort, rotate, then sort again then rotate again.
```c
void sort_three(t_list **head_a)
{
    if (is_sorted(*head_a))
        return;
    if ((*head_a)->data > (*head_a)->next->data)
        swap_a(*head_a);
    rotate_a(head_a);
    if ((*head_a)->data > (*head_a)->next->data)
        swap_a(*head_a);
    reverse_rotate_a(head_a);
    if((*head_a)->data > (*head_a)->next->data)
    {
        swap_a(*head_a);
    }
} 
```