Minimal rotation cost is a helper function which goal is to help me reducing the amount of moves required to put a node a top at the stack. 
It's pretty simple, we have two ways of moving a node, rotate or reverse rotate, one drags it to the bottom, the other at the top.
So if the node is above median, we want to drag it a the bottom, else at the top. 
Here is the code :

```c
int	minimal_rotation_cost(int i, int len)
{
	if (i <= len / 2)
		return (i);
	else
	{
		return (len - i);
	}
}
```