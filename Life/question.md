# Life

Catch the vibe! https://www.youtube.com/watch?v=SBaITnCSsnQ

Every living person collects memories, happy or sad; and everybody keeps moving on regardless of what they go through because life does not stop. Sometimes you may notice that the days you thought you were sad were actually happy moments. Sometimes, you think you are living in the worst days possible when they are not at all bad. Throughout your life, you learn non-stop and prepare for something bigger. Yet this is usually realized quite late.

In this question, we will examine life. Happiness of a life... Think about a timeline that represents the memories in a lifetime. The author of this question keeps a timeline to mark the happiness score of his life. But obviously, happiness is not a constant, everybody has bad days. Normally, these days should be marked with negative values. But again, the author of this question does not do that in hopes of maybe getting over them one day. So, the timeline actually contains the emotion depth of the author's feelings with all positive values.

The author also believes that after every $k$ happy memories, he has $k$ sad memories. Also, after every $k$ sad memories, he has $k$ happy memories. Nobody lives a life with continuous happiness or sadness. These moods should follow each other. But, why $k$ memories? Please don't ask, we also don't know that.

Initially, an array of happiness scores will be given to calculate the total happiness score of a part of his life. When calculating total happiness of a time interval, you will be given left and right indexes. You should calculate the total happiness according to the given rule in the previous paragraph with assuming the first $k$ memories of a life part are always happy memories, since there is no way of knowing this and we need to make an assumption. However, be cautious! As we mentioned at the beginning of this question, these values might change later, specifically when the author reads his diaries.

Two operations will be asked to perform in every query:
1. The author wants to change the happiness score of a memory
2. The author wants to learn the total happiness score of a life part. Help him do the calculations!

## Input Format

First line consists of three integers $n$, $q$ and $k$ which are the number of memories, number of queries and $k$ respectively.

Second line consists of $n$ space separated integers. $a_i$ is the happiness value of $i$th day.

The next $q$ lines consist of $3$ integers. First integer is the $query\ type$.
- If $query\ type$ is $1$, then the next two integers are $i$ and $v$, where $v$ is the new value of $i$'th memory.
- If $query\ type$ is $2$, then the next two integers are $l$ and $r$, where $l$ is the leftmost and $r$ is the rightmost index of the life part that you need to calculate the total happiness scores for (including the rightmost index).

## Constraints

$1 \leq n, q \leq 10^5$

$1 \leq k \leq 10$

$1 \leq a_i, v \leq 10^{12}$, where $0 \leq i < n$

$0 \leq i, l, r < n$

## Output Format

For each query with type $2$, print one line with one integer which is the happiness value of given range in mod $10^9+7$.

### Sample Input

```
10 5 3
1 2 3 4 5 6 7 8 9 10
2 0 9
1 1 12
2 0 9
2 1 4
2 7 9
```

### Sample Output

```
5
15
14
27
```