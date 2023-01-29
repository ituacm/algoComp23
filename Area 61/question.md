# Area 61

Pepperson is a company that attaches great importance to privacy and has many offices in different locations of Area 61. Because Pepperson values ​​privacy very much, it uses a local telephone network that only employees of its offices can use. However, high network traffic wears out the cables and this situation brings with it an extra maintenance cost to the company. For each network cable, maintenance cost is equal to the length of the network cable.

Because of the turbulent economy of Area 61, Pepperson feels the need to cut down on some expenses and invests in a routing system. According to this system, there is no need to have a direct connection for communication between two offices, meaning, an arbitrary office A can use other offices to communicate with an another office B that is not directly connected to A. After this routing system is established, it is promised to have obtained the optimal maintenance cost for that network. It is absolutely known that there is no other minimum cost network other than the one this system provides. Note that communications can be made bilaterally.

After a while, it gets even harder to compensate these expenses; so Hacer, CEO of Pepperson, starts looking for more solutions and realizes that there is a company producing hi-tech network cables. What makes these cables so special is that they have constant maintenance costs. Now, wanting to reduce its expenses even more, Pepperson decides to renew their cables with these new technology network cables.

Ceren, CEO of the network cable company, offers some fixed cost cables to Hacer. For every offer, Pepperson can select as many of its current cables as it wants to replace in order to get the minimum maintenance cost. Can you help Hacer to make the smartest decision?

## Input Format

The first line consists of two integers ~n~ and ~m~ where ~n~ is the number of Pepperson offices and ~m~ is total number of network cables among them.

The following ~m~ lines consist of three integers ~o_i~, ~o_j~ and ~c~ where ~c~ is the maintenance cost between offices ~o_i~ and ~o_j~.

Next line consists of one integer ~q~ which is the number of offers from Ceren.

Following ~q~ lines include one integer ~fc~ denoting the fixed maintenance cost of new technology network cables.

## Constraints

- ~1 \leq n \leq 10^{5}~
- ~1 \leq m \leq 2\times10^{5}~
- ~0 \leq o_i, o_j \lt n~
- ~o_i \neq o_j~
- ~1 \leq c, fc \leq 10^{4}~
- ~1 \leq q \leq 10^{5}~

## Output Format

For each offer from Ceren, print one line with one integer denoting the minimum maintenance cost obtained by renewing as many network cables as needed.

### Sample Input 0

```
6 8
0 2 3
0 4 5
0 5 6
1 4 2
1 5 7
2 3 1
2 4 5
4 5 2
3
2
3
4
```

### Sample Output 0

```
9
11
12
```