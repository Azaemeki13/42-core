
I have a structure t_list which is composed of the following: 

```c
typedef struct s_list
{
	long			data;
	int				index;
	int				push_price;
	int				cheapest;
	int				above_median;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target_node;
}					t_list;
```
- **data**-> The actual data stored in the node, this is what I want to sort.
- **index**-> The "rank" of the node, it's in base 0 so 0 means at top, while max is at bottom.
- **push_price**-> is the amount of moves i'll need to put at top of stack
- **cheapest**-> is a boolean marker, if 0 it's not the cheapest, else it is.
- **above_median**-> is also a boolean marker, if 0, it's beyond median else it's above.
- **next and prev**-> they're pointers to neighbor nodes.
- **target_node**-> For stack B, it concerns the element in sA that's supposed to be linked to nsB.