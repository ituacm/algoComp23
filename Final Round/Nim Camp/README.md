# Nim Camp

Alice and Bob take part in a Nim game training camp.
Nim is a game of strategy in which two players take turns removing stones from distinct piles.
On each turn, a player must remove at least one stone, and may remove any number of stones provided they all come from the same pile.
The goal of the game is to take the last stone.

The camp consists of $t$ training days.
On the $i$-th day, first Alice defines the initial game state, i.e. the number of piles and the number of stones in each pile.
There are several rules she must obey:

1. there must be at least one pile,
2. the number of stones in each pile must be between $l_i$ and $r_i$, inclusive,
3. the sizes of all piles must be distinct.


Then they play the Nim game.
Bob starts first, and both players follow the optimal strategy.
If possible, Alice will choose the initial game state that allows her to win.
If there are multiple such states, she will at **first minimize the number of piles** and **second minimize the total number of stones**.
Your task is to help Alice.

## Input Format

The first line contains the number of training days $t$.
Each of the following $t$ lines contains two integers $l_i$ and $r_i$ separated by a single space.

## Constraints

$1 \le t \le 10^6$,

$1 \le l_i \le r_i \le 10^{18}$.

## Output Format

Print $t$ lines.
The $i$-th line should contain the number of piles and the total number of stones (separated by a single space) in the initial game state.
If there is no way Alice can win, print "-1 -1" instead (quotes for clarity).

### Sample Input 1

```
2
1 6
1 2
```

### Sample Output 1

```
3 6
-1 -1
```

### Explanation
In the first sample, Alice chooses three piles with $1$, $2$, and $3$ stones. 

In the second sample, Alice can't win.