# Sweep Rowing

A sweep rowing is a type of academic rowing where each athlete paddles with one oar to the left or the right of the boat.
The rowing team consists of $2 n$ athletes numbered from 1 to $2 n$ in the order in which they sit in the boat.
The ideal placement of rowers must meet two conditions:

1. the number of athletes rowing on the left (L-rowers) should be the same as the number of athletes rowing on the right (R-rowers);
2. the sum of the numbers of L-rowers should be equal to the sum of the numbers of R-rowers.

For example, if $n=2$, arrangements **LRRL** and **RLLR** are ideal, whereas arrangements **LRRR** and **RLRL** are not.

Your task is to find the number of ideal arrangements for a given $n$.
Since this number can be large, print it modulo $10^9+7$.

## Input Format

The input contains one integer $n$.

## Constraints

$1 \le n \le 250.$

## Output Format

Print the number of different ideal arrangements modulo $10^9+7$.

### Sample Input 1

```
1
```

### Sample Output 1

```
0
```

### Sample Input 2

```
2
```

### Sample Output 2

```
2
```