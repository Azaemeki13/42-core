```c
void node_targeting(t_list **head_a, t_list **head_b)

{

t_list *b_move;

  

b_move = NULL;

b_move = (*head_b);

while (b_move)

{

b_move->target_node = find_target(*head_a, b_move);

b_move = b_move->next;

}

overall_refresher((*head_a), (*head_b));

}
```
It is composed of few functions : 
- [[Find target]]
- [[overall_refresher]]
Node targeting is what I like to call an assembler function, it reunites functions with a specific purpose all in one.
Find target is my logic function, it detects the target for each node.
overall refresher allows me to refresh the index of my lists. 