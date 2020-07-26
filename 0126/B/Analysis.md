# Analysis

## Proof
If no suffix matches the prefix, then no solution. 

If a suffix matches the prefix, we must find something of length f[b] in the middle as well. That's why last is set to one before the end. If there is something in the middle, we're good.

Let's say region A , a suffix, is not found in the middle.
If no suffix of A that matches the prefix of A, then no solution. 

But if there is a prefix of A that is also a suffix of A (call this substring B = C = D), then that is the solution. We can easily check this because the prefix of A is also the prefix of S (the given string). How is this a guaranteed solution? We can say B is what Prefix uses, C is what Obelix uses, and since C is also a suffix of S, D is what Suffix uses.


|------------S------------|
         |--------A-------|\
|--------A-------|\
|-----B-----|\
    |------C-----|\
             |------D-----|
