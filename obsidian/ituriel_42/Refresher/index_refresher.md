Here is the code for index refresher : 

```c
void	index_refresher(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head->index = i;
		if (head->index <= (list_size(head) / 2))
			head->above_median = 0;
		else
			head->above_median = 1;
		i++;
		head = head->next;
	}
}
```
It's composed of :
- [[list_size]] that calculate in index(1) the size of my list.