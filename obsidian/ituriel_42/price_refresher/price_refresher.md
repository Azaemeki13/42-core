So, the goal of price refresher is to browse through sA with a nsB, by adding the price of pushing both cheapest and target node, we have the full price to combine elements.
Here is the code :

```c
void	price_refresher(t_list *head_a, t_list *head_b)
{
	int		len_a;
	int		len_b;
	t_list	*current_node;
	int		cost_a;
	int		cost_b;

	current_node = NULL;
	len_a = list_size(head_a);
	len_b = list_size(head_b);
	current_node = head_b;
	while (current_node)
	{
		cost_b = minimal_rotation_cost(current_node->index, len_b);
		cost_a = 0;
		if (current_node->target_node)
			cost_a = minimal_rotation_cost(current_node->target_node->index,
					len_a);
		current_node->push_price = cost_a + cost_b;
		current_node = current_node->next;
	}
}
```
It is composed with the following functions :
- [[minimal_rotation_cost]]
- [[list_size]]
