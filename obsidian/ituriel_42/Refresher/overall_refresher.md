It's a code supposed to refresh the ->index part of my structure.

```c
void	overall_refresher(t_list *head_a, t_list *head_b)
{
	index_refresher(head_a);
	index_refresher(head_b);

	ft_printf("overall refreshed.\n");
}
```

It is composed of :
- [[index_refresher]] 