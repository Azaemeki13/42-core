```c
void	value_filler(long *min_value, long *max_value, t_list *head_a)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = head_a;
	while (tmp != NULL)
	{
		if (tmp->data < *min_value)
			*min_value = tmp->data;
		if (tmp->data > *max_value)
			*max_value = tmp->data;
		tmp = tmp->next;
	}
}
```