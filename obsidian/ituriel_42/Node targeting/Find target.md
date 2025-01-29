Here is the code for find target:
```c
t_list	*find_target(t_list *head_a, t_list *b_node)
{
	t_list	*best_target;
	long	min_value;
	long	max_value;
	t_list	*tmp;

	best_target = head_a;
	tmp = head_a;
	min_value = LONG_MAX;
	max_value = LONG_MIN;
	value_filler(&min_value, &max_value, head_a);
	if (b_node->data < min_value)
		return (mini_value(head_a, min_value));
	if (b_node->data > max_value)
		return (mini_value(head_a, min_value));
	tmp = head_a;
	while (tmp)
	{
		if (tmp->data >= b_node->data)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (best_target);
}
```

I'm here using various functions that help me keeping the 42 syntax (25 lines hello) ! 
- [[value_filler]] actually browse stack A to fill min and max value. 
- [[mini_value]] and [[maxi_value]] help me returning the values ( less variables hihi)