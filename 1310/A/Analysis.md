## Analysis
Beautiful problem. 

## Strategy 
Big idea is that sum tracks the cost of everything in the priority queue. We start from the smallest value and work our way up. We choose the most costly one (sometimes the only one) to keep at that value. 
All others stay in the PQ and get their costs added to res for as long as they stay in there.

If there's nothing in the PQ, that means we can move onto the next value (tracked by i).

If there's nothing left in nums (i == n), then we go through what's been added to the PQ. (ex. 1 1 1 are the a values)
