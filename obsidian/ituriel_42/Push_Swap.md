##  Error checking & push_3

- Treat argv, whether it’s a string containing numbers separated with spaces, or just lots of strings containing an int. Also sort out typos etc.. for split dont hesitate to malloc + 2 to mimic the argv behaviour.
- While initialising the stack, check for overflow, underflow (AtoLong), duplicates (While →next )
- Next step is [[Tiny Sort logic]]![[Pasted image 20250129133935.png]]
- create function highest node,that look for biggest node and flags it //DONE

### [[Tiny Sort logic]]

After tiny Sort, we push the nodes in b until 3 remain in A, this is done on function  **[[Push until three]]** .

## Node targeting 

After this, we can focus on a new concept. We need each node in stack B to target one precise node in A according to the following   logic : 

> [!ns = NodeStack, S = stack]
#### Case 1: nsB > sA

We're in this case linking the nsB with the smallest value of sA. This way, we could just when nsB travels to A rotate Aa to put this new high value to bottom of the stack.

#### Case 2: nsB < sA

nsB should then be linked with the smallest biggest number so that there is minimum interval between the two of them.

Let's dive into the code for [[Node targeting]].

## Calculating the prices 

OK now we do have our target, but let's remind that the goal of this exercise is to sort a stack in a minimum amount of time, so for this we now need to calculate prices. 
*What's a price ?* 
**Well simply answered it's the amount of moves you'll need to do in order to put the node on top of the stack.**
Like the index we will add this to my [[data structure]].

Let's take a look at [[price_refresher]].
as price_refresher always refreshes the price, I want to use it after i'm done with my main logic loop. 

![[Untitled Diagram.svg]]