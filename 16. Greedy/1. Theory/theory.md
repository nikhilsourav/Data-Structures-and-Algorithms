## Definition:

- Greedy algorithms are mainly used in optimization problems.
- Optimization problems generally involves maximizing or minimizing something. For eg: shortest path, longest path
- Greedy algorithm makes optimal choice at each step as it attempts to find the overall optimal way to solve the entire problem

<br/>

## General structure:

<br/>

```
getOptimal(arr[], n, item)

1. Initialize res = 0

2. while (all items are not considered)
    {
        i = selectAnItem()
        if(isFeasible(i))
            res = res + i
    }

3. return res
```

## Applications:

- Activity selection
- Fractional knapsack
- Job sequencing
- Prim's algorithm
- Kruskal's algorithm
- Dijkstra's algorithm
- Huffman coding
