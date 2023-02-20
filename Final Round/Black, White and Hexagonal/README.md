# Black, White, and Hexagonal

You are given an infinite hexagonal grid in which cells are numbered as shown in the figure below.

<img src="https://contest.ituacm.com/static/images/questions/b_field.png" width="50%">

Each cell is painted black or white.
You need to process $m$ requests.
The $i$-th request specifies the numbers of two cells $a_i$ and $b_i$.
Your task is to find a path between these cells such that the number of color changes along the way is minimized.

## Input Format
The first line contains two integers $n$ and $m$.

The next line contains $n$ characters $0$ or $1$.
The $i$-th character (0-based) is equal to $0$ if the $i$-th grid cell is black, and it equals $1$ if the cell is white.
All cells with numbers greater than or equal to $n$ are black.

Each of the following $m$ lines contains two space-separated integers  $a_i$ and $b_i$.

## Constraints
$1 \le n \le 3000000,$

$1 \le m \le 100000,$

$0 \le a_i, b_i \le 3000000.$

## Output Format
For every request, print a line containing the minimum number of color changes along the way connecting cells $a_i$ and $b_i$.

### Sample Input 1

```
1 4
1
0 1
0 5
1 4
1 8
```

### Sample Output 1

```
1
1
0
0
```