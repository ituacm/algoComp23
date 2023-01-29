# Area 44

Raider is a company that attaches great importance to privacy and has many offices in different locations of Area 44. Because Raider values ​​privacy very much, it uses a local telephone network that only employees of its offices can use. However, this situation brings with it an extra maintenance cost to the company. For each network cable, maintenance cost is directly proportional to the length of the network cable.

One day, the company decides to remove some of the cables that are not exactly crucial for the network in order to reduce maintenance costs and buys a routing system. According to this system, there is no need to have a direct connection for communication between two offices, meaning, an arbitrary office A can use other offices to communicate with an another office B that is not directly connected to A. After this routing system is established, it is promised to have obtained a minimum maintenance cost for that network. It is absolutely known that there is no other minimum cost network other than the one this system provides. Note that communications can be made bilaterally.

After a while, Raider realizes that their priorities have changed from minimum maintenance cost to minimum latency. Raider's network consists of cables that have proportional latency with respect to the cable length. Hacer, CEO of Raider, searchs for superb network cables and realizes that there is another company with brand new technology of network cables. What makes them so special is that they have constant latency time. But these cables are very expensive so Raider can by only one cable. Hacer needs to make a clever choice to reduce overall latency which is summation of latency between all different office pairs. And remember, latency is proportional to the cable length.

Ceren, CEO of the network cable company, offers some fixed latency cables to Hacer. For every offer, Raider is expected to select one cable in its network to replace with the offered latency cost to minimize the total sum. Can you help Hacer to find the minimum overall latency of her network for each offer from Ceren?

## Input Format

The first line consists of two integers $n$ and $m$ where $n$ is the number of Raider's offices and $m$ is the total number of network cables among them.

The following $m$ lines consist of three integers $o_i$, $o_j$ and $l$ where $l$ is the length and latency of the cable between offices $o_i$ and $o_j$.

Next line consists of one integer $q$ which is the number of offers from Ceren.

Following $q$ lines include one integer $fl$ denoting the fixed latency cost of new technology network cables.

## Constraints

- $1 \leq n \leq 10^{4}$
- $1 \leq m \leq 2\times10^{5}$
- $0 \leq o_i, o_j \lt n$
- $o_i \neq o_j$
- $1 \leq l, fl \leq 10^{4}$
- $1 \leq q \leq 10^{4}$

## Output Format

For every offer from Ceren, print one line with one integer denoting the network's minimum overall latency obtained by replacing one network cable with the new offer.

### Sample Input 0

```
4 4
0 1 5
1 2 12
1 3 8
2 3 9
2
4
7
```

### Sample Output 0

```
58
68
```

### Sample Explanation 0

<img src="https://contest.ituacm.com/static/images/questions/area44-2-graph.png" width="36%"><img src="https://contest.ituacm.com/static/images/questions/area44-2-mst.png" width="36%">

In this given network, overall latency is the sum of the latency between all office pairs which is $74$ (for example, latency between office $0$ and office $2$ is $9 + 8 + 5 = 22$).

If we replaced the cable with length $4$ with an offer of $8$, overall latency would be $58$.

If we replaced the cable with length $7$ with an offer of $9$, overall latency would be $68$.