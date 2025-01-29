```c
t_list	*maxi_value(t_list *head_a, int max_value)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = head_a;
	while (tmp->data != max_value)
		tmp = tmp->next;
	return (tmp);
}
```