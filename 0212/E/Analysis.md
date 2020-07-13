# Analysis

## Intuition
You can't color all n nodes. But you can always color n-1 nodes if you choose one node to not be colored and color all attached ligaments, with at least one ligament colored differently from the rest.

## Strategy
Since n - 1 is the maximum, we generate all the ways we can paint i nodes red and n - i - 1 blue.

Iterate over all nodes, considering the possibility they are uncolored. This is now a simple dp problem. With certain denominations of coins, what possible sums can you generate?

Possible sums not in the for loop:
- Everything above it (coming from parent) is an option to be colored red. (dp[n - size[rt]]) 
- Nothing (dp[0])

Then iterate over all kids. The logic here is that if you are capable of coloring j nodes red, you can color j + sz[kid] nodes red.

Of course, you cannot color 0 nodes red, because then you wouldn't have two colors. You also can't color n - 1 nodes blue for the same reason.