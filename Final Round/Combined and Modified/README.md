# Combined and Modified

Combined is an event in alpine ski racing.
A traditional combined competition consists of downhill and slalom runs.
Each discipline runs on separate days.

In one of the modified versions, the winner is determined in the following way.
For each skier, penalty points are calculated as the product of places this skier took in each of the two disciplines.
The winner is the skier with the fewest penalty points.

Assume your favorite skier is one of the $n$ competitors.
The downhill is over, and the slalom is now underway.
Thus the final downhill places are already known as well as the current places of skiers who have already done their slalom runs.
Note that slalom places can change after other skiers' runs.
You can also assume skier results in a discipline can never be identical, i.e. their places are always distinct.

Is it possible for your favorite skier to win the combined, i.e. to get strictly fewer penalty points than all other competitors?
Your task is to find any scenario which would allow this.

## Input Format

The first line contains integer $n$.

Each of the next $n$ lines contains two space-separated integers $a_i$ and $b_i$, denoting places of the $i$-th skier in downhill and slalom, respectively.
If $b_i = 0$, then this skier has not yet performed in slalom.
Your favorite skier is the first one on this list.

## Constraints

$1 \le n \le 10000,$

$1 \le a_i \le n,$

$0 \le b_i \le n,$

all $a_i$ are distinct,

all non-zero elements $b_i$ are distinct and form a permutation.

## Output Format

If it's impossible for your favorite skier to win, print $-1$.

Otherwise, print $n$ lines.
The $i$-th line should contain the $i$-th skier final place in slalom.
The provided outcome should be valid and such that your favorite skier wins the combined.

If there are multiple possible answers, print any of them.

### Sample Input 1

```
4
3 0
2 0
4 0
1 0

```

### Sample Output 1

```
1
3
2
4

```