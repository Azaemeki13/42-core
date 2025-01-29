```c
void	push_until_three(t_list **head_a, t_list **head_b)
{
	while ((*head_a)->next->next->next != 0)
	{
		push_b(head_a, head_b);
	}
	while ((*head_a)->prev)
	{
		(*head_a) = (*head_a)->prev;
	}
	ft_printf("Successfully pushed all \n");
	return ;
}
```
NB : take the comment out ! ~ 