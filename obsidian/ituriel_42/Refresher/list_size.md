Here is the code for list_size.

```c
int	list_size(t_list *head)
{
	t_list	*current_node;
	int		i;

	current_node = NULL;
	i = 0;
	current_node = head;
	while (current_node)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}
```