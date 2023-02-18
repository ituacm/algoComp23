# God Mode On


> The best way to predict the future is to create it. ~ Peter Drucker

It is known by all that predicting the future is really hard, almost impossible. Sometimes our predictions turn out to be right while other times things do not go as planned. Yet we never, ever give up on planning ahead because of all the perks it has. Knowing the future would probably have the most benefit when investing. If we could know the price of a stock $X$ days from now, we could invest accordingly and make a lot of money.

Well, you see, we actually have a friend who can do this.

Novruz is a psychic who can predict the future with $100\%$ accuracy. He starts working on an automatic trading system that will be in his best interest by predicting the stock prices for the next $N$ days and uploading this data to the system. A question pops up in his mind after experimenting with a couple of transactions: For a stock that he buys on day $X$, at least how many days should he keep it so that he can sell it with minimum $A\%$ profit? See, he is not a greedy one. He just wants to take $A\%$ profit and continue enjoying the beauties of life.

Can you help Novruz to develop this system and make the best possible transactions?

**We recommend you to be careful about percentages and take into account that some bits may be lost during the division process.**


## Input Format

The first line contains two space separated integers:
- $N$: the number of days
- $Q$: the number of queries you need to answer

The second line contains $N$ space separated integers, the stock price values for $N$ consecutive days, respectively.

Following $Q$ lines contains two space separated integers:
- $X$: the day the stock is purchased (0-indexed)
- $A$: the intended profit percentage

## Constraints
$ 2 \leq N, Q \leq 10^6$

$ 0 \leq X < N$

$ 0 < A \leq 200$

$ 0 \leq stock\ price\ value \leq 10^5 $

## Output Format

Print a single integer in a new line for every query, the minimum number of days Novruz should hold the stock for at least $A\%$ profit.

Print $-1$ for queries in which it is not possible to take the intended profit

### Sample Input 1
```
10 7
127 107 101 121 112 105 111 101 122 120
5 3
9 2
6 5
7 3
5 4
9 4
1 4
```

### Sample Output 1
```
1
-1
2
1
1
-1
2
```