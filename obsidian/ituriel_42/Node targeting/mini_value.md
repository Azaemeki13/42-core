```c
t_list	*mini_value(t_list *head_a, int min_value)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = head_a;
	while (tmp->data != min_value)
		tmp = tmp->next;
	return (tmp);
}
```